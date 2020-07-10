1.运行Server.java，启动注册中心
2.运行Publisher.java，作为发布者，可以通过update/publish + 空格 + key ( + 空格 + key-value ) 操作符进行更新和发布
3.运行Subscriber1和Subscriber2，可以通过subscribe+空格+key进行服务订阅
4.当Publisher进行update时会通知订阅者key的更新数值