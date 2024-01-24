// 求符合给定条件的整数集 2～6 之间
// 输入: 6
// 输出:
// 678 679 687 689 697 698
// 768 769 786 789 796 798
// 867 869 876 879 896 897
// 967 968 976 978 986 987

#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);
  // i => index, j 是i的下一个字母，k 是j的下一个字母
  int i,j,k;
  int cnt = 0;

  i = a;
  while (i <= a+3) {
    j = a;
    while (j <= a+3) {
      k = a;
      while (k <= a+3) {
        if (i != j) {
          if (i != k) {
            if (j != k) {
              cnt++;
              printf("%d%d%d", i, j, k);
              if (cnt == 6) {
                printf("\n");
                cnt = 0;
              } else {
                printf(" ");
              }
            }
          }
        }
        k++;
      }
      j++;
    }
    i++;
  }
  
  return 0;
}
