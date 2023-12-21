// 2.如果是这种情况输入
// code=24 count=20，输出"继续等待"
// code=24 count=19 输出"一切正常"
// code=50 count=25 将没有任何输出
// 所有 else 匹配的最里面的 if

#include <stdio.h>

int main()
{
  const int READY = 24;
  int code = 0;
  int count = 0;
  printf("请输入code count: ");
  scanf("%d %d", &code, &count);
  if (code == READY) 
    if (count < 20)
      printf("一切正常\n");
  else
      printf("继续等待\n");

  return 0;
}