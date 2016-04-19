// See license.txt for details about licensing.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

class vec_t {
 public:
  float x, y, z;
  vec_t (const float x, const float y, const float z) : x(x), y(y), z(z) {}
  
  vec_t operator+(const vec_t& b) const {
    return vec_t(x + b.x, y + b.y, z + b.z);
  }
};

vec_t benchmark (int n, const vec_t& p) {
  vec_t sum(0.0, 0.0, 0.0);
  for (int i = 0; i < n; i++) 
    sum = sum + p;
  return sum;
}

int main (int argc, char* argv[]) {
  const int iters = atoi(argv[1]);
  clock_t begin = clock();
  const vec_t p = vec_t(0.1, 0.2, 0.3);
  vec_t res = benchmark(iters, p);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  if (res.x > 0.0)
    printf("%f\n", time_spent);
}
