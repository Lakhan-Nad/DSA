/* Find Longest Common Subsequence of three Sequences */

#include <stdio.h>

int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}

int lcs(int arr1[], int len1, int arr2[], int len2, int arr3[], int len3) {
  int dp[len1 + 1][len2 + 1][len3 + 1];
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      for (int k = 0; k <= len3; k++) {
        if (i == 0 || j == 0 || k == 0) {
          dp[i][j][k] = 0;
        } else if (arr1[i - 1] == arr2[j - 1] && arr2[j - 1] == arr3[k - 1]) {
          dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
        } else {
          dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
          dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
        }
      }
    }
  }
  return dp[len1][len2][len3];
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
  int p;
  scanf("%d", &p);
  int arr3[p];
  for (int i = 0; i < p; i++) {
    scanf("%d", arr3 + i);
  }
  int ans = lcs(arr1, n, arr2, m, arr3, p);
  printf("%d", ans);
}