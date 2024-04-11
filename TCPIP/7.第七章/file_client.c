#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char const *argv[])
{
  int sock;
  FILE * fp;

  char buf[BUF_SIZE];
  int read_cnt;
  struct sockaddr_in serv_adr;
  if (argc != 3) {
    printf("Usage : %s <IP> <port>\n", argv[0]);
    exit(1);
  }

  fp = fopen("receive.dat", "wb");// 创建新文件以保存服务器端传输到文件数据
  sock = socket(PF_INET, SOCK_STREAM, 0);

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_adr.sin_port = htons(atoi(argv[2]));

  connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
  while ( (read_cnt = read(sock, buf, BUF_SIZE)) != 0 ) {
    fwrite((void*)buf, 1, read_cnt, fp);// 接收数据并保存到24创建的文件，直到接收EOF为止
  }
  puts("Received file data");
  write(sock, "Thank you", 10);// 向服务器端发送表示感谢的消息，若服务器端未关闭输入流，则可接收此消息
  fclose(fp);
  close(sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}