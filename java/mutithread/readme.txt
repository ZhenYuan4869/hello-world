两种方法实现多线程的输出。

第一种方法：普通的重写runnable方法，然后使用循环，每个循环start开启新线程，等到CPU有时间片的时候自动调用run产生输出。同时用递归方法来控制输出顺序。

第二种方法：使用sleep来控制一个线程完全运行之后再开启下一个，可以达到按顺序开启线程的目的，但是因为手动设置延迟所以运行时间较长