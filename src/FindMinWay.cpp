#include "FindMinWay.h"
#include <queue>
#include <iostream>

float find_min_way(float** matrix, int n, int m) {  // обход в ширину
  if ((n == 0) || (m == 0)) {
    throw 1;  // исключение для неверно заданной матрицы
  }

  float** field = new float*[n];
  for (int i = 0; i < n; ++i) {
    field[i] = new float[m];
    for (int j = 0; j < m; ++j)
      field[i][j] = INFINITY;
  }

  float len = 0;
  std::queue<coordinates> Q;

  coordinates Y;  // наша начальная точка
  Y.string = 0;
  Y.column = m - 1;
  Q.push(Y);
  field[Y.string][Y.column] = 0;

  while (!Q.empty()) {
    coordinates point = Q.front();
    Q.pop();
    if (point.string > 0) {
      if ((matrix[point.string - 1][point.column] == 1)
        && (field[point.string - 1][point.column] == INFINITY)) {
        coordinates* tmp = new coordinates;
        tmp->string = (point.string - 1);
        tmp->column = (point.column);
        Q.push(*tmp);
        field[point.string - 1][point.column] = field[point.string][point.column] + 1;
      }
    }
    if (point.string < (n - 1)) {
      if ((matrix[point.string + 1][point.column] == 1)
        && (field[point.string + 1][point.column] == INFINITY)) {
        coordinates* tmp = new coordinates;
        tmp->string = (point.string + 1);
        tmp->column = (point.column);
        Q.push(*tmp);
        field[point.string + 1][point.column] = field[point.string][point.column] + 1;
      }
    }
    if (point.column > 0) {
      if ((matrix[point.string][point.column - 1] == 1)
        && (field[point.string][point.column - 1] == INFINITY)) {
        coordinates* tmp = new coordinates;
        tmp->string = (point.string);
        tmp->column = (point.column - 1);
        Q.push(*tmp);
        field[point.string][point.column - 1] = field[point.string][point.column] + 1;
      }
    }
    if (point.column < m - 1) {
      if ((matrix[point.string][point.column + 1] == 1)
        && (field[point.string][point.column + 1] == INFINITY)) {
        coordinates* tmp = new coordinates;
        tmp->string = (point.string);
        tmp->column = (point.column + 1);
        Q.push(*tmp);
        field[point.string][point.column + 1] = field[point.string][point.column] + 1;
      }
    }
  }
  len = field[n - 1][0];
  if ((len == 0) || (len == INFINITY)) {
    throw 2;  // исключение в случае, если пути между точками нет
  }
  return len;
}
