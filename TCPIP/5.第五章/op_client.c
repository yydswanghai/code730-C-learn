#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
#define RET_SIZE 4
#define OPSZ 4
void error_handling(char * message);

int main(int argc, char const *argv[])
{
  int sock;
  char opmsg[BUF_SIZE];
  int result, opnd_cnt, i;
  struct sockaddr_in serv_adr;
  if (argc != 3) {
    printf("Usage : %s <IP> <port>\n", argv[0]);
    exit(1);
  }

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    error_handling("socket() error");
  }
  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_adr.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1 ) {
    error_handling("connect() error");
  } else {
    puts("Connected..........");
  }
  fputs("Operand count: ", stdout);// stdout：常量，表示标准输出流的指针，代表标准输出设备，通常指屏幕或控制台
  scanf("%d", &opnd_cnt);
  opmsg[0] = (char)opnd_cnt;// 将用户输入的数字个数转为char类型 3 => '3'，并存入数组[0]中，1字节

  for (i = 0; i < opnd_cnt; i++)
  {
    printf("Operand %d: ", i+1);
    // 从用户的输入中得到待算整数，保存到opmsg数组。4字节的int型数据要保存到char数组，因而转换成int指针类型
    scanf("%d", (int*)&opmsg[i*OPSZ+1]);
  }
  fgetc(stdin);// 下下行需要输入字符，在此之前调用fgetc函数删掉缓冲中的字符
  fputs("Operator: ", stdout);
  scanf("%c", &opmsg[opnd_cnt*OPSZ+1]);// 输入运算信息，保存到opmsg数组
  write(sock, opmsg, opnd_cnt*OPSZ+2);
  read(sock, &result, RET_SIZE);
  
  printf("Operation result: %d \n", result);
  close(sock);
  return 0;
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
 * 
 * 客户端向服务器端传输的数据结构示例：
 * i*4+1
 * [3] [ ] [2] [5] [ ] [ ] [1] [7] [ ] [ ] [3] [2] [ ] [+]
 * 操作数个数:3                                          运算符:+
 * [2] [ ] [4] [5] [ ] [ ] [5] [7] [ ] [-]
 * 操作数个数:2                          运算符:-
*/