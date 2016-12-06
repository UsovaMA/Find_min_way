#include "FindMinWay.h"
#include <queue>
#include <iostream>
#include <limits>
float inf = std::numeric_limits<float>::infinity();

float find_min_way(float** matrix, int n, int m) {  // обход в ширину
  if ((n == 0) || (m == 0)) {
    throw logic_error("Error description\n"); 
  }

  float** field = new float*[n];
  for (int i = 0; i < n; ++i) {
    field[i] = new float[m];
    for (int j = 0; j < m; ++j)
      field[i][j] = inf;
  }

  float len = 0;
  std::queue<coordinates> Q;

  coordinates Y;  // наша начальная точка
  Y.x = 0;
  Y.y = m - 1;
  Q.push(Y);
  field[Y.x][Y.y] = 0;

  while (!Q.empty()) {
    coordinates point = Q.front();
    Q.pop();
    if (point.x > 0) {
      if ((matrix[point.x - 1][point.y] == 1)
        && (field[point.x - 1][point.y] == inf)) {
        coordinates* tmp = new coordinates;
        tmp->x = (point.x - 1);
        tmp->y = (point.y);
        Q.push(*tmp);
        field[point.x - 1][point.y] = field[point.x][point.y] + 1;
      }
    }
    if (point.x < (n - 1)) {
      if ((matrix[point.x + 1][point.y] == 1)
        && (field[point.x + 1][point.y] == inf)) {
        coordinates* tmp = new coordinates;
        tmp->x = (point.x + 1);
        tmp->y = (point.y);
        Q.push(*tmp);
        field[point.x + 1][point.y] = field[point.x][point.y] + 1;
      }
    }
    if (point.y > 0) {
      if ((matrix[point.x][point.y - 1] == 1)
        && (field[point.x][point.y - 1] == inf)) {
        coordinates* tmp = new coordinates;
        tmp->x = (point.x);
        tmp->y = (point.y - 1);
        Q.push(*tmp);
        field[point.x][point.y - 1] = field[point.x][point.y] + 1;
      }
    }
    if (point.y < m - 1) {
      if ((matrix[point.x][point.y + 1] == 1)
        && (field[point.x][point.y + 1] == inf)) {
        coordinates* tmp = new coordinates;
        tmp->x = (point.x);
        tmp->y = (point.y + 1);
        Q.push(*tmp);
        field[point.x][point.y + 1] = field[point.x][point.y] + 1;
      }
    }
  }
  len = field[n - 1][0];
  if ((len == 0) || (len == INFINITY)) {
	  throw logic_error("Error description\n");  // исключение в случае, если пути между точками нет
  }
  return len;
}
