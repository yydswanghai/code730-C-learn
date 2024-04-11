#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 30

int main(int argc, char const *argv[])
{
  int fds[2];// 0出口 1入口
  char str[] = "Who are you?";
  char buf[BUF_SIZE];
  pid_t pid;

  pipe(fds);// 创建管道，fds数组中保存用于I/O的文件描述符
  pid = fork();// 复制，父/子进程将同时拥有上面的I/O文件描述符
  if (pid == 0) {// 子进程传递数据
    write(fds[1], str, sizeof(str));
  } else {// 父进程接收数据
    read(fds[0], buf, BUF_SIZE);
    puts(buf);
  }
  return 0;
}