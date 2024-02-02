#include <stdio.h>

int main(int argc, char const *argv[]) {
  FILE *fp = fopen("12.in", "r");// fp没有返回会返回NULL
  if (fp) {
    int num;
    fscanf(fp, "%d", &num);
    printf("%d\n", num);
    fclose(fp);
  } else {
    printf("无法打开文件\n");
  }

  return 0;
}
