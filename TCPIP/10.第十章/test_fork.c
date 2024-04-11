#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{
  int sock;
  pid_t pid;

  sock = socket(PF_INET, SOCK_STREAM, 0);

  pid = fork();
  if (pid == 0)
  {
    printf("Child process: Socket file descriptor: %d\n", sock);
  }
  else
  {
    printf("Parent process: Socket file descriptor: %d\n", sock);
  }
  close(sock);
  return 0;
}