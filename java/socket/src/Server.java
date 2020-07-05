import org.json.simple.JSONObject;

import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Server {
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
                JSONObject object = new JSONObject();
                if(string.length()<=10) {
                    int count = 10-string.length();
                    for(int i=0;i<count;i++)
                    {
                        string = string+" ";
                    }
                }
                else{
                    string = string.substring(0,10);
                }
                object.put("msg", string);
                object.put("length",10);
                oos.writeObject(object);
                oos.flush();
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}