/*  You are given a set
of segments on a line and your goal is to mark as few points on a line as
possible so that each segment contains at least one marked point.
*/

#include <stdio.h>

int farther(int a[2], int b[2]) {
  if (a[1] != b[1]) {
    return a[1] > b[1];
  } else {
    return a[0] > b[0];
  }
}

void swap(int a[2], int b[2]) {
  int x = a[0];
  int y = a[1];
  a[0] = b[0];
  a[1] = b[1];
  b[0] = x;
  b[1] = y;
}

void sortByRight(int arr[][2], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (farther(arr[j], arr[j + 1])) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n][2];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &arr[i][0], &arr[i][1]);
  }
  sortByRight(arr, n);
  int cur = 0;
  int ans[n];
  for (int i = 0; i < n; i++) {
    ans[cur] = arr[i][1];
    while (i < n && arr[i][0] <= ans[cur]) {
      i++;
    }
    i--;
    cur++;
  }
  printf("%d\n", cur);
  for (int i = 0; i < cur; i++) {
    printf("%d ", ans[i]);
  }
}