#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
#define OPSZ 4
void error_handling(char * message);
int calculate(int opnum, int opnds[], char oprator);

int main(int argc, char const *argv[])
{
  int serv_sock, clnt_sock;// 文件描述符
  char opinfo[BUF_SIZE];
  int result, opnd_cnt, i;// opnd_cnt 待算个数
  int recv_cnt, recv_len;
  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t clnt_adr_sz;
  
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
  
  for (i = 0; i < 5; i++) {
    opnd_cnt = 0;
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
    read(clnt_sock, &opnd_cnt, 1);// 首先接收待算个数，接收第一个字节

    recv_len = 0;
    while ( (opnd_cnt*OPSZ+1) > recv_len ) {
      recv_cnt = read(clnt_sock, &opinfo[recv_len], BUF_SIZE-1);// opinfo 即是 opinfo[0]
      recv_len+=recv_cnt;
    }
    result = calculate(opnd_cnt, (int*)opinfo, opinfo[recv_len-1]);
    write(clnt_sock, (char*)&result, sizeof(result));
    close(clnt_sock);
  }
  close(serv_sock);
  return 0;
}

int calculate(int opnum, int opnds[], char op) {
  int result = opnds[0], i;
  switch (op) {
    case '+':
      for (i = 1; i < opnum; i++) result += opnds[i];
      break;
    case '-':
      for (i = 1; i < opnum; i++) result -= opnds[i];
      break;
    case '*':
      for (i = 1; i < opnum; i++) result *= opnds[i];
      break;
  }
  return result;
}
void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}

/**
 * 自定义应用层协议
 * 客户端连接到服务器端后以1字节整数形式传递待算数字个数
 * 客户端向服务器端传递的每个整数型数据占用4字节
 * 传递整数型数据后接着传递运算符。运算符信息占用1字节
 * 选择字符+、-、*、之一传递
 * 服务器端以4字节整数型向客户端传回运算结果
 * 客户端得到运算结果后终止与服务器端的连接
*/