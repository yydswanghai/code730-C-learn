#include <stdio.h>

int main() {
  // a[0] => "Hello\0"
  // a[1] => "World\0"
  // a[2] => "dasdhauskhdadah\0" 超过10长度
  char a[][10] = {
    "Hello",
    "World",
    "dasdhauskhdadah"
  };

  // a[0] => 指针 => "Hello"
  // a[1] => 指针 => "World"
  // a[2] => 指针 => "dasdhauskhdadah"
  char *a2[] = {
    "Hello",
    "World",
    "dasdhauskhdadah"
  };

  return 0;
}