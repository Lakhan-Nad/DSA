/* You have n ads to place on a popular Internet page. For each ad, you know how
much is the advertiser willing to pay for one click on this ad. You have set up
n slots on your page and estimated the expected number of clicks per day for
each slot. Now, your goal is to distribute the ads among the slots to maximize
the total revenue.
*/

#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr + j, arr + j + 1);
      }
    }
  }
}

void main() {
  int n;
  scanf("%d", &n);
  int aarr[n];
  int barr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", aarr + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", barr + i);
  }
  sort(aarr, n);
  sort(barr, n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (long long)aarr[i] * (long long)barr[i];
  }
  printf("%lld", ans);
}