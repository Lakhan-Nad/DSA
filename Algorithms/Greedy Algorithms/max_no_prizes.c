/* You are organizing a funny competition for children. As a prize fund you have
n candies. You would like to use these candies for top k places in a competition
with a natural restriction that a higher place gets a larger number of candies.
To make as many children happy as possible, you are going to find the largest
value of k for which it is possible.
*/

#include <stdio.h>

void main() {
  long long n;
  scanf("%lld", &n);
  long long z = 1;
  while ((z * (z + 1)) / 2 <= n) {
    z++;
  }
  z--;
  printf("%lld\n", z);
  for (long long i = 1; i <= z - 1; i++) {
    printf("%lld ", i);
  }
  n -= (z * (z - 1)) / 2;
  printf("%lld", n);
}