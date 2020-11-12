public class MultiThread {
    public static void main(String[] args) {
        final Object obj = new Object();
        MTFrame mtf = new MTFrame(obj);
        Runnable r1 = new TimeThread();
        Runnable r2 = new WordsThread(obj);
        Thread t1 = new Thread(r1);
        Thread t2 = new Thread(r2);
        t1.start();
        t2.start();
    }
}