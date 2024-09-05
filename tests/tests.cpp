#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

extern "C" {
#include "average.h"
#include "counter.h"
#include "get_min.h"
#include "longest_seq.h"
#include "reverse.h"
}

// See Catch2's documentation:
// https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up
TEST_CASE("longest_seq") {
  int a[13] = {0, 0, 0, 4, 5, 0, 0, 0, 0, 0, 11, 0, 0};
  int b[5] = {1, 2, 3, 4, 5};

  REQUIRE(longest_seq(a, 13) == 5);
  REQUIRE(longest_seq(b, 5) == -1);
}

TEST_CASE("average") {
  {
    int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, -4, 0};
    double avg = average(list, 10);
    REQUIRE_THAT(avg, Catch::Matchers::WithinAbs(3.2, 1e-5));
  }
  {
    int list[] = {1, 7, 3, 24, 5, 5, 6};
    double avg = average(list, 7);
    REQUIRE_THAT(avg, Catch::Matchers::WithinAbs(7.285714, 1e-5));
  }
}

TEST_CASE("counter") {
  int v = 1;
  int a[100][150] = {{1, 1}};
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 150; j++) {
      a[i][j] = 20;
    }
  }

  a[1][1] = 1;
  a[2][2] = 2;
  a[2][3] = 2;
  a[3][3] = 3;
  a[3][4] = 4;
  a[10][10] = 5;
  a[20][20] = 6;
  a[30][30] = 7;
  a[40][40] = 8;
  a[50][50] = 9;
  a[50][51] = 10;
  a[50][52] = 11;
  a[50][53] = 12;
  a[50][54] = 13;
  a[50][55] = 14;
  a[50][56] = 15;
  a[50][57] = 16;
  a[50][58] = 17;
  a[50][59] = 18;
  a[50][60] = 19;

  int countA[20];
  int countB[20] = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1,
                    1, 1, 1, 1, 1, 1, 1, 1, 1, 14980};
  count_1_to_20(a, countA);
  REQUIRE(countA == countB);
}

TEST_CASE("reverse") {
  int a[5] = {1, 2, 3, 4, 5};
  int b[5];
  int c[5] = {5, 4, 3, 2, 1};
  reverse(a, b, 5);
  REQUIRE(b == c);
}

TEST_CASE("get_min") {
  {
  int list[5] = {1, 2, 3, 4, 5};
  int n = 5;
  REQUIRE(get_min(list, n) == 1);
  }
  {
  int list[5] = {5, 4, 3, 2, 1};
  int n = 5;
  REQUIRE(get_min(list, n) == 1);
  }
  {
  int list[5] = {1, -3, -5, 8, 2};
  int n = 5;
  REQUIRE(get_min(list, n) == -5);
  }
}
