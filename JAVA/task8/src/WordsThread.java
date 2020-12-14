import java.util.Random;

public class WordsThread implements Runnable {
    String[] words = { "Per aspera, ad astra.", "El Psy Kongroo.", "闷声发大财", "Too young, too simple.", "NAÏVE" };
    Random df = new Random();
    Object obj;

    WordsThread(Object obj) {
        this.obj = obj;
    }

    public void run() {
        while (true) {
            synchronized (obj) {
                while (!MTFrame.isRun) {
                    try {
                        obj.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                int num = df.nextInt(5);
                MTFrame.words.setText(words[num]);
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
