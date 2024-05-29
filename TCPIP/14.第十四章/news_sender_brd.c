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
  int send_sock;
  struct sockaddr_in broad_adr;
  FILE *fp;// 文件指针
  char buf[BUF_SIZE];
  int so_brd = 1;
  if (argc != 3) {
    printf("Usage : %s <Boradcast IP> <PORT>\n", argv[0]);
    exit(1);
  }

  send_sock = socket(PF_INET, SOCK_DGRAM, 0);// 创建UDP套接字
  memset(&broad_adr, 0, sizeof(broad_adr));
  broad_adr.sin_family = AF_INET;
  broad_adr.sin_addr.s_addr = inet_addr(argv[1]);
  broad_adr.sin_port = htons(atoi(argv[2]));

  setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST, (void*)&so_brd, sizeof(so_brd));
  if ((fp = fopen("news.txt", "r")) == NULL) {
    error_handling("fopen() error");
  }
  while (!feof(fp)) {// feof检查文件指针fp是否指向文件的末尾，在末尾返回1，不在末尾返回0
    fgets(buf, BUF_SIZE, fp);// 从打开的文件中读取 BUF_SIZE-1 个字符到 buf
    // 发送数据
    sendto(send_sock, buf, strlen(buf), 0, (struct sockaddr*)&broad_adr, sizeof(broad_adr));
    sleep(2);// 为传输数据添加一定的时间间隔
  }
  fclose(fp);
  close(send_sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}