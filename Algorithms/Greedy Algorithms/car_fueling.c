/* You are going to travel to another city that is located d miles away from
your home city. Your car can travel at most m miles on a full tank and you start
with a full tank. Along your way, there are gas stations at distances stop1,
stop2 , . . . , stopn from your home city. What is the minimum number of refills
needed?
*/

#include <stdio.h>

void main() {
  int d;
  int m;
  int n;
  scanf("%d %d %d", &d, &m, &n);
  int dists[n + 2];
  dists[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", dists + i);
  }
  dists[n + 1] = d;
  int fuel = m;
  int fills = 0;
  int current = 0;
  int next;
  while (fuel >= 0 && current != n + 1) {
    if (fuel - dists[current + 1] + dists[current] < 0) {
      fuel = m;
      fills++;
    }
    fuel -= dists[current + 1] - dists[current];
    current++;
  }
  if (fuel < 0) {
    printf("%d", -1);
  } else {
    printf("%d", fills);
  }
}