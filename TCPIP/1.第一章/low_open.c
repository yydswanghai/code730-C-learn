// 创建新文件并保存数据
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "../common/index.h"

int main(int argc, char const *argv[])
{
  int fd;
  char buf[] = "Let's go!\n";
  // fd: 文件[描述符/句柄]
  // 文件打开模式O_CREAT、O_WRONLY、O_TRUNC的组合，因此将创建空文件，并只能写。若存在data.txt文件，则清空文件的全部数据
  fd = open("data.txt", O_CREAT|O_WRONLY|O_TRUNC);
  if(fd == -1){
    error_handling("open() error!");
  }
  printf("file descriptor: %d \n", fd);

  if(write(fd, buf, sizeof(buf)) == -1 ){
    error_handling("write() error!");
  }
  close(fd);
  return 0;
}
/**
 * gcc low_open.c ../common/index.c -o open
 * ./open
*/
