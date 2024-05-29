#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
// 生存时间 Time to Live
#define TTL 64
#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char const *argv[])
{
  int send_sock;
  struct sockaddr_in mul_adr;
  int time_live = TTL;
  FILE *fp;// 文件指针
  char buf[BUF_SIZE];
  if (argc != 3) {
    printf("Usage : %s <GroupIP> <PORT>\n", argv[0]);
    exit(1);
  }

  send_sock = socket(PF_INET, SOCK_DGRAM, 0);// 创建UDP套接字
  memset(&mul_adr, 0, sizeof(mul_adr));
  mul_adr.sin_family = AF_INET;
  mul_adr.sin_addr.s_addr = inet_addr(argv[1]);
  mul_adr.sin_port = htons(atoi(argv[2]));
  // 指定TTL信息
  setsockopt(send_sock, IPPROTO_IP, IP_MULTICAST_TTL, (void*)&time_live, sizeof(time_live));
  if ((fp = fopen("news.txt", "r")) == NULL) {
    error_handling("fopen() error");
  }
  while (!feof(fp)) {// feof检查文件指针fp是否指向文件的末尾，在末尾返回1，不在末尾返回0
    fgets(buf, BUF_SIZE, fp);// 从打开的文件中读取 BUF_SIZE-1 个字符到 buf
    // 发送数据
    sendto(send_sock, buf, strlen(buf), 0, (struct sockaddr*)&mul_adr, sizeof(mul_adr));
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