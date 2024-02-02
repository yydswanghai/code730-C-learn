// 标准头文件结构

#ifndef _MAX_H_
#define _MAX_H_

struct Node {
  int value;
  char* name;
};

#endif

// 如果没有定义_MAX_H_，那么就定义_MAX_H_
// 编译器会看这个东西有没有存在过
// 这样加入标准头结构做保护