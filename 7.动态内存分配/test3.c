#include <stdlib.h>
#include <stdio.h>

int main() {
  int i;
  void *p = 0;// 2.指针定义的时候赋一个0值
  int cnt = 0;
  p = malloc(100*1024*1024);
  // p++;// 需要释放的指针不是申请来的
  p = &i;
  free(p);

  free(NULL);// 1.不报错的原因

  return 0;
}