#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
  int serv_sock, clnt_sock;
  FILE * read_fp;
  FILE * write_fp;
  
  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t clnt_adr_sz;
  char buf[BUF_SIZE] = {0,};
  
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
  listen(serv_sock, 5);
  clnt_adr_sz = sizeof(clnt_adr);
  clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

  read_fp = fdopen(clnt_sock, "r");// 读
  write_fp = fdopen(dup(clnt_sock), "w");// 复制-写

  fputs("FROM SERVER: Hi~ client? \n", write_fp);// 发送给客户端的数据
  fputs("I love all of the world \n", write_fp);
  fputs("You are awesome! \n", write_fp);
  fflush(write_fp);

  shutdown(fileno(write_fp), SHUT_WR);// 让套接字进入半关闭并同时发送EOF
  // 针对写模式的FILE指针调用fclose函数时，只能销毁与该FILE指针相关的文件描述符吗，无法销毁套接字
  fclose(write_fp);

  fgets(buf, sizeof(buf), read_fp);// 读取客户端最后的消息
  fputs(buf, stdout);
  fclose(read_fp);
  return 0;
}

/**
 * 结果分析：269页
*/
