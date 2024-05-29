## 问题

1. 下列关于MSG_OOB可选项的说法错误的是？（b、c）
  * a. MSG_OOB指传输Out-of-band数据，是通过其他路径高速传输数据
  * b. MSG_OOB指通过其他路径高速传输数据，因此，TCP中设置该选项的数据先到达对方主机
  * c. 设置MSG_OOB使数据先到达对方主机后，以普通数据的形式和顺序读取。也就是说，只是提高了传输速度，接收方无法识别这一点
  * d. MSG_OOB无法脱离TCP的默认数据传输方式。即使设置了MSG_OOB，也会保持原有传输顺序。该选项只用于要求接收方紧急处理
* 答案：
  * a.部分正确，MSG_OOB它不会改变数据的传输路径或速度，而是改变了数据在接收端的处理优先级
  * b.MSG_OOB不表示数据通过其他路径或高速传输。在TCP中，设置MSG_OOB选项的数据不会先到达对方主机。数据的到达顺序仍然按照发送顺序。
  * c.MSG_OOB不会改变数据的到达顺序，也不会提高传输速度。它仅表示发送的数据是紧急的，并要求接收方紧急处理。接收方可以识别这些数据是Out-of-band数据，并据此给予特殊处理。
2. 利用readv & writev函数收发数据有何优点？分别从函数调用次数和I/O缓冲的角度给出说明。
  * 234页
3. 通过recv函数验证输入缓冲是否存在数据时（确认后立即返回时），如何设置recv函数最后一个参数中的可选项？分别说明各可选项的含义
  * 设置 MSG_PEEK
  * 222页
4. 可在Linux平台通过注册事件处理函数接收MSG_OOB数据。那Windows中如何接收？请说明接收方法

## send & recv

```c
#include <sys/socket.h>
/**
 * 发送 221页
 * @param sockfd 表示与数据传输对象的连接的套接字文件描述符
 * @param buf    保持待传输数据的缓冲地址值
 * @param nbytes 待传输的字节数
 * @param flags  传输数据时指定的可选项信息
 * @return 成功时返回发送的字节数，失败时返回-1
 */
ssize_t send(int sockfd, const void * buf, size_t nbytes, int flags);
```

```c
#include <sys/socket.h>
/**
 * 接收 222页
 * @param sockfd 表示与数据接收对象的连接的套接字文件描述符
 * @param buf    保持接收数据的缓冲地址值
 * @param nbytes 可接收的最大字节数
 * @param flags  接收数据时指定的可选项信息
 * @return 成功时返回接收的字节数，失败时返回-1
 */
ssize_t recv(int sockfd, void * buf, size_t nbytes, int flags);
```

send函数和recv函数的最后一个参数收发数据时的可选项 222页

## 紧急模式工作原理 227页

MSG_OOB的真正的意义在于督促数据接收对象尽快处理数据，这是紧急模式的全部内容，而且TCP“保持传输顺序”的传输特性依然成立


```c
#include <sys/uio.h>
/**
 * 整合发送 231页
 * @param filedes 表示数据传输对象的套接字文件描述符。但该函数并不只限于套接字，因此，可以像read函数一样向其传递文件或标准输出描述符
 * @param iov iovec 结构体数组的地址值，结构体 iovec 中包含待发送数据的位置和大小信息
 * @param iovcnt 向第二个参数传递的数组长度
 * @return 成功时返回发送的字节数，失败时返回-1
 */
ssize_t writev(int filedes, const struct iovec * iov, int iovcnt);

struct iovec {
  void * iov_base;// 缓冲地址
  size_t iov_len;// 缓冲大小
}
```

```c
#include <sys/uio.h>
/**
 * 整合接收 233页
 * @param filedes 传递接收数据的文件（或套接字）描述符
 * @param iovec 包含数据保存位置和大小信息的 iovec 结构体数组的地址值
 * @param iovcnt 第二个参数中数组的长度
 * @return 成功时返回接收的字节数，失败时返回-1
 */
ssize_t readv(int filedes, const struct iovec * iov, int iovcnt);
```

