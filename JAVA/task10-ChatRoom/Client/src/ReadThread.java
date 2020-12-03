import java.io.ObjectInputStream;

public class ReadThread implements Runnable{
    ObjectInputStream cin;
    boolean isRun = true;

    ReadThread(ObjectInputStream cin){
        this.cin = cin;
    }

    @Override
    public void run() {
        try{
            while(isRun){
                User user = (User)cin.readObject();
                System.out.println(user.content);
            }
            if(cin != null){
                cin.close();
            }
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
