/* Binary Search */

#include <stdio.h>

int binarySearch(int arr[], int n, int elem) {
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high) {
    mid = (high + low) / 2;
    if (arr[mid] == elem) {
      return mid;
    } else if (arr[mid] < elem) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  int k, temp;
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &temp);
    printf("%d ", binarySearch(arr, n, temp));
  }
}