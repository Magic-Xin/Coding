namespace Data;

public enum Types
{
    Public,
    Private,
    Connect,
    Disconnect,
    UpdateUsers,
    Success,
    Fail
}

[Serializable]
public class Message
{
    public string IpSend { get; set; } = string.Empty;
    public string Name { get; set; } = string.Empty;
    public string ReceiveName { get; set; } = string.Empty;
    public string Content { get; set; } = string.Empty;
    public DateTime Time { get; set; }
    public List<string> Users { get; set; } = new();
    public Types Type { get; set; }
}