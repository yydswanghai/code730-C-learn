#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 4096

void error_handling(char *message);

int main(int argc, char const *argv[])
{
  if(argc != 3) {
    printf("Usage:%s <source(克隆的源文件)> <destination(生成的目标文件)>\n", argv[0]);
    exit(1);
  }

  int source_fd = open(argv[1], O_RDONLY);
  if(source_fd == -1) {
    error_handling("source open() error!");
  }

  int dest_fd = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644);// 添加文件权限
  if(dest_fd == -1){
    error_handling("dest open() error!");
  }
  char buf[BUF_SIZE];
  ssize_t bytes_read;
  printf("buf size %lu\n", sizeof(buf));

  while ( (bytes_read = read(source_fd, buf, sizeof(buf))) > 0 ) {
    ssize_t bytes_written = write(dest_fd, buf, bytes_read);
    if(bytes_written != bytes_read){
      close(source_fd);
      close(dest_fd);
      error_handling("write() error!");
    }
  }

  if (bytes_read == -1) {
    error_handling("read() error!");
  }
  close(source_fd);
  close(dest_fd);

  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}