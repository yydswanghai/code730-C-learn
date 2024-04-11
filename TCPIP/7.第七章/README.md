## 问题

1. 解释TCP中“流”的概念。UDP中能否形成流？请说明原因
2. Linux中的close函数或Windows中的closesocket函数属于单方面断开连接的方法，有可能带来一些问题。什么是单方面断开连接？什么情况下会出现问题？
  * 128页
3. 什么是半关闭？针对输出流执行半关闭的主机处于何种状态？半关闭会导致对方主机接收什么消息？
  * 130页

* 半关闭（Half-close）
* 完全断开连接
* 套接字和流 129页

```c
/**
 * @param sock 需要断开的套接字文件描述符
 * @param howto 传递断开方式信息
 *  SHUT_RD：断开输入流 <- 套接字无法再接收数据。即使输入缓冲收到数据也会抹去，而且无法调用输入相关函数
 *  SHUT_WR：断开输出流 -> 无法再传输数据。但如果输出缓冲还留有未传输到数据，则将传递至目标主机
 *  SHUT_RDWR：同时断开I/O流 相当于分两次调用 shutdown(sock, SHUT_RD) shutdown(sock, SHUT_WR)
 * @return 成功返回0，失败返回-1
 */
int shutdown(int sock, int howto);
```


