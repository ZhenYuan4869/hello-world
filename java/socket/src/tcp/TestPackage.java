package tcp;

import tcp.MsgPackage;

public class TestPackage extends MsgPackage {

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

}
