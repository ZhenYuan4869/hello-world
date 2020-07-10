import org.json.simple.JSONObject;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;

public class Server {

    public static Map<String, String> valueMap = new HashMap<>();
    public static Map<String, Socket> publisher = new HashMap<>();
    public static Map<String, Set<ObjectOutputStream>> subscriber = new HashMap<>();

    public static void main(String[] args){

        try {
            System.out.println("Socket服务器开始运行...");
            ServerSocket serverSocket = new ServerSocket(9999);
            while (true){
                Socket socket = serverSocket.accept();
                new Thread(new Server_listen(socket,publisher,subscriber,valueMap)).start();
//                new Thread(new Server_send(socket)).start();
            }
        }catch (Exception e){
            e.printStackTrace();
        }

    }
}

class Server_listen implements Runnable{
    private Socket socket;
    private Map<String, Socket> publisher;
    private Map<String, Set<ObjectOutputStream>> subscriber;
    private Map<String, String> valueMap;
    private ObjectOutputStream oos;
    ObjectInputStream ois;

    Server_listen(Socket socket,Map publisher,Map subscriber,Map valueMap) throws IOException {
        this.socket = socket;
        oos = new ObjectOutputStream(socket.getOutputStream());
        ois = new ObjectInputStream(socket.getInputStream());

        this.publisher = publisher;
        this.valueMap = valueMap;
        this.subscriber = subscriber;
    }

    @Override
    public void run() {
        try {
            while (true) {
                JSONObject receive = (JSONObject) ois.readObject();
                System.out.println("receive "+receive);
                if (receive.get("operation").equals(Operation.PUBLISH)) {
                    if (!publisher.containsKey(receive.get("key"))) {
                        publisher.put((String) receive.get("key"), this.socket);
                        JSONObject object = new JSONObject();
                        object.put("message", "成功将当前client设置为publisher。");
                        oos.writeObject(object);
                        oos.flush();
                        valueMap.put((String) receive.get("key"), (String) receive.get("key-value"));
                    } else {
                        JSONObject object = new JSONObject();
                        object.put("message", "该key已有发布者，无法更改。");
                        oos.writeObject(object);
                        oos.flush();
                    }
                } else if (receive.get("operation").equals(Operation.UPDATE)) {
                    if(publisher.get(receive.get("key"))!= null) {
                        if (publisher.get(receive.get("key")).equals(this.socket)) {
                            valueMap.put((String) receive.get("key"), (String) receive.get("key-value"));
                            Set<ObjectOutputStream> sub = subscriber.get(receive.get("key"));
                            if (sub != null) {
                                for (ObjectOutputStream keyOos : sub) {
                                    JSONObject object = new JSONObject();
                                    object.put(receive.get("key"), "更新为" + receive.get("key-value"));
                                    keyOos.writeObject(object);
                                    keyOos.flush();
                                }
                            }

                        } else {
                            System.out.println(publisher.get(receive.get("key")));
                            System.out.println(this.socket);
                            JSONObject object = new JSONObject();
                            object.put("message", "不是对应key的publisher无法更改对应内容。");
                            oos.writeObject(object);
                            oos.flush();
                        }
                    }
                } else if (receive.get("operation").equals(Operation.SUBSCRIBE)) {
                    Set<ObjectOutputStream> keySubscriber = subscriber.getOrDefault(receive.get("key"), new HashSet<>());
                    keySubscriber.add(this.oos);
                    subscriber.put((String) receive.get("key"), keySubscriber);
                    JSONObject object = new JSONObject();
                    object.put("message", "订阅成功！");
                    oos.writeObject(object);
                    oos.flush();
                } else if (receive.get("operation").equals("heart")) {
//                    JSONObject object = new JSONObject();
//                    object.put("message", "心跳包接收成功！");
//                    oos.writeObject(object);
//                    oos.flush();
                } else {
                    JSONObject object = new JSONObject();
                    System.out.println(receive);
                    object.put("message", "operation操作符不合规失败。");
                    oos.writeObject(object);
                    oos.flush();
                }
            }
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

//class Server_send implements Runnable{
//    private Socket socket;
//
//    Server_send(Socket socket){
//        this.socket = socket;
//    }
//
//    @Override
//    public void run() {
//        try {
////            ObjectOutputStream oos = new ObjectOutputStream(socket.getOutputStream());
////            Scanner scanner = new Scanner(System.in);
////            while (true){
////                System.out.print("请输入要发送的内容：");
////                String string = scanner.nextLine();
////                JSONObject object = new JSONObject();
////                if(string.length()<=10) {
////                    int count = 10-string.length();
////                    for(int i=0;i<count;i++)
////                    {
////                        string = string+" ";
////                    }
////                }
////                else{
////                    string = string.substring(0,10);
////                }
////                object.put("msg", string);
////                object.put("length",10);
////                oos.writeObject(object);
////                oos.flush();
////            }
//        }catch (Exception e){
//            e.printStackTrace();
//        }
//    }
//}