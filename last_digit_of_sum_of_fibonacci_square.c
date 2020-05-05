/*  Calculate last digit of sum of Fi^2 from i = 1 to n where Fi is ith
   Fibonacci number. */

/* We use Pisnao Period to solve this problem */
/* Pisano Period is period of series of Fn % m where the series starts repeating
   itself after certain terms p */
/* The sum of F1^2, F2^2, F3^2 ...Fn^2 is Fn+1*Fn */

#include <stdio.h>

#define pisanoPeriodTen 60

int lastDigitOfSum(long long n) {
  int arr[pisanoPeriodTen];
  arr[0] = 1;  // first term
  arr[1] = 1;  // second term
  // Calculate the Series upto Pisano Period
  for (int i = 2; i < pisanoPeriodTen; i++) {
    arr[i] = (arr[i - 1] + arr[i - 2]) % 10;
  }
  int lastDigit = 1;
  int index = n % (long long)pisanoPeriodTen;
  if (index == 0) index = pisanoPeriodTen;
  lastDigit *= arr[index - 1];  // Multiply Fn
  index = index % pisanoPeriodTen;
  lastDigit *= arr[index];  // Multiply Fn+1
  lastDigit = lastDigit % 10;
  return lastDigit;
}

void main() {
  long long n;
  scanf("%lld", &n);
  int result = sumLastDigits(n);
  printf("%d", result);
}