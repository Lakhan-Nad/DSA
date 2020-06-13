/* The edit distance between two strings is the minimum number of operations
(insertions, deletions, and substitutions of symbols) to transform one string
into another. It is a measure of similarity of two strings. Edit distance has
applications, for example, in computational biology, natural language
processing, and spell checking. Your goal in this problem is to compute the edit
distance between two strings.
*/

#include <stdio.h>
#include <string.h>

int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}

int editDistance(char s1[], char s2[]) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i <= len1; i++) {
    dp[i][0] = i;
  }
  for (int i = 0; i <= len2; i++) {
    dp[0][i] = i;
  }
  for (int j = 1; j <= len2; j++) {
    for (int i = 1; i <= len1; i++) {
      int smallest = dp[i - 1][j] + 1;
      smallest = min(smallest, dp[i][j - 1] + 1);
      if (s1[i - 1] == s2[j - 1]) {
        smallest = min(smallest, dp[i - 1][j - 1]);
      } else {
        smallest = min(smallest, dp[i - 1][j - 1] + 1);
      }
      dp[i][j] = smallest;
    }
  }
  return dp[len1][len2];
}

void main() {
  char str1[101];
  char str2[101];
  scanf("%s", str1);
  scanf("%s", str2);
  int ans = editDistance(str1, str2);
  printf("%d", ans);
}