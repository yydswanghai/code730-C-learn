// tcp 验证传输的数据不存在数据边界
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
  int idx = 0, read_len = 0;
  
  if (argc != 3) {
    printf("Usage : %s <IP> <port> ", argv[0]);
    exit(1);
  }

  // 如果前两个参数是 PF_INET, SOCK_STREAM 可以省略第三个参数 IPPROTO_TCP
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

  // 一次读取
  if (read(sock, message, sizeof(message)-1) == -1) {
    error_handling("read() error");
  }

  printf("message from server : %s \n", message);
  close(sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}