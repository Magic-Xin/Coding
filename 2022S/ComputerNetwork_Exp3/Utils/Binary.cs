using System.Runtime.Serialization.Formatters.Binary;

namespace Data;

public static class Binary
{
    public static byte[] Serialize(object obj)
    {
        using var ms = new MemoryStream();
        var bf = new BinaryFormatter();
        bf.Serialize(ms, obj);
        return ms.ToArray();
    }
    
    public static object Deserialize(byte[] data)
    {
        using var ms = new MemoryStream(data);
        var bf = new BinaryFormatter();
        return bf.Deserialize(ms);
    }
}