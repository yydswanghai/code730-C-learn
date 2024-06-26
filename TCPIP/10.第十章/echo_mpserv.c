#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_childproc(int sig);

int main(int argc, char const *argv[])
{
  int serv_sock, clnt_sock;
  struct sockaddr_in serv_adr, clnt_adr;

  pid_t pid;
  struct sigaction act;
  socklen_t adr_sz;
  int str_len, state;
  char buf[BUF_SIZE];
  if (argc != 2) {
    printf("Usage : %s <port>\n", argv[0]);
    exit(1);
  }

  act.sa_handler = read_childproc;// 处理僵尸进程-start
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  state = sigaction(SIGCHLD, &act, 0);// 处理僵尸进程-end
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
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
  while (1) {
    adr_sz = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);// 父子进程都有该套接字
    if (clnt_sock == -1) {
      continue;
    } else {
      puts("new client connected...");
    }
    pid = fork();// 创建子进程
    if (pid == -1) {
      close(clnt_sock);
      continue;
    } 
    if (pid == 0) {// 子进程区域
      close(serv_sock);// 关闭33行创建的服务器套接字，因为服务器端套接字文件描述符同样也传递到子进程
      while ((str_len = read(clnt_sock, buf, BUF_SIZE)) != 0) {
          write(clnt_sock, buf, str_len);
      }
      close(clnt_sock);
      puts("client disconnected...");
      return 0;
    } else {
      close(clnt_sock);// 47行创建的套接字文件描述符已复制给子进程，因此服务器端需要销毁自己拥有的文件描述符
    }
  }
  close(serv_sock);
  return 0;
}

void read_childproc(int sig) {
  pid_t pid;
  int status;
  pid = waitpid(-1, &status, WNOHANG);
  printf("removed proc id:%d \n", pid);
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}
/**
 * 通过 fork 函数复制文件描述符 187页
 * 关闭无关套接字的原因 59、70行 188页
*/