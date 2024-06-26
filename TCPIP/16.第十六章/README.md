## 问题

1. 下列关于FILE结构体指针和文件描述符的说法错误的是？（a,d,e）
  * a.与FILE结构体指针相同，文件描述符也分为输入描述符和输出描述符
    * 文件描述符不区分输入输出
  * b.复制文件描述符时将生成相同值的描述符，可以通过这2个描述符进行I/O
  * c.可以利用创建套接字时返回的文件描述符进行I/O，也可以不通过文件描述符，直接通过FILE结构体指针完成
  * d.可以从文件描述符生成FILE结构体指针，而且可以利用这种FILE结构体指针进行套接字I/O
    * FILE指针是用于标准C库文件I/O函数的，而不是用于套接字I/O的。套接字I/O有它自己的系统调用集，通常不使用FILE结构体指针
  * e.若文件描述符为读模式，则基于该描述符生成的FILE结构体指针同样是读模式；若文件描述符为写模式，则基于该描述符生成的FILE结构体指针同样是写模式
    * 文件描述符本身并不具有读或写模式；它们只是用于引用打开的文件或资源
2. EOF的发送相关描述中错误的是？（a,b,c）
  * a.终止文件描述符时发送EOF
    * EOF（End Of File）通常是在读取操作到达文件末尾时由读取函数返回的，而不是在终止文件描述符时发送的。EOF是数据流结束的信号，与文件描述符的终止不是直接相关的
  * b.即使未完全终止文件描述符，关闭输出流时也会发送EOF
    * 关闭输出流（例如，使用close函数关闭一个文件描述符）并不会直接发送EOF。EOF是读取操作的结果，而不是写入或关闭操作的结果。关闭输出流可能会导致后续的写入操作失败，但这与EOF的发送无关
  * c.如果复制文件描述符，则包括复制的文件描述符在内，所有描述符都终止时才会发送EOF
    * 复制文件描述符（使用如dup或dup2的系统调用）并不会导致EOF的发送。每个描述符都是独立的，它们各自可以有自己的读取和写入位置，并且一个描述符的关闭不会影响其他描述符。EOF的发送与文件描述符的复制或终止没有直接关系
  * d.即使复制文件描述符，也可以通过调用shutdown函数进入半关闭状态并发送EOF

## 分离I/O

```c
#include <unistd.h>

// 复制文件描述符
int dup(int fildes);
/**
 * 指定复制文件描述符
 * @param fildes 需要复制的文件描述符
 * @param fildes2 明确指定的文件描述符整数值
 * @return 成功时返回复制的文件描述符，失败时返回-1
 */
int dup2(int fildes, int fildes2);
```

274