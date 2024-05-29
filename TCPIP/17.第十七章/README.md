## 问题

## epoll

```c
#include <sys/epoll.h>

/**
 * 创建保存epoll文件描述符的空间
 * @param size epoll 实例的大小
 * @return 成功时返回 epoll 文件描述符，失败时返回-1
 */
int epoll_create(int size);

/**
 * 向空间注册并注销文件描述符
 * @param epfd 用于注册监视对象的 epoll例程的文件描述符
 * @param op 用于指定监视对象的添加、删除或更改等操作
 *  - EPOLL_CTL_ADD: 将文件描述符注册到epoll例程
 *  - EPOLL_CTL_DEL: 从epoll例程中删除文件描述符
 *  - EPOLL_CTL_MOD: 更改注册的文件描述符的关注事件发生情况
 * @param fd 需要注册的监视对象文件描述符
 * @param event 监视对象的事件类型
 *  - EPOLLIN: 需要读取数据的情况
 *  - EPOLLOUT: 输出缓冲为空，可以立即发送数据的情况
 *  - EPOLLPRI: 收到OOB数据的情况
 *  - EPOLLRDHUP: 断开连接或半关闭的情况，这在边缘触发方式下非常有用
 *  - EPOLLERR: 发生错误的情况
 *  - EPOLLET: 以边缘触发的方式得到事件通知
 *  - EPOLLONESHOT: 发生一次事件后，相应文件描述符不再收到事件通知。因此需要向epoll_ctl函数的第二个参数传递EPOLL_CTL_MOD，再次设置事件
 * @return 成功时返回0，失败时返回-1
 * @example epoll_ctl(A, EPOLL_CTL_ADD, B, C); epoll例程A中注册文件描述符B，主要目的是监视参数C中的事件
 * @example epoll_ctl(A, EPOLL_CTL_DEL, B, NULL); epoll例程A中删除文件描述符B
 */
int epoll_ctl(int epfd, int op, int fd, struct epoll_event * event);

/**
 * 与select函数类似，等待文件描述符发生变化
 * @param epfd 表示事件发生监视范围的epoll例程的文件描述符
 * @param events 保存发生事件的文件描述符集合的结构体地址值
 * @param maxevents 第二个参数中可以保存的最大事件数
 * @param timeout 以1/1000秒为单位的等待时间，传递-1时，一直等待直到发生事件
 * @return 成功时返回发生事件的文件描述符数，失败时返回-1
 */
int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);
```