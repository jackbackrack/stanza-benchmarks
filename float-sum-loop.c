#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

float benchmark (int n) {
  float sum = 0.0;
  for (int i = 0; i < n; i++) 
    sum = sum + (float)(i);
  return sum;
}

int main (int argc, char* argv[]) {
  const int iters = atoi(argv[1]);
  clock_t begin = clock();
  float res = benchmark(iters);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  if (res > 0.0)
    printf("%f\n", time_spent);
}
