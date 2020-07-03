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
class Server_listen implements Runnable {
    private Socket socket;
    @Override
    public void run() {
        // TODO Auto-generated method stub

    }

    
}


//发送数据给客户的类