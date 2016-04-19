// See license.txt for details about licensing.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

float benchmark (int n, float* v, int len) {
  float sum = 0.0;
  for (int j = 0; j < n; j++) 
    for (int i = 0; i < len; i++)
      sum = sum + v[i];
  return sum;
}

int main (int argc, char* argv[]) {
  const int iters = atoi(argv[1]);
  clock_t begin = clock();
  const int n = 1000;
  float* v  = (float*)malloc(n * sizeof(float));
  for (int i = 0; i < n; i++) v[i] = 0.1;
  float res = benchmark(iters, v, n);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  if (res > 0.0)
    printf("%f\n", time_spent);
}
