/* You are given a set of bars of gold and your goal is to take as much gold as
possible into your bag. There is just one copy of each bar and for each bar you
can either take it or not (hence you cannot take a fraction of a bar).
*/

/* A case of discrete knapsack without repetations
 */

#include <stdio.h>
#include <stdlib.h>

long max(long a, long b) {
  if (a > b)
    return a;
  else
    return b;
}

long knapsack(long weight, long arr[], int size) {
  long *dp[weight + 1];
  for (int i = 0; i <= weight; i++) {
    dp[i] = (long *)malloc((size + 1) * (sizeof(long)));
  }
  for (int i = 0; i <= weight; i++) {
    for (int j = 0; j <= size; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (i < arr[j - 1]) {
        dp[i][j] = dp[i][j - 1];
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - arr[j - 1]][j - 1] + arr[j - 1]);
      }
    }
  }
  long ans = dp[weight][size];
  for (int i = 0; i <= weight; i++) {
    free(dp[i]);
  }
  return ans;
}

void main() {
  long weight;
  int n;
  scanf("%ld %d", &weight, &n);
  long arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%ld", arr + i);
  }
  long ans = knapsack(weight, arr, n);
  printf("%ld", ans);
}