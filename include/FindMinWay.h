#ifndef __FINDMINWAY_H_
#define __FINDMINWAY_H_
#include <stdio.h>

struct coordinates {
  int x;
  int y;
};

struct logic_error {
  char* x;
  logic_error(char* p) {
    x = new char[30];
    x = p;
  }
  void what() {
    printf("%s", x);
  }
};

float find_min_way(float** martix, int n, int m);

#endif
