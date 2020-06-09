/* Given an integer find minimum number of denominations in 1, 5, 10 */

#include <stdio.h>

void main() {
  int n;
  scanf("%d", &n);
  int ten = n / 10;
  int five = (n % 10) / 5;
  int one = n % 5;
  printf("%d\n", (ten + five + one));
}