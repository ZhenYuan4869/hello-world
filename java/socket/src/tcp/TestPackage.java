package tcp;

import tcp.MsgPackage;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class TestPackage extends MsgPackage implements Serializable{

    public TestPackage() {
        super("t1", "t2");
    }

    private TestHead t1;

    private TestBody t2;

    public TestHead getT1() {
        return t1;
    }

    public void setT1(TestHead t1) {
        this.t1 = t1;
    }

    public TestBody getT2() {
        return t2;
    }

    public void setT2(TestBody t2) {
        this.t2 = t2;
    }

    private void writeObject(ObjectOutputStream oos) throws IOException {
        //System.out.println("Serializable writeObject");
        oos.writeObject(t1);
        oos.writeObject(t2);
    }

    private void readObject(ObjectInputStream ois) throws IOException, ClassNotFoundException {
        //System.out.println("Serializable readObject");
        t1 = (TestHead) ois.readObject();
        t2 = (TestBody) ois.readObject();
    }
}
