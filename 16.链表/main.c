#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void add(Node *head, int number);
void print(List *list);
typedef struct _list {
  Node* head;// 该指针指向第一个
} List;

int main(int argc, char const *argv[]) {

  List list;
  list.head = NULL;
  int number;
  do {
    scanf("%d", &number);
    if (number != -1) {
      add(&list, number);
    }
  } while (number != -1);
  print(&list);
  // 用户输入一个数字
  scanf("%d", &number);
  Node *p;
  int isFound = 0;
  for ( p = list->head; p; p = p->next) {
    if (p->value == number) {// 找到用户输入的数字
      printf("找到了\n");
      isFound = 1;
      break;
    }
  }
  if (!isFound) {
    printf("没有找到\n");
  }
  // 删除
  Node *q;
  for ( q=NULL, p=list->head; p; q=p, p=p->next) {
    if (p->value == number) {// 找到用户输入的数字
      if (q) {
        q->next = p->next;// 1.连接p的上一个节点和下一个节点
      } else {// q是NULL
        list.head = p->next;
      }
      free(p) // 2.回收内存
      break;
    }
  }

  return 0;
}

void add(List *list, int number) {
  Node *p = (Node*)malloc(sizeof(Node));// 申请一块p指针的内存，表示新的节点
  p->value = number;// 初始化
  p->next = NULL;   // 初始化
  // find the next 用末尾节点的next指向它（上面新的节点）
  Node *last = list->head;
  if (last) {// 非第一个节点
    // 找到末尾的节点，因为末尾节点的next是NULL，循环结束，last就是最后那个末尾的节点
    while (last->next) {
      last = last->next;
    }
    last->next = p;// 连接新节点
  } else {// 第一个节点
    list->head = p;
  }
}
// 遍历
void print(List *list) {
  Node *p;
  for ( p = list->head; p; p = p->next) {
    printf("%d\t", p->value);
  }
  printf("\n");
}