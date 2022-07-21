namespace Data;

public class Log
{
    private readonly string _file;

    public Log()
    {
        var filename = "log-" + DateTime.Now.ToString("yyyyMMdd") + ".log";
        
        _file = Path.Combine(Directory.GetCurrentDirectory(), filename);
        if (!File.Exists(_file))
        {
            File.Create(_file);
        }
    }
    
    public void Write(string text)
    {
        File.AppendAllText(_file, text);
    }
}