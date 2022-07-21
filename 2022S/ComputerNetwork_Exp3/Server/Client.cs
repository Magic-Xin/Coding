using System.Net.Sockets;
using Data;
using Message = Data.Message;

namespace Server;

public class Client
{
    public string Name;
    
    private readonly Socket _clientSocket;
    private readonly ServerForm _serverForm;

    private bool _receiveThreadFlag;
    public Client(Socket clientSocket, ServerForm serverForm)
    {
        Name = "";
        _clientSocket = clientSocket;
        _serverForm = serverForm;
        _receiveThreadFlag = true;
        
        var receiveThread = new Thread(Receive);
        receiveThread.Start();
    }

    private void Receive()
    {
        try
        {
            while (_receiveThreadFlag)
            {
                var buffer = new byte[1024];
                _clientSocket.Receive(buffer);
                var data = (Message)Binary.Deserialize(buffer);

                switch (data.Type)
                {
                    case Types.Connect:
                        if (_serverForm.ClientUsers.Exists(name => name == data.Name))
                        {
                            Send(new Message{Type = Types.Fail});
                            break;
                        }
                        
                        Send(new Message{Type = Types.Success});
                        Name = data.Name;
                        _serverForm.Msg(data, Color.Blue);
                        _serverForm.ClientUsers.Add(data.Name);
                        _serverForm.Data.Add(new Message
                        {
                            Users = _serverForm.ClientUsers,
                            Type = Types.UpdateUsers
                        });
                        break;
                    case Types.Disconnect:
                        _serverForm.Msg(data, Color.Blue);
                        _serverForm.ClientUsers.Remove(data.Name);
                        Disconnect();
                        break;
                    default:
                         _serverForm.Msg(data, Color.Blue);
                         _serverForm.Data.Add(data);
                        break;
                }
            }

            lock (_clientSocket)
            {
                _clientSocket.Shutdown(SocketShutdown.Both);
                _clientSocket.Close();
            }
        }
        catch (SocketException)
        {
            _serverForm.Msg(Name + " Error! Disconnect!", Color.Red);
            Disconnect();
            throw;
        }
    }

    public void Send(Message data)
    {
        try
        {
            lock (_clientSocket)
            {
                var buffer = Binary.Serialize(data);
                _clientSocket.Send(buffer);
            }
        }
        catch (SocketException)
        {
            _serverForm.Msg(Name + " Error! Disconnect!", Color.Red);
            Disconnect();
            throw;
        }
    }

    private void Disconnect()
    {
        _receiveThreadFlag = false;

        _serverForm.ClientDisconnect(this);
        _serverForm.Data.Add(new Message
        {
            Users = _serverForm.ClientUsers,
            Type = Types.UpdateUsers
        });
    }

    public void Close()
    {
        _receiveThreadFlag = false;
    }
}