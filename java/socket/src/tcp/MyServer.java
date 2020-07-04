/*
author: Yuan Zhen
2020/07/03
*/
package tcp;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

//socket服务器类
public class MyServer {

    public static final int SERVER_PORT = 9999;
    public static final Charset MY_COMM_CHARSET = StandardCharsets.UTF_8;
    public static final String BYE = "bye";


    public static void main(String[] args) throws IOException {
        commWithClient();
    }

    private static void commWithClient() throws IOException {
        System.out.println("服务器端启动，监听端口："+SERVER_PORT);
        try(
            ServerSocket ss = new ServerSocket(SERVER_PORT);
            Socket s = ss.accept(); //客户端连接，不连接一直停在这里
        ) {
            MyChat myChat = new MyChat(s, "客户端", "已连接");
            myChat.chatting();
        }
    }
}
