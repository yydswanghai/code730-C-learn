#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char const *argv[])
{
  int serv_sock;
  int clnt_sock;
  
  struct sockaddr_in serv_addr;
  struct sockaddr_in clnt_addr;
  socklen_t clnt_addr_size;

  char message[] = "hello world!";

  if (argc != 2) {
    printf("Usage : %s <port>\n", argv[0]);
    exit(1);
  }
  // 面向连接 IPv4
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (serv_sock == -1) {
    error_handling("socket() error");
  }
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(atoi(argv[1]));

  if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1 ) {
    error_handling("bind() error");
  }

  if (listen(serv_sock, 5) == -1) {
    error_handling("listen() error");
  }

  clnt_addr_size = sizeof(clnt_addr);
  clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
  if (clnt_sock == -1) {
    error_handling("accept() error");
  }
  // 多次调用 write 函数发送数据给客户端
  int str_len = 0;
  int i;
  for ( i = 0; i < 5; i++) {
    if( write(clnt_sock, message, sizeof(message)) == -1 ){
      error_handling("write() error");
    }
    str_len++;
  }
  printf("函数一共写入了%d次 \n", str_len);
  
  close(clnt_sock);
  close(serv_sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
/**
 * gcc tcp_server2.c -o server2
 * ./server2 127.0.0.1 9190
*/