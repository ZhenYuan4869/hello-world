/*
author: Yuan Zhen
2020/07/03
*/
package tcp;

import java.io.IOException;
import java.net.Socket;
import java.rmi.UnknownHostException;

import static tcp.MyServer.SERVER_PORT;

public class MyClient {
    public static void main(String[] args){
        commWithServer();
    }

    private static void commWithServer() {
        try (
            //127.0.0.1
            Socket s = new Socket("localhost",SERVER_PORT);
        ) {
            // System.out.println("客户端连接到："+s.getRemoteSocketAddress());
            MyChat myChat = new MyChat(s, "服务器端", null);
            myChat.chatting();
        } catch (UnknownHostException e) {
            //TODO: handle exception
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
    }
}