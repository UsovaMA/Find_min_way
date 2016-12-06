#include <gtest/gtest.h>
#include <gtest/gtest.h>
#include "FindMinWay.h"

TEST(FindMinWay, can_find_in_matrix_with_ones_string) {
  int n = 1, m = 5;
  float** my_matrix = new float*[n];
  for (int i = 0; i < n; ++i) {
    my_matrix[i] = new float[m];
    for (int j = 0; j < m; ++j)
      my_matrix[i][j] = 1;
  }
  float res = find_min_way(my_matrix, n, m);
  EXPECT_EQ(m - 1, res);
}

TEST(FindMinWay, can_find_in_matrix_with_ones_column) {
  int n = 5, m = 1;
  float** my_matrix = new float*[n];
  for (int i = 0; i < n; ++i) {
    my_matrix[i] = new float[m];
    for (int j = 0; j < m; ++j)
      my_matrix[i][j] = 1;
    }
  float res = find_min_way(my_matrix, n, m);
  EXPECT_EQ(n - 1, res);
}

/* 1 1 1 0 Y
   1 1 1 0 1
   1 0 1 1 1
   X 0 1 1 1 */

TEST(FindMinWay, can_find_way_in_rectangular_matrix) {
  int n = 4, m = 5;
  float** my_matrix = new float*[n];
  for (int i = 0; i < n; ++i) {
    my_matrix[i] = new float[m];
    for (int j = 0; j < m; ++j)
      my_matrix[i][j] = 1;
  }
  my_matrix[0][3] = 0;
  my_matrix[1][3] = 0;
  my_matrix[2][1] = 0;
  my_matrix[3][1] = 0;
  float res = find_min_way(my_matrix, n, m);
  EXPECT_EQ(9, res);
}

TEST(FindMinWay, throw_then_empty_field) {
  int n = 0, m = 0;
  float** field = NULL;
  float res = 0;
  EXPECT_ANY_THROW(res = find_min_way(field, n, m));

}

TEST(FindMinWay, throw_then_no_way_in_string) {
  int n = 1, m = 10;
  float** my_matrix = new float*[n];
  for (int i = 0; i < n; ++i) {
    my_matrix[i] = new float[m];
    for (int j = 0; j < m; ++j)
      my_matrix[i][j] = 1;
  }
  my_matrix[0][5] = 0;
  float res = 0;
  EXPECT_ANY_THROW(res = find_min_way(my_matrix, n, m));
}

TEST(FindMinWay, throw_then_no_way_in_column) {
  int n = 10, m = 1;
  float** my_matrix = new float*[n];
  for (int i = 0; i < n; ++i) {
    my_matrix[i] = new float[m];
    for (int j = 0; j < m; ++j)
      my_matrix[i][j] = 1;
  }
  my_matrix[5][0] = 0;
  float res = 0;
  EXPECT_ANY_THROW(res = find_min_way(my_matrix, n, m));
}

/* 1 1 0 1 Y
   1 1 0 1 1
   1 1 0 1 1
   X 1 0 1 1 */

TEST(FindMinWay, throw_then_matrix_without_a_way) {
  int n = 4, m = 5;
  float** my_matrix = new float*[n];
  for (int i = 0; i < n; ++i) {
    my_matrix[i] = new float[m];
    for (int j = 0; j < m; ++j)
      my_matrix[i][j] = 1;
  }
  my_matrix[0][2] = 0;
  my_matrix[1][2] = 0;
  my_matrix[2][2] = 0;
  my_matrix[3][2] = 0;
  float res = 0;
  EXPECT_ANY_THROW(res = find_min_way(my_matrix, n, m));
}

int main(int ac, char* av[]) {
  testing::InitGoogleTest(&ac, av);
  return RUN_ALL_TESTS();
}
