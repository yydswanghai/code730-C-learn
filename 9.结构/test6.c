// 输入结构
#include <stdio.h>

struct point {
  int x;
  int y;
};
struct point getStruct(void);
void output(struct point);
int main(int argc, char const *argv[]) {
  struct point y = {0, 0};
  y = getStruct();
  output(y);
  return 0;
}
// 不传递point，而是返回
struct point getStruct(void){
  struct point p;
  scanf("%d", &p.x);
  scanf("%d", &p.y);
  printf("getStruct函数里的x=%d,y=%d\n", p.x, p.y);
  return p;
}
// 输出y
void output(struct point p){
  printf("main函数里的x=%d,y=%d\n", p.x, p.y);
}