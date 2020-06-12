/* A 3-way partiton quick sort algorithm */

#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void partition(int arr[], int left, int right, int *i, int *j) {
  int mid = (left + right) / 2;
  int pivot = arr[mid];
  int x = left;
  int y = right;
  while (1) {
    while (x < right && arr[x] <= pivot) {
      x++;
    }
    while (y > left && arr[y] > pivot) {
      y--;
    }
    if (x >= y) {
      break;
    }
    swap(arr + x, arr + y);
    x++;
    y--;
  }
  int border = y;
  *j = x;
  x = left;
  while (1) {
    while (x < border && arr[x] < pivot) {
      x++;
    }
    while (y > left && arr[y] == pivot) {
      y--;
    }
    if (x >= y) {
      break;
    }
    swap(arr + x, arr + y);
    x++;
    y--;
  }
  *i = y;
}

void quicksort(int arr[], int left, int right) {
  if (right - left == 0) {
    return;
  }
  int i, j;
  partition(arr, left, right, &i, &j);
  quicksort(arr, left, i);
  quicksort(arr, j, right);
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}