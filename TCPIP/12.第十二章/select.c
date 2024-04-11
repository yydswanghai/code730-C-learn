#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#define BUF_SIZE 30

int main(int argc, char const *argv[])
{
  fd_set reads, temps;
  int result, str_len;
  char buf[BUF_SIZE];
  struct timeval timeout;// 超时返回0
  
  FD_ZERO(&reads);  // 初始化fd_set
  FD_SET(0, &reads);// 监听标准输入的变化

  while (1)
  {
    temps = reads;// 需要对比调用select前后fd_set的变化
    timeout.tv_sec = 5;// 每一次调用select前都要初始化timeval
    timeout.tv_usec = 0;
    result = select(1, &temps, 0, 0, &timeout);
    if (result == -1) {
      puts("select() error!");
      break;
    } else if (result == 0) {
      puts("Time-out");
    } else {
      // 检查文件描述符集合 temps 中是否包含文件描述符 0（标准输入）
      if (FD_ISSET(0, &temps)) {// 验证select调用的结果
        str_len = read(0, buf, BUF_SIZE);
        buf[str_len] = 0;
        printf("message from console: %s", buf);
      }
    }
  }
  return 0;
}