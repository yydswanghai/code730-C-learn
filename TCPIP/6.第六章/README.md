## 问题

1. UDP为什么TCP速度快？为什么TCP数据传输可靠而UDP数据传输不可靠？
  * 111页
2. 下列不属于UDP特点的是？（b）
  * a.UDP不同于TCP，不存在连接的概念，所以不像TCP那样只能进行一对一的数据传输
  * b.利用UDP传输数据时，如果有2个目标，则需要2个套接字
  * c.UDP套接字中无法使用已分配给TCP的同一端口号
  * d.UDP套接字和TCP套接字可以共存。若需要，可以在同一主机进行TCP和UDP数据传输
  * e.针对UDP函数也可以调用connect函数，此时UDP套接字跟TCP套接字相同，也需要经过3次握手过程
3. UDP数据报向对方主机的UDP套接字传递过程中，IP和UDP分别负责哪些部分？
  * 112页
4. UDP一般比TCP快，但根据交换数据的特点，其差异可大可小。请说明何种情况下UDP的性能优于TCP？
  * 113页
5. 客户端TCP套接字调用connect函数时自动分配IP和端口号。UDP中不调用bind函数，那何时分配IP和端口号？
  * 118页
6. TCP客户端必需调用connect函数，而UDP中可以选择性调用。请问，在UDP中调用connect函数有哪些好处？
  * 122页
7. 请参考本章给出的uecho_server.c和uecho_client.c，编写示例使服务器端和客户端轮流收发消息。收发的消息均要输出的控制台窗口。

## UDP 111页

```c
#include <sys/socket.h>
/**
 * 传输数据
 * @param sock 用于传输数据的UDP套接字文件描述符
 * @param buff 保存待传输数据的缓冲地址值
 * @param nbytes 待传输的数据长度，以字节为单位
 * @param flags 可选项参数，若没有则传递0
 * @param to   存有目标地址信息的sockaddr结构体变量的地址值
 * @param addrlen 传递给参数to的地址值结构体变量长度
 * @return 成功时返回传输的字节数，失败时返回-1
 */
ssize_t sendto(int sock, void * buff, size_t nbytes, int flags, struct sockaddr *to, socklen_t addrlen);
```

```c
#include <sys/socket.h>
/**
 * 接收数据
 * @param sock 用于接收数据的UDP套接字文件描述符
 * @param buff 保存接收数据的缓冲地址值
 * @param nbytes 可接收的最大字节数，无法超过参数buff所指的缓冲大小
 * @param flags 可选项参数，若没有则传递0
 * @param from   存有发送端地址信息的sockaddr结构体变量的地址值
 * @param addrlen 保存参数from的结构体变量长度的变量地址值
 * @return 成功时返回接收的字节数，失败时返回-1
 */
ssize_t recvform(int sock, void * buff, size_t nbytes, int flags, struct sockaddr *from, socklen_t *addrlen);
```