#include <stdio.h>

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int max1 = -1;
  int max2 = -1;
  int temp;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max2) {
      max2 = arr[i];
    }
    if (max2 > max1) {
      swap(&max1, &max2);
    }
  }
  long max_product = (long)max1 * (long)max2;
}