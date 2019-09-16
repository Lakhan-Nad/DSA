/*Binary Search implemented on array of user-defined data with a key */

#include <stdio.h>

#define MAX_SIZE 100000

// Generic Data with key for search purpose if only one element is present that
// becomes the key.
struct data {
  int key;
};

/* Function to binary search an element in array.
   Binary search is applied on sorted arrays.
   Key is always searched in middle element of array, if key is found its
   position is returned, else array is divided in half and search continue
   either in left half or right half depending on weather element is less than
   middle element or greater than it.
*/

int binary_search(struct data arr[], int l, int r, int key) {
  if (l > r) {
    return -1;
  }
  int mid = l + (r - l) / 2;
  if (arr[mid].key == key) {
    return mid;
  } else if (arr[mid].key > key) {
    return binary_search(arr, l, mid - 1, key);
  } else {
    return binary_search(arr, mid + 1, r, key);
  }
}

int main() {  // Driver Code
  int size, i, key;
  struct data arr[MAX_SIZE];
  printf("Enter size of array: ");
  scanf("%d", &size);
  if (size < 0 || size > MAX_SIZE) {  // Check size
    printf("Not a valid array size");
    return 0;
  }
  printf("Enter elements in sorted order\n");
  for (i = 0; i < size; i++) {  // Take array input only key is taken input here
    scanf("%d", &arr[i].key);
  }
  printf("Enter key you want to search: ");
  scanf("%d", &key);
  int result = binary_search(arr, 0, size - 1, key);  // Function Call
  if (result == -1) {
    printf("Key not found");
  } else {
    printf("Key was found in %d position", result + 1);
  }
  return 0;
}
