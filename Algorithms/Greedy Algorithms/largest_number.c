/* As the last question of a successful interview, your boss gives you a few
pieces of paper with numbers on it and asks you to compose a largest number from
these numbers. The resulting number is going to be your salary, so you are very
much interested in maximizing this number.
*/

#include <stdio.h>

int count(int a) {
  int x = 1;
  while (a > 0) {
    x *= 10;
    a /= 10;
  }
  return x;
}

int greater(int a, int b) {
  int num1 = a * count(b) + b;
  int num2 = b * count(a) + a;
  return num1 < num2;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (greater(arr[j], arr[j + 1])) {
        swap(arr + j, arr + j + 1);
      }
    }
  }
}

void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  sort(arr, n);
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }
  // printf("\n");
  //   printf("%d", greater(23, 2));
}