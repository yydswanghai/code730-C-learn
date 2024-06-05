#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
  int fd1, fd2, fd3;
  fd1 = socket(PF_INET, SOCK_STREAM, 0);// 创建套接字
  fd2 = open("test.dat", O_CREAT|O_WRONLY|O_TRUNC);// 创建文件
  fd3 = socket(PF_INET, SOCK_DGRAM, 0);// 创建套接字

  // 为什么是从3开始的顺序编号，因为0、1、2是分配给标准I/O的描述符
  printf("file descriptor(文件描述符)1: %d\n", fd1);
  printf("file descriptor(文件描述符)2: %d\n", fd2);
  printf("file descriptor(文件描述符)3: %d\n", fd3);

  close(fd1);
  close(fd2);
  close(fd3);
  return 0;
}
/**
 * gcc fd_seri.c -o fd_seri
 * ./fd_seri
*/