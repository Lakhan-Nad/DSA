#include <stdio.h>

long fibonacci(int n) {
  if (n == 0)
    return (long)0;
  else if (n == 1)
    return (long)1;
  else {
    long a = 0;
    long b = 1;
    long c;
    for (int i = 2; i <= n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  long result = fibonacci(n);
  printf("%d", result);
}