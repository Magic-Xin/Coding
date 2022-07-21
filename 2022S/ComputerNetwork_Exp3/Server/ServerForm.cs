using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;
using Data;
using Message = Data.Message;
using Log = Data.Log;

namespace Server;

public partial class ServerForm : Form
{
    private Socket? _serverSocket;
    private Thread? _mainThread;
    private Thread? _handleThread;
    private string _ipAddress;
    private int _port;

    private bool _mainThreadFlag;
    private bool _handleThreadFlag;

    private readonly List<Client> _clients;
    
    public readonly List<string> ClientUsers;
    public readonly List<Message> Data;

    private readonly Log _log;

    public ServerForm()
    {
        InitializeComponent();
        GetHostIp();

        _ipAddress = "";
        _port = 0;
        
        _mainThreadFlag = true;
        _handleThreadFlag = true;

        _clients = new List<Client>();
        Data = new List<Message>();
        ClientUsers = new List<string>();
        
        _log = new Log();
    }

    public void Msg(string msg, Color color)
    {
        serverTextBox.Invoke(new EventHandler(delegate
        {
            serverTextBox.SelectionStart = serverTextBox.TextLength;
            serverTextBox.SelectionColor = color;
            serverTextBox.AppendText(DateTime.Now + " " + msg + "\r\n");
            serverTextBox.ScrollToCaret();
        }));
        _log.Write( DateTime.Now + " " + msg + "\r\n");
    }

    public void Msg(Message msg, Color color)
    {
        serverTextBox.Invoke(new EventHandler(delegate
        {
            serverTextBox.SelectionStart = serverTextBox.TextLength;
            serverTextBox.SelectionColor = color;
            serverTextBox.AppendText(msg.Time + " ");
            
            switch (msg.Type)
            {
                case Types.Public:
                    serverTextBox.AppendText("(Public) " + msg.Name + " : " + msg.Content + "\r\n");
                    break;
                case Types.Private:
                    serverTextBox.AppendText("(Private) " + msg.Name + " To " + msg.ReceiveName + " : " + msg.Content + "\r\n");
                    break;
                case Types.Connect:
                    serverTextBox.AppendText(msg.Name + " Connected\r\n");
                    break;
                case Types.Disconnect:
                    serverTextBox.AppendText(msg.Name + " Disconnected\r\n");
                    break;
            }
            
            serverTextBox.ScrollToCaret();
        }));
        _log.Write(msg.Time + " " + msg.Name + "," + msg.ReceiveName + msg.ReceiveName==string.Empty?"":"," + msg.Type + "," + msg.Content + "\r\n");
    }

    public void ClientDisconnect(Client client)
    {
        _clients.Remove(client);
    }

    private void GetHostIp()
    {
        var host = Dns.GetHostEntry(Dns.GetHostName());
        foreach (var ip in host.AddressList)
        {
            if (ip.AddressFamily != AddressFamily.InterNetwork || ip.ToString().Contains("192.168")) continue;
            _ipAddress = ip.ToString();
            ip_label.Text = _ipAddress;
        }
    }

    private bool PortIsUsed()
    {
        var ipProperties = IPGlobalProperties.GetIPGlobalProperties();
        var ipEndPoints = ipProperties.GetActiveTcpListeners();

        return ipEndPoints.Any(endPoint => endPoint.Port == _port);
    }

    private void portBox_KeyPress(object sender, KeyPressEventArgs e)
    {
        if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8)
            e.Handled = true;
    }

    private void start_button_Click(object sender, EventArgs e)
    {
        _port = int.Parse(portBox.Text);
        if (_port is < 1 or > 65535)
        {
            Msg("Port error", Color.Red);
            return;
        }

        if (PortIsUsed())
        {
            Msg("Port is used", Color.Red);
            return;
        }

        try
        {
            _serverSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            _serverSocket.Bind(new IPEndPoint(IPAddress.Any, _port));
            _serverSocket.Listen(10);
            _mainThreadFlag = true;
            _handleThreadFlag = true;
            StartThread();
        }
        catch (Exception ex)
        {
            stop_button_Click(null, EventArgs.Empty);
            Msg(ex.Message, Color.Red);
            throw;
        }

        stop_button.Enabled = true;
        start_button.Enabled = false;
        portBox.Enabled = false;
    }

    private void StartThread()
    {
        _mainThread = new Thread(Accept) {IsBackground = true};
        _mainThread.Start();

        _handleThread = new Thread(HandleData) {IsBackground = true};
        _handleThread.Start();
    }

    private void Accept()
    {
        while (_mainThreadFlag && _serverSocket != null)
        {
            var clientSocket = _serverSocket.Accept();
            Msg(DateTime.Now + " Client " + clientSocket.RemoteEndPoint + " connected", Color.Green);
            var client = new Client(clientSocket, this);

            _clients.Add(client);

            client.Send(new Message
            {
                IpSend = _ipAddress,
                Content = "Connected successfully",
                Time = DateTime.Now,
                Type = Types.Connect
            });
        }
    }

    private void HandleData()
    {
        while (_handleThreadFlag)
        {
            if (Data.Count > 0)
            {
                var data = Data.First();
                Data.RemoveAt(0);
                switch (data.Type)
                {
                    case Types.UpdateUsers:
                        foreach (var client in _clients)
                        {
                            client.Send(data);
                        }

                        break;
                    case Types.Public:
                        foreach (var client in _clients)
                        {
                            client.Send(data);
                        }

                        break;
                    case Types.Private:
                        var clients = _clients.FindAll(c => c.Name == data.Name || c.Name == data.ReceiveName);
                        foreach (var client in clients)
                        {
                            client.Send(data);
                        }

                        break;
                }
            }
        }
    }

    private void stop_button_Click(object? sender, EventArgs e)
    {
        _mainThreadFlag = false;
        _handleThreadFlag = false;
        
        CloseMainThread();

        foreach (var client in _clients)
        {
            var data = new Message
            {
                IpSend = _ipAddress,
                Content = "Server is closing...",
                Time = DateTime.Now,
                Type = Types.Disconnect
            };
            client.Send(data);
            client.Close();
        }

        if (_serverSocket is {Connected: true})
            _serverSocket.Shutdown(SocketShutdown.Both);
        _serverSocket?.Close();

        _clients.Clear();
        Data.Clear();
        ClientUsers.Clear();

        stop_button.Enabled = false;
        start_button.Enabled = true;
        portBox.Enabled = true;
    }

    private void CloseMainThread()
    {
        var ipAddress = IPAddress.Parse("127.0.0.1");
        var ipEndPoint = new IPEndPoint(ipAddress, _port);
        var clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        try
        {
            clientSocket.Connect(ipEndPoint);
        }
        catch (Exception ex)
        {
            Msg(ex.Message, Color.Red);
        }
    }

    private void clear_button_Click(object sender, EventArgs e)
    {
        serverTextBox.Clear();
    }

    private void ServerForm_FormClosed(object sender, FormClosedEventArgs e)
    {
        stop_button_Click(sender, e);
    }
}