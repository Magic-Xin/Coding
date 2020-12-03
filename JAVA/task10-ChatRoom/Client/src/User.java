import java.io.Serializable;

public class User implements Serializable {
    String id;
    String content;
    int status;

    User(String id){
        this.id = id;
    }
}