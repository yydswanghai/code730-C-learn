#include <stdio.h>
#include <fcntl.h>
/**
 * 如果文件无法打开可能是权限问题
 * 修改权限：chmod 600 data.dat
 * 查看权限：ls -l data.dat
*/
int main(int argc, char const *argv[])
{
  FILE * fp;
  int fd = open("data.dat", O_WRONLY|O_CREAT|O_TRUNC);
  if (fd == -1) {
    perror("file open error");
    return -1;
  }
  
  printf("First file descriptor: %d \n", fd);
  fp = fdopen(fd, "w");// 文件描述符转换为FILE指针
  fputs("TCP/IP SOCKET PROGRAMMING \n", fp);
  printf("Second file descriptor: %d \n", fileno(fp));// FILE指针转换为文件描述符
  fclose(fp);
  return 0;
}
