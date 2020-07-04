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

//socket服务器类
public class MyServer {

    public static final int SERVER_PORT = 9999;
    public static final Charset MY_COMM_CHARSET = StandardCharsets.utf_8;
    public static final String BYE = "bye";


    public static void main(String[] args){
        commWithClient();
    }

    private static void commWithClient() {
        try(
            ServerSocket ss = new ServerSocket(SERVER_PORT);
            Socket s = ss.accept(); //客户端连接，不连接一直停在这里
            BufferedReader br = new BufferedReader(
                    new InputStreamReader(s.getInputStream(),MY_COMM_CHARSET)
            );
            PrintWriter pw = new PrintWriter(
                    new OutputStreamWriter(s.getOutputStream(),MY_COMM_CHARSET)
            );
        ) {
            pw.println("已经与客户端建立连接。");
            pw.flush();
            while(true){
                String line = br.readLine();
            }
        } catch (IOException e) {
            //TODO: handle exception
            e.printStackTrace();
        }
    }
}
