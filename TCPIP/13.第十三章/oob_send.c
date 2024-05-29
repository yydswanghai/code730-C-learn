#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char const *argv[])
{
  int sock;
  struct sockaddr_in recv_adr;
  if (argc != 3) {
    printf("Usage : %s <IP> <port>\n", argv[0]);
    exit(1);
  }

  sock = socket(PF_INET, SOCK_STREAM, 0);
  memset(&recv_adr, 0, sizeof(recv_adr));
  recv_adr.sin_family = AF_INET;
  recv_adr.sin_addr.s_addr = inet_addr(argv[1]);
  recv_adr.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr*)&recv_adr, sizeof(recv_adr)) == -1) {
    error_handling("connect() error");
  }
  // 正常顺序：12 -> 36 -> 45 -> 89  strlen("12") = 2
  write(sock, "12", strlen("12"));
  send(sock, "36", strlen("36"), MSG_OOB);// 紧急传输数据
  write(sock, "45", strlen("45"));
  send(sock, "89", strlen("89"), MSG_OOB);// 紧急传输数据
  close(sock);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}

// oob_msg: 6
// oob_msg: 9
// 123
// 458