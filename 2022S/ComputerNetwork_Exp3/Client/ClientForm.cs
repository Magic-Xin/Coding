using System.Net;
using System.Net.Sockets;
using Data;
using Message = Data.Message;
using Log = Data.Log;

namespace Client;

public partial class ClientForm : Form
{
    private Thread? _receiveThread;
    private Socket? _clientSocket;

    private bool _receiveThreadFlag;
    private string _nickname;

    private readonly Log _log;

    public ClientForm()
    {
        InitializeComponent();

        _receiveThreadFlag = true;
        _nickname = "";
        
        listBox.SelectedIndex = 0;
        
        _log = new Log();
    }

    private void Msg(string msg, Color color)
    {
        clientTextBox.Invoke(new EventHandler(delegate
        {
            clientTextBox.SelectionStart = clientTextBox.TextLength;
            clientTextBox.SelectionColor = color;
            clientTextBox.AppendText(DateTime.Now + " " + msg + "\r\n");
            clientTextBox.ScrollToCaret();
        }));
        _log.Write( DateTime.Now + " " + msg + "\r\n");
    }

    private void Msg(Message msg, Color color)
    {
        clientTextBox.Invoke(new EventHandler(delegate
        {
            clientTextBox.SelectionStart = clientTextBox.TextLength;
            clientTextBox.SelectionColor = color;
            clientTextBox.AppendText(msg.Time + " ");
            
            switch (msg.Type)
            {
                case Types.Public:
                    clientTextBox.AppendText("(Public) " + msg.Name + " : ");
                    break;
                case Types.Private:
                    clientTextBox.AppendText("(Private) " + msg.Name + " To " + msg.ReceiveName + " : ");
                    break;
            }

            clientTextBox.AppendText(msg.Content + "\r\n");
            clientTextBox.ScrollToCaret();
        }));
        _log.Write(msg.Time + " " + msg.Name + "," + msg.ReceiveName + msg.ReceiveName==string.Empty?"":"," + msg.Type + "," + msg.Content + "\r\n");
    }

    private void portBox_KeyPress(object sender, KeyPressEventArgs e)
    {
        if ((e.KeyChar < 48 || e.KeyChar > 57) && e.KeyChar != 8)
            e.Handled = true;
    }

    private async void start_button_Click(object sender, EventArgs e)
    {
        var port = int.Parse(portBox.Text);
        if (port is < 1 or > 65535)
        {
            Msg("Port must be between 1 and 65535", Color.Red);
            return;
        }

        try
        {
            var ip = IPAddress.Parse(ipBox.Text);
            _clientSocket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
            await _clientSocket.ConnectAsync(new IPEndPoint(ip, port));

            if (FirstConnect() == Types.Connect)
            {
                Msg("Connecting to server...", Color.Green);
                nameBox.Enabled = false;
                _nickname = nameBox.Text;
                Send(new Message
                {
                    IpSend = ip.ToString(),
                    Name = _nickname,
                    Time = DateTime.Now,
                    Type = Types.Connect
                });
                if (FirstConnect() == Types.Success)
                {
                    _receiveThreadFlag = true;
                    StartThread();

                    Msg("Connected", Color.Green);

                    ipBox.Enabled = false;
                    portBox.Enabled = false;
                    start_button.Enabled = false;
                    send_button.Enabled = true;
                    listBox.Enabled = true;
                    stop_button.Enabled = true;
                }
                else
                {
                    Msg("Nickname has been used!", Color.Red);
                    Send(new Message {Type = Types.Disconnect});
                    nameBox.Enabled = true;
                }
            }
            else
            {
                Msg("Connection failed!", Color.Red);
            }
        }
        catch (Exception)
        {
            Msg("Connect Error!", Color.Red);
            throw;
        }
    }

    private Types FirstConnect()
    {
        var buffer = new byte[1024];
        _clientSocket?.Receive(buffer);
        var data = (Message) Binary.Deserialize(buffer);

        return data.Type;
    }

    private void StartThread()
    {
        _receiveThread = new Thread(Receive){IsBackground = true};
        _receiveThread.Start();
    }

    private void Receive()
    {
        while (_receiveThreadFlag)
        {
            try
            {
                var buffer = new byte[1024];
                _clientSocket?.Receive(buffer);
                var data = (Message) Binary.Deserialize(buffer);

                switch (data.Type)
                {
                    case Types.Disconnect:
                        Send(new Message{Type = Types.Disconnect});
                        Msg(data.Content, Color.Red);
                        Stop();
                        break;
                    case Types.UpdateUsers:
                        listBox.Invoke(new EventHandler(delegate
                        {
                            listBox.Items.Clear();
                            listBox.Items.Add("ALL");
                            foreach (var user in data.Users)
                            {
                                listBox.Items.Add(user);
                            }
                        }));
                        listBox.SelectedIndex = 0;
                        break;
                    case Types.Public:
                        Msg(data, Color.Black);
                        break;
                    case Types.Private:
                        Msg(data, Color.Blue);
                        break;
                }
            }
            catch (Exception)
            {
                Msg("Disconnect", Color.Red);
                Stop();
                break;
            }
        }
    }

    private void Send(Message msg)
    {
        try
        {
            if (_clientSocket == null) return;
            lock (_clientSocket)
            {
                var buffer = Binary.Serialize(msg);
                _clientSocket.Send(buffer);
            }
        }
        catch (Exception)
        {
            Stop();
            throw;
        }
    }

    private void Stop()
    {
        _receiveThreadFlag = false;

        ipBox.Enabled = true;
        portBox.Enabled = true;
        start_button.Enabled = true;
        nameBox.Enabled = true;
        send_button.Enabled = false;
        listBox.Enabled = false;
        stop_button.Enabled = false;
    }

    private void stop_button_Click(object? sender, EventArgs e)
    {
        Send(new Message {Name = _nickname, Time = DateTime.Now, Type = Types.Disconnect});
        Stop();
    }

    private void send_button_Click(object? sender, EventArgs e)
    {
        if (msgBox.Text == "")
        {
            return;
        }

        var msg = msgBox.Text;
        if (listBox.SelectedIndex == 0 || listBox.SelectedItem == null)
        {
            Send(new Message
            {
                Name = _nickname,
                Time = DateTime.Now,
                Content = msg,
                Type = Types.Public,
            });
        }
        else
        {
            Send(new Message
            {
                Name = _nickname,
                ReceiveName = listBox.SelectedItem.ToString() ?? string.Empty,
                Time = DateTime.Now,
                Content = msg,
                Type = Types.Private,
            });
        }

        msgBox.Text = "";
    }

    private void ClientForm_FormClosed(object sender, FormClosedEventArgs e)
    {
        if (_clientSocket != null && (!_receiveThreadFlag || !_clientSocket.Connected)) return;
        Send(new Message {Name = _nickname, Time = DateTime.Now, Type = Types.Disconnect});
        _receiveThreadFlag = false;
    }

    private void msgBox_KeyPress(object sender, KeyPressEventArgs e)
    {
        if(e.KeyChar is (char) Keys.Enter or (char) Keys.Return)
        {
            send_button_Click(sender, e);
        }
    }
}