#include <stdio.h>

void max_heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }
  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }
  if (largest != i) {
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    max_heapify(arr, n, largest);
  }
}

void min_heapify(int arr[], int n, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  if (left < n && arr[left] < arr[smallest]) {
    smallest = left;
  }
  if (right < n && arr[right] < arr[smallest]) {
    smallest = right;
  }
  if (smallest != i) {
    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
    min_heapify(arr, n, smallest);
  }
}

void heapSort(int arr[], int n, int reverse) {
  int i, temp;
  for (i = n / 2; i >= 0; i--) {
    if (reverse) {
      min_heapify(arr, n, i);
    } else {
      max_heapify(arr, n, i);
    }
  }
  for (i = n - 1; i >= 0; i--) {
    temp = arr[i];
    arr[i] = arr[0];
    arr[0] = temp;
    if (reverse) {
      min_heapify(arr, i, 0);
    } else {
      max_heapify(arr, i, 0);
    }
  }
}

void printArray(int arr[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void main() {
  int n;
  int arr[] = {2, 4, 1, 6, 343, 13, 35, 352, 35};
  n = sizeof(arr) / sizeof(arr[0]);
  heapSort(arr, n, 0);
  printArray(arr, n);
  heapSort(arr, n, 1);
  printArray(arr, n);
}