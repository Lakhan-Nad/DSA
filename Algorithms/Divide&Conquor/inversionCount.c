/* Count no o f i,j such that arr[i] > arr[j] */

#include <stdio.h>

int inversions;

void merge(int arr[], int left, int mid, int right) {
  int size = right - left + 1;
  int copy[size];
  int i = left;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      copy[k++] = arr[i++];
    } else {
      copy[k++] = arr[j++];
      inversions += mid - i + 1;
    }
  }
  while (i <= mid) {
    copy[k++] = arr[i++];
  }
  while (j <= right) {
    copy[k++] = arr[j++];
    inversions += mid - i + 1;
  }
  k = 0;
  for (i = left; i <= right; i++) {
    arr[i] = copy[k++];
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left >= right) {
    return;
  }
  int mid = (left + right) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  inversions = 0;
  mergeSort(arr, 0, n - 1);
  //   for (int i = 0; i < n; i++) {
  //     printf("%d ", arr[i]);
  //   }
  printf("%d", inversions);
}