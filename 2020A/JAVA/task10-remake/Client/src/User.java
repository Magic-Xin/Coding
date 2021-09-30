import java.io.Serializable;

public class User implements Serializable {
    private String id;
    private String to_whom;
    private String content;
    private int status;

    User(String id){
        this.id = id;
    }

    public String getId(){
        return this.id;
    }

    public void setId(String id){
        this.id = id;
    }

    public String getTo_whom(){
        return this.to_whom;
    }

    public void setTo_whom(String to_whom){
        this.to_whom = to_whom;
    }

    public String getContent(){
        return this.content;
    }

    public void setContent(String content){
        this.content = content;
    }

    public int getStatus(){
        return this.status;
    }

    public void setStatus(int status){
        this.status = status;
    }
}
