/*
author: Yuan Zhen
2020/07/03
*/
package tcp;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

import static tcp.MyServer.BYE;
import static tcp.MyServer.MY_COMM_CHARSET;

public class MyChat {
    private Socket s;
    private String from;
    private String greeting;

    public MyChat(Socket s, String from, String greeting) {
        this.s = s;
        this.from = from;
        this.greeting = greeting;
    }

    public void chatting() {
        Scanner in = new Scanner(System.in);
        try(
                BufferedReader br = new BufferedReader(
                        new InputStreamReader(s.getInputStream(),MY_COMM_CHARSET)
                );
                PrintWriter pw = new PrintWriter(
                        new OutputStreamWriter(s.getOutputStream(),MY_COMM_CHARSET)
                );
        ) {
            if(greeting != null) {
                pw.println(greeting);
                pw.flush();
            }
            while(true){
                String line = br.readLine();
                if(line.equalsIgnoreCase(BYE)){
                    pw.println(BYE);
                    break;
                }else{
                    System.out.println(from+"："+line);
                    String myword = in.nextLine();
                    pw.println(myword);
                    pw.flush();
                }
            }
        } catch (IOException e) {
            //TODO: handle exception
            e.printStackTrace();
        }
    }
}
