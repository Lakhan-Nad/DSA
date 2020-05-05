#include <stdio.h>

int lastDigitFibonacci(int n) {
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else {
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
      c = (a + b) % 10;
      a = b;
      b = c;
    }
    return c;
  }
}

void main() {
  int n;
  scanf("%d", &n);
  int result = lastDigitFibonacci(n);
  printf("%d", result);
}