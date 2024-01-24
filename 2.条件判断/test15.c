// 在嵌套的for中跳出
// break和continue 只能对它所在的那层循环做

#include <stdio.h>

// 1.接力break
int main() {
  int x;// 元
  int one, two, five;// 角
  int exit = 0;
  scanf("%d", &x);
  
  for ( one = 1; one < x*10 ; one++) {
    for ( two = 1; two < x*10/2 ; two++) {
      for ( five = 1; five < x*10/5 ; five++) {
        if (one + two*2 + five*5 == x*10) {
          printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n", 
            one, two, five, x);
          exit = 1;
          break;
        }
      }
      if(exit) break;// 相当于 if(exit == 1) break;
    }
    if(exit) break;
  }

  return 0;
}

// 2.使用goto
int main2() {
  int x;// 元
  int one, two, five;// 角

  scanf("%d", &x);
  
  for ( one = 1; one < x*10 ; one++) {
    for ( two = 1; two < x*10/2 ; two++) {
      for ( five = 1; five < x*10/5 ; five++) {
        if (one + two*2 + five*5 == x*10) {
          printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n", 
            one, two, five, x);
          goto out;// 从这里
        }
      }
    }
  }

  // 跳到这里
  out:
  
  return 0;
}