// This #ifdef block is something that we have added so we can test your
// code. Please ignore it.
#ifdef TEST
#include "average.h"
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
/// Excercise 6
/// Returns the average of an array
/// Pre: n>0, list[0...n-1] is defined
double average(int list[], int n) {
  double avg = 0;
  assert(n > 0);
  // insert your code here
  return avg;
}

// This #ifdef block is something that we have added so we can test your
// code. Please ignore it.
#ifndef TEST

int main() {

  printf("Hellope!\n");

  return 0;
}

#endif
