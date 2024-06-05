## 问题

1. 请解释复用技术的通用含义，并说明何为I/O复用
  * 205页
2. 多进程并发服务器的缺点有哪些？如何在I/O复用服务器端中弥补？
  * 204页
3. 复用服务器端需要select函数。下列关于select函数使用方法的描述错误的是？C
  * a.调用select函数前需要集中I/O监视对象的文件描述符
  * b.若已通过select函数注册为监视对象，则后续调用select函数时无需重复注册
  * c.复用服务器端同一时间只能服务于1个客户端，因此，需要服务的客户端接入服务器端后只能等待
  * d.与多进程服务器端不同，基于select的复用服务器端只需要1个进程。因此，可以减少因创建进程产生的服务器端的负担
4. select函数的观察对象中应包含服务器端套接字（监听套接字），那么应将其包含到哪一类监听对象集合？请说明原因
5. select函数中使用的fd_set结构体在Windows和Linux中具有不同声明。请说明区别，同时解释存在区别的必然性

## I/O复用 204页

```c
#include <sys/select.h>
#include <sys/time.h>
/**
 * @param maxfd 监视对象文件描述符数量
 * @param readset 将所有关注“是否存在待读取数据”的文件描述符注册到fd_set型变量，并传递其地址值
 * @param writeset 将所有关注“是否可传输无阻塞数据”的文件描述符注册到fd_set型变量，并传递其地址值
 * @param exceptset 将所有关注”是否发生异常“的文件描述符注册到fd_set型变量，并传递其地址值
 * @param timeout 调用select函数后，为防止陷入无限阻塞的状态，传递超时（time-out）信息
 * @return 发生错误时返回-1，超时返回时返回0。因发生关注的事件返回时，返回大于0的值，该值是发生事件的文件描述符数
 */
int select(int maxfd, fd_set * readset, fd_set * writeset, fd_set * exceptset, const struct timeval * timeout);
```

你要监视3种监视项中的哪些项，就分别声明一个/多个fd_set型的变量，传递地址值到第2至第4个参数