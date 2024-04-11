#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  pid_t pid = fork();
  
  if (pid == 0) {
    puts("Hi, I am a child process");
  } else {
    printf("child process ID: %d \n", pid);
    sleep(30);// 父进程暂停30秒，如果父进程终止，处于僵尸状态的子进程将同时销毁。
  }
  if (pid == 0) {
    puts("end child process");
  } else {
    puts("end parent process");
  }
  
  return 0;
}
/**
 * 创建僵尸进程
 * 后台运行 ./zombie &
 * ps ua 
 * 30秒后重复输入查看进程id
*/