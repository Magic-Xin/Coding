public class ServerMain {
    public static void main(String[] args) {
        Runnable r = new MainThread();
        Thread t = new Thread(r);
        t.start();
    }
}
