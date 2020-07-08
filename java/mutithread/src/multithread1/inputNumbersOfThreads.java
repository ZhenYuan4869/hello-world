/*
 * @author Zhen.Yuan
 * @date 2020-07-09
 */
//方法一采用普通的建立线程然后重写runnable的方法输出，同时用递归方法控制输出
package multithread1;

import java.util.Scanner;

public class inputNumbersOfThreads{
    public static void main(String[] args){
        System.out.println("这是第一种方法。");
        System.out.println("请输入需要建立的线程数：");
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        new Thread(new myThread(number)).start(); //以i为编号创建线程并且开始运行
            //start()方法开启一个线程，此时并没有运行，一旦得到CPU时间片，就自动开始执行run()方法。
        System.out.println("等待程序运行中...");
    }
}

class myThread extends Thread implements Runnable {
    private int number;   //线程编号

    myThread(int i) {
        this.number = i;
    }

    @Override
    public void run() {
        if(this.number>1){
            myThread t = new myThread(number-1);
            try {
                t.start();//递归方法
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        if (this.number % 3 == 0) {
            System.out.println("当前线程号为：" + this.number + "，输出为：" + (this.number % 3 + 3) + "。");
        } else {
            System.out.println("当前线程号为：" + this.number + "，输出为：" + (this.number % 3) + "。");
        }
    }

}


