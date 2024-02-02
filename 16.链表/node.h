#ifndef _NODE_H_
#define _NODE_H_

typedef struct _node {
  int value;
  struct _node *next;// 这行时，Node还未出现，所以这里要用 struct _node
} Node;

#endif