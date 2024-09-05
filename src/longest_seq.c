// This #ifdef block is something that we have added so we can test your
// code. Please ignore it.
#ifdef TEST
#include "longest_seq.h"
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/// Excercise 3
/// Returns the index in list of the logest sequence of zeros in list, -1 if no
/// zeros in list pre: n>0
int longest_seq(int list[], int n) {
  assert(n > 0);
  // insert your code here

  return 0;
}

// This #ifdef block is something that we have added so we can test your
// code. Please ignore it.
#ifndef TEST

int main() {
  int a[13] = {0, 0, 0, 4, 5, 0, 0, 0, 0, 0, 11, 0, 0};
  int b[5] = {1, 2, 3, 4, 5};

  printf("The longest sequence of zeros start index is %d\n",
         longest_seq(a, 13));

  printf("The longest sequence of zeros start index is %d\n",
         longest_seq(b, 5));

  printf("Hellope!\n");

  return 0;
}

#endif
