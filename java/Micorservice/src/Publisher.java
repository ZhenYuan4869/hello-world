import org.json.simple.JSONObject;

import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Scanner;

public class Publisher {
    private static Socket socket;
    public static boolean connection_state = false;

    public static void main(String[] args){
        while (!connection_state) {
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
            new Thread(new Client_heart(socket,oos)).start();
            new Thread(new Client_send(socket,oos)).start();
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
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
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
                System.out.print("请输入需要做出的操作和对应的key，以空格键隔开：");
                String[] string = scanner.nextLine().split(" ");
                JSONObject object = new JSONObject();

                object.put("operation",string[0]);
                object.put("key",string[1]);
                if(string.length==3) {
                    object.put("key-value", string[2]);
                }
                System.out.println(object);
                oos.writeObject(object);
                oos.flush();
            }
        }catch (Exception e){
            e.printStackTrace();
            try {
                socket.close();
                Publisher.connection_state = false;
                Publisher.reconnect();
            }catch (Exception ee){
                ee.printStackTrace();
            }
        }
    }
}

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
                JSONObject object = new JSONObject();
                object.put("operation","heart");
                object.put("msg","心跳包");
                oos.writeObject(object);
                oos.flush();
            }
        }catch (Exception e){
            e.printStackTrace();
            try {
                socket.close();
                Publisher.connection_state = false;
                Publisher.reconnect();
            }catch (Exception ee){
                ee.printStackTrace();
            }
        }
    }
}
