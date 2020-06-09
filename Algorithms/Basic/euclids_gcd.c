#include <stdio.h>

int gcd(int a, int b) {
  if (a <= 0 || b <= 0) {
    return -1;
  }
  int d = a < b ? a : b;
  int g = a > b ? a : b;
  int r;
  while (g % d) {
    r = g % d;
    g = d;
    d = r;
  }
  return d;
}

void main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int result = gcd(a, b);
  printf("%d", result);
}