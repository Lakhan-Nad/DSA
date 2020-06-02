/*  Calculate last digit of sum of Fi^2 from i = 1 to n where Fi is ith
   Fibonacci number. */

/* We use Pisnao Period to solve this problem */
/* Pisano Period is period of series of Fn % m where the series starts repeating
   itself after certain terms p */
/* The sum of F1^2, F2^2, F3^2 ...Fn^2 is Fn+1*Fn */

#include <stdio.h>

#define pisanoPeriodTen 60

int squareFibonacciLastDigit(long long n) {
  int arr[pisanoPeriodTen];
  arr[0] = 0;  // first term
  arr[1] = 1;  // second term
  // Calculate the Series upto Pisano Period
  for (int i = 2; i < pisanoPeriodTen; i++) {
    arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
  }
  for (int i = 1; i < pisanoPeriodTen; i++) {
    arr[i] = (arr[i - 1] + arr[i]) % 10;
  }
  int index = (n + 1) % (long long)pisanoPeriodTen;
  int index2 = n % (long long)pisanoPeriodTen;
  return (index * index2) % 10;
}

void main() {
  long long n;
  scanf("%lld", &n);
  int result = squareFibonacciLastDigit(n);
  printf("%d", result);
}