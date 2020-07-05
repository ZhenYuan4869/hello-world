/*
* @author Zhen.Yuan (2020-07-04)
*/
package tcp;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

import tcp.MsgField;
import tcp.MsgPiece;
import tcp.MsgField.FillSide;

public class MyServer {
    public static void main(String[] args){

        try {
            System.out.println("Socket服务器开始运行...");
            ServerSocket serverSocket = new ServerSocket(9999);
            while (true){
                Socket socket = serverSocket.accept();
                new Thread(new Server_listen(socket)).start();
                new Thread(new Server_send(socket)).start();
            }
        }catch (Exception e){
            e.printStackTrace();
        }

    }
}

//接收信息方法
class Server_listen implements Runnable{
    private Socket socket;

    Server_listen(Socket socket){
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
            while (true)
                System.out.println(ois.readObject());
        }catch (Exception e){
            e.printStackTrace();
        }finally {
            try{
                socket.close();
            }catch (Exception e){
                e.printStackTrace();
            }
        }
    }
}

//发送信息方法
class Server_send implements Runnable{
    private Socket socket;

    Server_send(Socket socket){
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
            Scanner scanner = new Scanner(System.in);
            while (true){
                System.out.print("请输入要发送的内容：");
                String string = scanner.nextLine();
                //报文组装和封装组包
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
        }
    }
}