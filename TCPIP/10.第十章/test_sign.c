#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义全局变量，用于判断是否接收到Ctrl+C信号
volatile sig_atomic_t sigint_received = 0;
bool terminate_program = false;

void keycontrol(int sig) {// 信号处理器
  if (sig == SIGINT) {// SIGINT 输入CTRL+C
    sigint_received = 1;
  }
}

int main(int argc, char const *argv[])
{
  int i;
  struct sigaction act;
  act.sa_handler = keycontrol;
  sigemptyset(&act.sa_mask);// 调用 sigemptyset 将 sa_mask 成员的所有位初始化为0
  act.sa_flags = 0;// sa_flags 初始化为0
  sigaction(SIGINT, &act, 0);// 注册 SIGINT 信号和相应处理器

  while (!terminate_program)
  {
    printf("Hello, world!\n");
    sleep(3);
    
    if (sigint_received) {
      char input;
      printf("是否确定退出程序，输入Y则终止程序？(Y/N): ");
      scanf(" %c", &input);
      
      // 如果用户输入Y，则退出程序
      if (input == 'Y' || input == 'y') {
          printf("Exiting program...\n");
          terminate_program = true;
      } else {
          // 清除接收到Ctrl+C信号的标志
          sigint_received = 0;
      }
    }
  }
  return 0;
}
