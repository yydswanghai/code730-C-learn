// 结构的结构
#include <stdio.h>

struct point {
  int x;
  int y;
};
struct rectangle {
  struct point pt1;
  struct point pt2;
}
// rp指针指向r这个rectangle
int main(int argc, char const *argv[]) {
  struct rectangle r, *rp;
  rp = &r;

  // 以下等价
  r.pt1.x;
  rp->pt1.x;
  (r.pt1).x;
  (rp->pt1).x;

  return 0;
}
