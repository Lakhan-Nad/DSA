/* Can given numbers be partitioned into three subsets of equal sum */

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int partition(int arr[], int n, int k) {
  long x = 1 << n;
  char *dp = (char *)malloc(x * sizeof(char));
  int *total = (int *)malloc(x * sizeof(int));
  qsort(arr, n, sizeof(int), compare);
  int sum = 0;
  for (int i = 0; i < n; i++) sum += arr[i];
  if (sum % k || arr[n - 1] > sum / k) return 0;
  dp[0] = 1;
  sum /= k;
  for (int i = 0; i < x; i++) {
    if (dp[i]) {
      for (int j = 0; j < n; j++) {
        int temp = i | (1 << j);
        if (temp != i) {
          if (arr[j] <= sum - (total[i] % sum)) {
            dp[temp] = 1;
            total[temp] = total[i] + arr[j];
          } else {
            break;
          }
        }
      }
    }
  }
  int ans = (int)dp[x - 1];
  free(dp);
  free(total);
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  int possible = partition(arr, n, 3);
  printf("%d", possible);
}