/* Find pairwise maximum product of two numbers in array */
#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
/*
Find two maximum elements in array and take their product
Find two minimum elements in array and take their product

Print maximum of two products calculated above

The minimum elements is taken o handle -ve * -ve case
*/
void main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int max1 = INT_MIN;
  int max2 = INT_MIN;
  int min1 = INT_MAX;
  int min2 = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max2) {
      max2 = arr[i];
    }
    if (max2 > max1) {
      swap(&max1, &max2);
    }
    if(arr[i] < min2){
      min2 = arr[i];
    }
    if(min2 < min1){
      swap(&min2, &min1);
    }
  }
  long max_product = (long)max1 * (long)max2;
  long temp = (long)min1 * (long)min2;
  if(temp > max_product){
    max_product = temp;
  }
  printf("%ld", max_product);
}