#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
void error_handling(char *message);

int main(int argc, char const *argv[])
{
  int sock;
  int snd_buf, rcv_buf, state;// snd_buf 输出缓冲大小 rcv_buf 输入缓冲大小
  socklen_t len;
  
  sock = socket(PF_INET, SOCK_STREAM, 0);
  len = sizeof(snd_buf);
  state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void*)&snd_buf, &len);
  if (state) {
    error_handling("getsockopt() error");
  }
  len = sizeof(rcv_buf);
  state = getsockopt(sock, SOL_SOCKET, SO_SNDBUF, (void*)&rcv_buf, &len);
  if (state) {
    error_handling("getsockopt() error");
  }

  printf("输入缓冲大小: %d \n", rcv_buf);
  printf("输出缓冲大小: %d \n", snd_buf);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}