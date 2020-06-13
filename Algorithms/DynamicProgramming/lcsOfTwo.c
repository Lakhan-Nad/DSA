/* Find Longest Common Subsequence of two Sequences */

#include <stdio.h>

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int lcs(int arr1[], int len1, int arr2[], int len2) {
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (arr1[i - 1] == arr2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[len1][len2];
}

void main() {
  int n;
  scanf("%d", &n);
  int arr1[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr1 + i);
  }
  int m;
  scanf("%d", &m);
  int arr2[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", arr2 + i);
  }
  int ans = lcs(arr1, n, arr2, m);
  printf("%d", ans);
}