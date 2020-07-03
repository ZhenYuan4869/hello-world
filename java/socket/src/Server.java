/*
author: Yuan Zhen
2020/07/03
*/
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;

//socket服务器类
public class Server {
    public static void main(String[] args){
        try {
            System.out.println("Socket服务器开始运行");
            //java.net.ServerSocket.ServerSocket(int port) throws IOException 表示可能有IO错误所以放进try语句里面
            ServerSocket serverSocket = new ServerSocket(9999); //定义了一个ServerSocket变量，取名为serverSocket
            while (true) {
                Socket socket = serverSocket.accept(); 
                //服务器接收客户请求而产生的socket变量
            }
        } catch (Exception e) {
            //TODO: handle exception
            e.printStackTrace();
        }
        
    }
}

/**
 * 监听客户发来的信息的类，监听类
 * 需要重写run方法
 */

//要用到线程就要用到runnable
class Server_listen implements Runnable {
    private Socket socket;

    Server_listen(Socket socket){ //由外面传进来socket
        this.socket = socket; //将外面传进来的socket赋值进成员变量
    }

    @Override
    public void run() {
        // TODO Auto-generated method stub
        try {
            ObjectInputStream ois = new ObjectInputStream(socket.getInputStream());
            //通过ois不断读取客户传过来的信息
            while (true) {
                System.out.println(ois.readObject());
            }
        } catch (Exception e) {
            //TODO: handle exception
            e.printStackTrace();
        }finally{
            //故障或者bye就断开，不用一直连接socket
            try {
                socket.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}


//
/**
 * 发送数据给客户的类
 */
class Server_send implements Runnable {

    
}