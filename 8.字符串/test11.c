// 自动计数枚举
// 这里，这样需要遍历所有的枚举量或者需要建立一个用枚举量做下标的数组的时候就很方便了

#include <stdio.h>

enum color { RED, YELLOW, GREEN, NumCOLORS };

int main(int argc, char const *argv[]) {
  int color = -1;
  char *ColorNames[NumCOLORS] = {
    "red", "yellow", "green"
  };
  char *colorName = NULL;
  scanf("%d", &color);
  if (color >= 0 && color < NumCOLORS) {
    colorName = ColorNames[color];
  } else {
    colorName = "unknown";
  }
  printf("你喜欢的颜色是%s\n", colorName);

  return 0;
}
