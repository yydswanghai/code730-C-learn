// 输出int类型的最大数

#include <stdio.h>

int main() {
  int a=0,b=0;
  while (++a>0);
  // int最大的数+1变成一个负数，用这个负数-1就可以得到int的最大值
  // 相当于从0一直加到int最大数+1，此时不大于零，不在次进入while循环
  printf("int类型最大数是：%d\n", a-1);
  b++;
  while ((a=a/10)!=0) {
    b++;
  }
  
  printf("int类型最大的数的数位是：%d\n", b);   
   
  return 0;
}
