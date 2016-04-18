#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

int fibonacci(n) {
  if (n < 2) {
    return n;
  }
  return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(int argc, char* argv[]) {
  const int iters = atoi(argv[1]);
  clock_t begin = clock();
  int res = fibonacci(iters);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  if (res > 0)
    printf("%f\n", time_spent);
  return 0;
}
