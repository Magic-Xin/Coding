import java.util.Date;

public class TimeThread implements Runnable {
    public void run() {
        while (true) {
            Date date = new Date();
            MTFrame.time.setText(date.toString());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}