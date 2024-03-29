// 三字旗

#include <stdio.h>

int main() {
  const int size = 3;
  int board[size][size];
  int i,j;
  int numOfX;
  int numOfO;
  int result = -1;// -1 无人赢 1X赢 0O赢

  // 读入矩阵
  for ( i = 0; i < size; i++) {
    for ( j = 0; j < size; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  // 检查行
  for ( i = 0; i < size && result == -1; i++) {
    numOfO = numOfX = 0;
    for ( j = 0; j < size ; j++) {
      if (board[i][j] == 1) {
        numOfX++;
      } else {
        numOfO++;
      }
    }
    if (numOfO == size) {
      result = 0;
    } else if (numOfX == size) {
      result = 1;
    }
  }
  // 检查列
  if (result == -1) {
    for ( j = 0; j < size && result == -1; j++) {
      numOfO = numOfX = 0;
      for ( i = 0; i < size ; i++) {
        if (board[i][j] == 1) {
          numOfX++;
        } else {
          numOfO++;
        }
      }
      if (numOfO == size) {
        result = 0;
      } else if (numOfX == size) {
        result = 1;
      }
    }
  }
  // 检查对角线
  numOfO = numOfX = 0;
  for ( i = 0; i < size; i++) {
    if (board[i][j] == 1) {
      numOfX++;
    } else {
      numOfO++;
    }
  }
  if (numOfO == size) {
    result = 0;
  }else {
    result = 1;
  }
  
  numOfO = numOfX = 0;
  for ( i = 0; i < size; i++) {
    if (board[i][size-i-1] == 1) {
      numOfX++;
    } else {
      numOfO++;
    }
  }

  return 0;
}