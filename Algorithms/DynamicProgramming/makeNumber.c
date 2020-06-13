/* You are given a primitive calculator that can perform the following three
operations with the current number x: multiply x by 2, multiply x by 3, or add 1
to x. Your goal is given a positive integer n, find the minimum number of
operations needed to obtain the number n starting from the number 1.
*/

#include <stdio.h>

void makeNumber(int n) {
  int temp[n + 1];
  int prev[n + 1];
  temp[0] = 0, prev[0] = -1;
  temp[1] = 0, prev[1] = -1;
  for (int i = 2; i <= n; i++) {
    int smallest = temp[i - 1] + 1;
    prev[i] = i - 1;
    if (i % 2 == 0) {
      if (smallest > temp[i / 2] + 1) {
        smallest = temp[i / 2] + 1;
        prev[i] = i / 2;
      }
    }
    if (i % 3 == 0) {
      if (smallest > temp[i / 3] + 1) {
        smallest = temp[i / 3] + 1;
        prev[i] = i / 3;
      }
    }
    temp[i] = smallest;
  }
  printf("%d\n", temp[n]);
  int x = 0;
  int cur = n;
  while (cur != -1) {
    temp[x++] = cur;
    cur = prev[cur];
  }
  for (int i = 0; i < x; i++) {
    printf("%d ", temp[x - 1 - i]);
  }
}

void main() {
  int n;
  scanf("%d", &n);
  makeNumber(n);
}