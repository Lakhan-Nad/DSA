/* Given n points in space. Find minimum distnce between any two points */

#include <stdio.h>
#include <stdlib.h>

double sqrt(double n) {
  double lo = 0, hi = n, mid;
  for (int i = 0; i < 1000; i++) {
    mid = (lo + hi) / 2;
    if (mid * mid == n) return mid;
    if (mid * mid > n)
      hi = mid;
    else
      lo = mid;
  }
  return mid;
}

double dabs(double __x) {
  if (__x >= 0)
    return __x;
  else
    return (-1.0 * __x);
}

#define maxDistance 200000.00

typedef struct Point {
  double x, y;
} Point;

int sortByX(const void *a, const void *b) {
  if (((Point *)a)->x != ((Point *)b)->x) {
    return ((Point *)a)->x - ((Point *)b)->x;
  } else {
    return ((Point *)a)->y - ((Point *)b)->y;
  }
}

int sortByY(const void *a, const void *b) {
  if (((Point *)a)->y != ((Point *)b)->y) {
    return ((Point *)a)->y - ((Point *)b)->y;
  } else {
    return ((Point *)a)->x - ((Point *)b)->x;
  }
}

double minOfTwo(double a, double b) {
  if (a < b)
    return a;
  else
    return b;
}

double calcDistance(const Point *a, const Point *b) {
  double dist = (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
  dist = sqrt(dist);
  return dist;
}

double basicCalc(Point arr[], int left, int right) {
  double dist = (double)maxDistance;
  for (int i = left; i < right; i++) {
    for (int j = i + 1; j <= right; j++) {
      dist = minOfTwo(dist, calcDistance(arr + i, arr + j));
    }
  }
  return dist;
}

void copy(Point *a, Point *b) {
  double x, y;
  x = b->x;
  y = b->y;
  a->x = x;
  a->y = y;
}

void mergebyY(Point arr[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;
  int size = right - left + 1;
  Point temp[size];
  while (i <= mid && j <= right) {
    if (arr[i].y <= arr[j].y) {
      copy(temp + k, arr + i);
      k++, i++;
    } else {
      copy(temp + k, arr + j);
      k++, j++;
    }
  }
  while (i <= mid) {
    copy(temp + k, arr + i);
    k++, i++;
  }
  while (j <= right) {
    copy(temp + k, arr + j);
    k++, j++;
  }
  k = 0;
  for (i = left; i <= right; i++) {
    copy(arr + i, temp + k);
    k++;
  }
}

double calcClosest(Point arr[], int left, int right) {
  if (right - left + 1 <= 3) {
    qsort(arr + left, right - left + 1, sizeof(Point), sortByY);
    return basicCalc(arr, left, right);
  }
  int mid = (left + right) / 2;
  double midX = arr[mid].x;
  double curMin =
      minOfTwo(calcClosest(arr, left, mid), calcClosest(arr, mid + 1, right));
  mergebyY(arr, left, mid, right);
  Point temp[right - left + 1];
  int k = 0;
  for (int i = left; i <= right; i++) {
    if (dabs(arr[i].x - midX) < curMin) {
      copy(temp + k, arr + i);
      k++;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = i + 1; j < k && (dabs(temp[j].y - temp[i].y) < curMin); j++) {
      curMin = minOfTwo(curMin, calcDistance(temp + i, temp + j));
    }
  }
  return curMin;
}

int main() {
  int n;
  scanf("%d", &n);
  Point arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &arr[i].x, &arr[i].y);
  }
  qsort(arr, n, sizeof(Point), sortByX);
  double min = calcClosest(arr, 0, n - 1);
  printf("%lf", min);
}