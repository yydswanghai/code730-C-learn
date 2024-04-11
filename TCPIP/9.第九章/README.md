## 问题

1. 下列关于Time-wait状态的说法错误的是？ (A、C) 156页起 
  * c. Time-wait状态只在服务器端的套接字中发生
  * b. 断开连接的四次握手过程中，先传输FIN消息的套接字将进入Time-wait状态
  * c. Time-wait状态与断开连接的过程无关，而与请求连接过程中SYN消息的传输顺序有关
  * d. Time-wait状态通常并非必要，应尽可能通过更改套接字可选项防止其发生

2. TCP_NODELAY可选项与Nagle算法有关，可通过它禁用Nagle算法。请问何时应考虑禁用Nagle算法？
  * 160页

* 套接字多种可选项
  * SOL_SOCKET 套接字相关通用可选项
  * IPPROTO_IP IP协议相关的事项
  * IPPROTO_TCP TCP协议相关的事项
* getsockopt & setsockopt 151页
* SO_SNDBUF & SO_RCVBUF 153页
* SO_REUSEADDR 155页

```c
#include <sys/socket.h>
/**
 * 用于读取套接字可选项
 * @param sock 用于查看选项套接字文件描述符
 * @param level 要查看的可选项的协议层
 * @param optname 要查看的可选项名
 * @param optval 保存查看结果的缓冲地址值
 * @param optlen 向第四个参数optval传递的缓冲大小，调用函数后，该变量中保存通过第四个参数返回的可选项信息的字节数
 * @return 成功返回0，失败返回-1
 */
int getsockopt(int sock, int level, int optname, void *optval, socklen_t *optlen);
/**
 * 更改可选项时调用的函数
 * @param sock 用于更改可选项的套接字文件描述符
 * @param level 要更改的可选项的协议层
 * @param optname 要更改的可选项名
 * @param optval 保存要更改的选项信息的缓冲地址值
 * @param optlen 向第四个参数optval传递的可选项信息的字节数
 * @return 成功返回0，失败返回-1
 */
int setsockopt(int sock, int level, int optname, const void *optval, socklen_t optlen);
```