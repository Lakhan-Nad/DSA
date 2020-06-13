/* Given n, the amount of money find minimum coins in denominations 1,3,4 to
make up n */

#include <stdio.h>
#define Infinity 100000000

int min(int a, int b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}

int calcMinimumCoins(int arr[], int n, int money) {
  int temp[money + 1];
  temp[0] = 0;
  for (int i = 1; i <= money; i++) {
    int smallest = Infinity;
    for (int j = 0; j < n; j++) {
      if (i >= arr[j]) {
        smallest = min(smallest, temp[i - arr[j]] + 1);
      }
    }
    temp[i] = smallest;
  }
  return temp[money];
}

void main() {
  int n;
  scanf("%d", &n);
  int noOfDenominations = 3;
  int denominations[] = {1, 3, 4};
  int ans = calcMinimumCoins(denominations, noOfDenominations, n);
  printf("%d", ans);
}