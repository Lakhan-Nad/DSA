#include <stdio.h>

long long gcd(long long a, long long b) {
  if (a <= 0 || b <= 0) {
    return -1;
  }
  long long d = a < b ? a : b;
  long long g = a > b ? a : b;
  long long r;
  while (g % d) {
    r = g % d;
    g = d;
    d = r;
  }
  return d;
}

long long lcm(long long a, long long b) {
  long long gcdAB = gcd(a, b);
  long long lcmAB = (a * b) / gcdAB;
  return lcmAB;
}

void main() {
  long long a, b;
  scanf("%lld %lld", &a, &b);
  long long result = lcm(a, b);
  printf("%lld", result);
}