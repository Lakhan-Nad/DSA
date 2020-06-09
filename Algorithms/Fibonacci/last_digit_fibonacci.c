#include <stdio.h>

long long lastDigitFibonacci(long long n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else {
    long long a = 0;
    long long b = 1;
    long long c;
    for (long long i = 2; i <= n; i++) {
      c = (a + b) % 10;
      a = b;
      b = c;
    }
    return c;
  }
}

void main() {
  long long n;
  scanf("%lld", &n);
  long long result = lastDigitFibonacci(n);
  printf("%lld", result);
}