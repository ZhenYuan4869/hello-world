package tcp;

import tcp.MsgField;
import tcp.MsgPiece;
import tcp.MsgField.FillSide;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class TestHead extends MsgPiece implements Serializable {

    private int textLength;

    public int getTextLength() {
        return textLength;
    }

    public void setTextLength(int text_Length) {
        textLength = text_Length;
    }

    private static final MsgField[] items = new MsgField[]{
            new MsgField("text_Length", 10, '0', FillSide.LEFT),
    };

    public TestHead() {
        super(items);
    }

    private void writeObject(ObjectOutputStream oos) throws IOException {
        //System.out.println("Serializable writeObject");
        oos.writeObject(textLength);
    }

    private void readObject(ObjectInputStream ois) throws IOException, ClassNotFoundException {
        //System.out.println("Serializable readObject");
        textLength = (int) ois.readObject();
    }
}
