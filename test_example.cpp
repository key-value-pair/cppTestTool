#include "test_tool.h"

int add(int a, int b) {
  return a + b;
}

int plus(int a, int b) {
  return a * b;
}

void test_add() {
  int a, b;
  int actual, expect;

  a = 0;
  b = 0;
  actual = add(a, b);
  expect = 0;
  AssertEqualDefaultMsg(actual, expect);
}

void test_plus() {
  int a, b;
  int actual, expect;

  a = 1;
  b = 1;
  actual = plus(a, b);
  expect = 2;
  AssertEqualDefaultMsg(actual, expect);
}

ADD_TEST(test_add);
ADD_TEST(test_plus);
