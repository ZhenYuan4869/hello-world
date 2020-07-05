/*
*@author Zhen.Yuan (2020-07-04)
*/
package tcp;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;


public class MyClient {
    private static Socket socket;
    public static boolean connection_state = false;

    public static void main(String[] args){
        while (!connection_state) {     //如果先启动客户端则尝试重新连接
            connect();
            try {
                Thread.sleep(3000);
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }

    private static void connect(){
        try {
            socket = new Socket("127.0.0.1", 9999);
            connection_state = true;
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
            new Thread(new Client_listen(socket,ois)).start();
            new Thread(new Client_send(socket,oos)).start();
            new Thread(new Client_heart(socket,oos)).start();
        }catch (Exception e){
            e.printStackTrace();
            connection_state = false;
        }
    }

    public static void reconnect(){
        while (!connection_state){
            System.out.println("正在尝试重新链接.....");
            connect();
            try {
                Thread.sleep(3000);
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }
}

class Client_listen implements Runnable{
    private Socket socket;
    private ObjectInputStream ois;

    Client_listen(Socket socket,ObjectInputStream ois){
        this.socket = socket;
        this.ois = ois;
    }

    @Override
    public void run() {
        try {
            while (true){
                System.out.println(ois.readObject());
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}

class Client_send implements Runnable{
    private Socket socket;
    private ObjectOutputStream oos;

    Client_send(Socket socket, ObjectOutputStream oos){
        this.socket = socket;
        this.oos = oos;
    }

    @Override
    public void run() {
        try {
            Scanner scanner = new Scanner(System.in);
            while (true){
                System.out.print("请输入你要发送的信息：");
                String string = scanner.nextLine();
                //定长报文组装和封装组包
                TestHead head = new TestHead();
                head.setTextLength(string.length());
                TestBody body = new TestBody();
                body.setContent(string);

                TestPackage packagee= new TestPackage();
                packagee.setT1(head);
                packagee.setT2(body);

                oos.writeObject(packagee);
                oos.flush();
            }
        }catch (Exception e){
            e.printStackTrace();
            try {
                socket.close();
                MyClient.connection_state = false;
                MyClient.reconnect();
            }catch (Exception ee){
                ee.printStackTrace();
            }
        }
    }
}

//维持长连接需要客户端不定时发送心跳包
class Client_heart implements Runnable{
    private Socket socket;
    private ObjectOutputStream oos;

    Client_heart(Socket socket, ObjectOutputStream oos){
        this.socket = socket;
        this.oos = oos;
    }

    @Override
    public void run() {
        try {
            System.out.println("心跳包线程已启动...");
            while (true){
                Thread.sleep(5000);
                //心跳包也是定长报文形式
                TestHead head = new TestHead();
                TestBody body = new TestBody();
                head.setTextLength(3);
                body.setContent("心跳包");
                TestPackage packagee= new TestPackage();
                packagee.setT1(head);
                packagee.setT2(body);
                oos.writeObject(packagee);
                oos.flush();
            }
        }catch (Exception e){
            e.printStackTrace();
            try {
                socket.close();
                MyClient.connection_state = false;
                MyClient.reconnect();
            }catch (Exception ee){
                ee.printStackTrace();
            }
        }
    }
}