#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
  int status;
  pid_t pid = fork();// 创建子进程1

  if (pid == 0) {
    return 3;// 该子进程1通过main函数的return语句终止
  } else {
    printf("child PID: %d \n", pid);
    pid = fork();// 创建子进程2
    if (pid == 0) {
      exit(7);// 该子进程2通过exit函数终止
    } else {
      printf("child PID: %d \n", pid);
      wait(&status);
      if (WIFEXITED(status)) {
        printf("child send1 :%d\n", WEXITSTATUS(status));
      }
      wait(&status);
      if (WIFEXITED(status)) {
        printf("child send2 :%d\n", WEXITSTATUS(status));
      }
      sleep(30);
    }
  }

  return 0;
}
/**
 * 注意：调用wait函数时，如果没有已终止的子进程，那么程序将阻塞（Blocking）直到有子进程终止，因此需要谨慎调用该函数
 * 推荐使用 waitpid 函数
*/