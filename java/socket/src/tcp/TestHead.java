package tcp;

import tcp.MsgField;
import tcp.MsgPiece;
import tcp.MsgField.FillSide;

public class TestHead extends MsgPiece {

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
}
