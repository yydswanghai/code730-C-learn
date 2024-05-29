#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char const *argv[])
{
  int sock;
  struct sockaddr_in serv_addr;
  char message[30];
  int str_len;
  
  if (argc != 3) {
    printf("Usage : %s <IP> <port> ", argv[0]);
    exit(1);
  }

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    error_handling("socket() error");
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
    error_handling("connect() error");
  }

  str_len = read(sock, message, sizeof(message)-1);
  if (str_len == -1) {
    error_handling("read() error");
  }

  printf("message from server : %s \n", message);
  close(sock);
  return 0;
}

/**
 * 该函数在检测到错误时，向用户展示一个错误消息，并随后终止程序执行
 * - stderr 是 C 语言标准库中定义的一个文件流，通常用于输出错误或诊断信息
 * - fputc 是一个用于写入单个字符到文件流的函数，这里它写入了一个换行符 '\n'
 */
void error_handling(char *message) {
  fputs(message, stderr);// 将字符串(message)写入到标准错误流(stderr)，直到遇到字符串结束符 '\0'
  fputc('\n', stderr);// 这行代码向 stderr 输出一个换行符
  exit(1);// 终止程序，状态码1
}