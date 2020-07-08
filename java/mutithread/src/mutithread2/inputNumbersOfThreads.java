/*
 * @author Zhen.Yuan
 * @date 2020-07-09
 */
//方法二使用Executor管理线程输出
package mutithread2;

import java.util.Scanner;

public class inputNumbersOfThreads{
    public static void main(String[] args){
        System.out.println("这是第二种方法。");
        System.out.println("请输入需要建立的线程数：");
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        for(int i=0;i<number;i++) {
            new Thread(new myThread(i+1)).start();
            try {
                Thread.sleep(50);
                //使用sleep来控制一个线程完全运行之后再开启下一个，可以达到按顺序开启线程的目的。
                //但是因为手动设置延迟所以运行时间较长
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class myThread extends Thread implements Runnable {
    private int number;   //线程编号

    myThread(int i) {
        this.number = i;
    }

    @Override
    public void run(){
        if (this.number % 3 == 0) {
            System.out.println("当前线程为：" + this.number + "，输出为：" + (this.number % 3 + 3) + "。");
        } else {
            System.out.println("当前线程为：" + this.number + "，输出为：" + (this.number % 3) + "。");
        }
    }
}
