/*  Calculate last digit of sum of Fi from i = m to n where Fi is ith Fibonacci
    number. */

/* We use Pisnao Period to solve this problem */
/* Pisano Period is period of series of Fn % m where the series starts repeating
   itself after certain terms p */
/* The sum of F1, F2, F3, F4...Fn is Fn+2 -1 */

#include <stdio.h>

#define pisanoPeriodTen 60

int sumLastDigitsMtoN(long long m, long long n) {
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
  int left = (m - 1 > 0 ? m - 1 : 0) % (long long)pisanoPeriodTen;
  int right = n % (long long)pisanoPeriodTen;
  int lastDigit = (10 + arr[right] - arr[left]) % 10;
  return lastDigit;
}

void main() {
  long long m, n;
  scanf("%lld %lld", &m, &n);
  int result = sumLastDigitsMtoN(m, n);
  printf("%d", result);
}