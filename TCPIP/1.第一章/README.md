## 问题

1. 套接字在网络编程中的作用是什么？为何称它为套接字？
  * 网络编程是什么？
  * 套接字是什么？
  * 12页
2. 在服务器端创建套接字后，会依次调用listen函数和accept函数。请比较并说明二者作用。
  * 14页
3. Linux中，对套接字数据进行I/O时可以直接使用文件I/O相关函数；而在Windows中则不可以。原因为何？
  * 19页
4. 创建套接字后一般会给它分配地址，为什么？为了完成地址分配需要调用哪个函数？
  * 13页
5. Linux中的文件描述符与Windows的句柄实际上非常类似。请以套接字为对象说明它们的含义。
  * Linux中的文件描述符：19页
  * Windows中的句柄：30页
6. 底层文件I/O函数与ANSI标准定义的文件I/O函数之间有何区别
  * 19页
  * 底层文件 I/O 函数提供了更底层、更灵活的文件操作接口，但通常具有较差的移植性和较复杂的错误处理机制；
  * 而 ANSI 标准定义的文件 I/O 函数则提供了更标准化、更简单的接口，具有较好的移植性和较简单的错误处理机制。
7. 参考本书给出的示例low_open.c和low_read.c，分别利用底层文件I/O和ANSI标准I/O编写文件复制程序。可任意指定复制程序的使用方法。

```c
/**
 * 套接字的创建 (安装电话机)
 * @param domain 套接字中使用的协议族信息
 * @param type   套接字数据传输类型信息
 * @param protocol 计算机间通信中使用的协议信息
 * @return 成功返回文件描述符，失败返回-1
 */
int socket(int domain, int type, int protocal);

/**
 * 分配IP地址和端口号 (分配电话号码)
 * @param sockfd 要分配地址信息（IP地址和端口号）的套接字文件描述符
 * @param myaddr 存有地址信息的结构体变量的地址
 * @param addrlen 第二个结构体变量的长度
 * @return 成功返回0，失败返回-1
 */
int bind(int sockfd, struct sockaddr *myaddr, socklen_t addrlen);

/**
 * 转为可接收请求状态 (连接电话线)
 * @param sockfd 希望进入等待连接请求状态的套接字文件描述符，传递的描述符套接字参数成为服务器端套接字（监听套接字）
 * @param backlog 连接请求等待队列的长度，若为5，则队列长度为5，表示最多使5个连接请求进入队列
 * @return 成功返回0，失败返回-1
 */
int listen(int sockfd, int backlog);

/**
 * 受理连接请求 (拿起话筒)
 * @param sockfd 服务器端套接字的文件描述符
 * @param addr 保存发起连接请求的客户端地址信息的变量地址值，调用函数后向传递来的地址变量参数填充客户端地址信息
 * @param addrlen 第二个参数addr结构体的长度，但是存有长度的变量地址。函数调用完成后，该变量即被填入客户端地址长度
 * @return 成功返回文件描述符，失败返回-1
 */
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

/**
 * 发送连接请求
 * @param sockfd 客户端套接字的文件描述符
 * @param serv_addr 保存目标服务器端地址信息的变量地址值
 * @param addrlen 以字节为单位传递已传递给第二个结构体参数servaddr的地址变量长度
 * @return 成功返回0，失败返回-1
 */
int connect(int sockfd, struct sockaddr *serv_addr, socklen_t addrlen);
```

* 注意：创建套接字，但此时套接字并不马上分为服务器和客户端。
  * 如果紧接着调用bind、listen函数，将成为服务端套接字
  * 如果紧接着调用connect函数，将成为客户端套接字

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * 打开文件
 * @param path 文件名的字符串地址
 * @param flag 文件打开模式信息
 * @return 成功返回文件描述符，失败返回-1
 */
int open(const char* path, int flag);
```

下表是此函数第二个参数flag可能的常量值及含义。如需传递多个参数，则应通过位或运算(OR)符组合并传递

| 打开模式  | 含义           |
| -------- | ------------- |
| O_CREAT  | 必要时创建文件   |
| O_TRUNC  | 删除全部现有数据 |
| O_APPEND | 维持现有数据，保存到其后面 |
| O_RDONLY | 只读打开        |
| O_WRONLY | 只写打开        |
| O_RDWR   | 读写打开        |

```c
#include <unistd.h>
/**
 * 关闭文件：使用文件后必须关闭文件
 * @param fd 需要关闭的文件或套接字的文件描述符
 * @return 成功返回0，失败返回-1
 */
int close(int fd);
```

```c
#include <unistd.h>
/**
 * 将数据写入文件，write函数用于向文件输入（传输）数据。Linux中不区分文件与套接字，因此，通过套接字向其他计算机传递数据时也会用到该函数。
 * @param fd 显示数据传输对象的文件描述符
 * @param buf 保存要传输数据的缓冲地址值
 * @param nbytes 要传输数据的字节数
 * @return 成功返回写入的字节数，失败返回-1
 */
ssize_t write(int fd, const void* buf, size_t nbytes);
```

注意：此函数定义中，size_t是通过typedef声明的unsigned int类型，对ssize_t来说，size_t前面多的s代表signed，即ssize_t是通过typedef声明的signed int类。

```c
#include <unistd.h>
/**
 * 读取文件中的数据
 * @param fd 显示数据接收对象的文件描述符
 * @param buf 要保存接收数据的缓冲地址值
 * @param nbytes 要接收数据的最大字节数
 * @return 成功返回接收的字节数（但遇到文件结尾则返回0），失败返回-1
 */
ssize_t read(int fd, void* buf, size_t nbytes);
```

## Linux 平台下运行

```shell
gcc hello_server.c -o hserver
```

编译hello_server.c文件并生成可执行文件hserver。

-o 是用来指定可执行文件名的可选参数

因此编译后将可执行文件hserver，可如下执行此命令

```shell
./hserver
```

运行示例：

```shell
gcc hello_server.c -o hserver
./hserver 9190
```

正常情况下程序将停留在此状态，因为服务器端调用的accept函数还未返回。接下来运行客户端

```shell
gcc hello_client.c -o hclient
./hclient 127.0.0.1 9190
```

正常你会看到服务器端返回的`hello world!`，由此查看客户端消息传输过程，同时发现，完成消息传输后，服务器端和客户端都停止运行了。
执行过程中输入端`127.0.0.1`是运行示例用的计算机（本机）的IP地址。如果在同一台计算机中同时运行服务器端和客户端，将采用这种连接方式。但如果服务器端与客户端不在同一台计算机中运行，则应采用服务器端所在计算机的IP地址。

运行low_open示例

```shell
gcc low_open.c -o lopen
./lopen

file descriptor: 

cat data.txt
```

运行low_read示例

```shell
gcc low_read.c -o lread
./lread

file descriptor: 
```

运行fd_seri示例

```shell
gcc fd_seri.c -o fds
./fds
```