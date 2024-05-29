#include <stdio.h>
#include <stdlib.h>
#include "./index.h"
/**
 * 该函数在检测到错误时，向用户展示一个错误消息，并随后终止程序执行
 * - stderr 是 C 语言标准库中定义的一个文件流，通常用于输出错误或诊断信息
 * - fputc 是一个用于写入单个字符到文件流的函数，这里它写入了一个换行符 '\n'
 */
void error_handling(char *message) {
  fputs(message, stderr);// 将字符串(message)写入到标准错误流(stderr)，直到遇到字符串结束符 '\0'
  fputc('\n', stderr);// 这行代码向 stderr 输出一个换行符
  exit(1);// 终止程序，状态码1
}