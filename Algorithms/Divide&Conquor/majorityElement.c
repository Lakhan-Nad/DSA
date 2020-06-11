/* Find if there exists a majority element in array */

#include <stdio.h>

int maxCandidate(int arr[], int n) {
  int count = 1;
  int maxCandidate = __INT32_MAX__;
  for (int i = 0; i < n; i++) {
    if (maxCandidate == arr[i]) {
      count++;
    } else {
      count--;
    }
    if (count == 0) {
      count = 1;
      maxCandidate = arr[i];
    }
  }
  return maxCandidate;
}

int isMajority(int arr[], int n, int elem) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == elem) count++;
  }
  if (count >= n / 2 + 1) {
    return 1;
  } else {
    return 0;
  }
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  int elem = maxCandidate(arr, n);
  int ifExists = isMajority(arr, n, elem);
  printf("%d", ifExists);
}