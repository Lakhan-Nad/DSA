/*Linear Search implemented on array of user-defined data with a key */

#include <stdio.h>

#define MAX_SIZE 100000

// Generic Data with key for search purpose if only one element is present that
// becomes the key.
struct data {
  int key;
};

/* Function to linear search an element in array
   Array is sequentialy searched for matching element until array ends or key is
   found.
*/

int linear_search(struct data arr[], int l, int r, int key) {
  if (l > r) {  // Check if array size is positive
    return -1;
  } else if (arr[l].key == key) {
    return l;
  } else if (arr[r].key == key) {
    return r;
  } else {
    return linear_search(arr, l + 1, r - 1, key);  // Recursive Call
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
  printf("Enter elements\n");
  for (i = 0; i < size; i++) {  // Take array input only key is taken input here
    scanf("%d", &arr[i].key);
  }
  printf("Enter key you want to search: ");
  scanf("%d", &key);
  int result = linear_search(arr, 0, size - 1, key);  // Function Call
  if (result == -1) {
    printf("Key not found");
  } else {
    printf("Key was found in %d position", result + 1);
  }
  return 0;
}
