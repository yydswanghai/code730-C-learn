#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void timeout(int sig) {// 信号处理器
  if (sig == SIGALRM) {// SIGALRM 已到通过调用alarm函数注册时间
    puts("Time out!");
  }
  alarm(2);// 每间隔2秒重复产生 SIGALRM 信号，信号处理器中调用alarm
}

int main(int argc, char const *argv[])
{
  int i;
  struct sigaction act;
  act.sa_handler = timeout;
  sigemptyset(&act.sa_mask);// 调用 sigemptyset 将 sa_mask 成员的所有位初始化为0
  act.sa_flags = 0;// sa_flags 初始化为0

  sigaction(SIGALRM, &act, 0);// 注册 SIGALRM 信号和相应处理器
  alarm(2);// 2秒后发生 SIGALRM 信号
  
  for (i = 0; i < 3; i++)
  {
    puts("wait...");
    sleep(100);
  }
  return 0;
}
