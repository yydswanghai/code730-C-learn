#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
  int sock;
  char buf[BUF_SIZE];
  struct sockaddr_in serv_addr;
  
  FILE * read_fp;
  FILE * write_fp;
  
  sock = socket(PF_INET, SOCK_STREAM, 0);
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  read_fp = fdopen(sock, "r");
  write_fp = fdopen(sock, "w");

  while (1) {
    if (fgets(buf, sizeof(buf), read_fp) == NULL) {
      break;
    }
    fputs(buf, stdout);
    fflush(stdout);
  }
  fputs("FROM CLIENT: Thank you! \n", write_fp);
  fflush(write_fp);
  fclose(write_fp);
  fclose(read_fp);
  return 0;
}
