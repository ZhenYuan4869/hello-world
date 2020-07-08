/*
 * @author Zhen.Yuan
 * @date 2020-07-09
 */
//方法二使用Executor管理线程输出
package mutithread2;

import java.util.Scanner;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class inputNumbersOfThreads {
    public static void main(String[] args) {
        System.out.println("这是第二种方法。");
        System.out.println("请输入需要建立的线程数：");
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        ExecutorService exec = Executors.newCachedThreadPool();
        for(int i=0;i<number;i++){
            exec.execute(new myThread(i+1));
        }
        exec.shutdown();
    }
}

class myThread implements Runnable {
    private int number;   //线程编号

    myThread(int i) {
        this.number = i;
    }

    @Override
    public void run() {
        if (this.number % 3 == 0) {
            System.out.println("当前线程为：" + this.number + "，输出为：" + (this.number % 3 + 3) + "。");
        } else {
            System.out.println("当前线程为：" + this.number + "，输出为：" + (this.number % 3) + "。");
        }
    }
}