/*  Calculate last digit of sum of Fi from i = 1 to n where Fi is ith
   Fibonacci number. */

/* We use Pisnao Period to solve this problem */
/* Pisano Period is period of series of Fn % m where the series starts repeating
   itself after certain terms p */
/* The sum of F1, F2, F3, F4...Fn is Fn+2 -1 */

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
  int index = (n + 2) % (long long)pisanoPeriodTen;
  if (index == 0) index = pisanoPeriodTen;
  int lastDigit = arr[index - 1] - 1;
  return lastDigit;
}

void main() {
  long long n;
  scanf("%lld", &n);
  int result = sumLastDigits(n);
  printf("%d", result);
}