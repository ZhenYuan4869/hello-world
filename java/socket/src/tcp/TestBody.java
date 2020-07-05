package tcp;

import tcp.MsgField;
import tcp.MsgPiece;
import tcp.MsgField.FillSide;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class TestBody extends MsgPiece implements Serializable {
    private static final MsgField[] items = new MsgField[]{
            new MsgField("content", 20, ' ',FillSide.RIGHT),
    };

    public TestBody() {
        super(items);
    }

    private String content;

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    private void writeObject(ObjectOutputStream oos) throws IOException {
        //System.out.println("Serializable writeObject");
        oos.writeObject(content);
    }

    private void readObject(ObjectInputStream ois) throws IOException, ClassNotFoundException {
        //System.out.println("Serializable readObject");
        content = (String) ois.readObject();
    }
}
