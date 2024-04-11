#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char const *argv[])
{
  pid_t pid;
  int lval = 20;
  gval++;
  lval+=5;

  pid = fork(); // 创建子进程。父进程的pid中存有子进程的ID，子进程的pid是0
  if (pid == 0) {
    gval += 2;
    lval += 2;
  } else {
    gval -= 2;
    lval -= 2;
  }
  if (pid == 0) {
    printf("Child Process: [%d, %d] \n", gval, lval);// 11+2 25+2
  } else {
    printf("Parent Process: [%d, %d] \n", gval, lval);// 11-2 25-2
  }
  return 0;
}
/**
 * 在调用fork()函数时，会生成一个新的进程，它与调用进程（父进程）相同的程序代码、数据空间和堆栈。
 * 但是，这两个进程会在不同的地址空间中运行，因此它们是完全独立的。
*/