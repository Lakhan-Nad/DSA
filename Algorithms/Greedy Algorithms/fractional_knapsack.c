/* Given n items with value vi and weight wi and total weight W
    Find the fractional value of each item to attain maximum value */

#include <stdio.h>

void swap(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

double min(double a, double b) {
  if (a > b)
    return b;
  else
    return a;
}

void sort(double arr[], double same[], int len) {
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        swap(arr + j, arr + j + 1);
        swap(same + j, same + j + 1);
      }
    }
  }
}

void main() {
  int n;
  double weight;
  scanf("%d %lf", &n, &weight);
  double weights[n];
  double ratios[n];
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", ratios + i, weights + i);
    ratios[i] /= weights[i];
  }
  sort(ratios, weights, n);
  int current = 0;
  double w;
  double total = 0;
  while (current < n && weight > 0) {
    w = min(weight, weights[current]);
    total += ratios[current] * w;
    weight -= w;
    current++;
  }
  printf("%lf\n", total);
}