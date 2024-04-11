#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char * message);

int main(int argc, char const *argv[])
{
  int serv_sock, clnt_sock;// 文件描述符
  char message[BUF_SIZE];
  int str_len, i;
  
  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t clnt_adr_sz;// clnt_adr 的字节长度
  
  if (argc != 2) {
    printf("Usage : %s <port>\n", argv[0]);
    exit(1);
  }

  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  if (serv_sock == -1) {
    error_handling("socket() error");
  }

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1) {
    error_handling("bind() error");
  }
  if (listen(serv_sock, 5) == -1) {
    error_handling("listen() error");
  }
  clnt_adr_sz = sizeof(clnt_adr);
  
  for (i = 0; i < 5; i++) {// 为处理5个客户端连接而添加的循环，共调用5次accept函数，一次向5个客户端提供服务
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
    if (clnt_sock == -1) {
      error_handling("accept() error");
    } else {
      printf("Connected client %d \n", i+1);
    }
    while ((str_len = read(clnt_sock, message, BUF_SIZE)) != 0 ) {
      write(clnt_sock, message, str_len);// 完成回声服务的代码，原封不动传输读取的字符串
    }
    close(clnt_sock);
  }
  close(serv_sock);

  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}

/**
 * 迭代回声服务器端
 * 服务器端在同一时刻只与一个客户端相连，并提供回声服务
 * 服务器端依次向5个客户端提供服务并退出
 * 客户端接收用户输入端字符串并发送到服务器端
 * 服务器端将接收端字符串数据传回客户端，即“回声”
 * 服务器端与客户端之间的字符串回声一直执行到客户端输入Q为止
*/