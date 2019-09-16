/*Jump Search implemented on array of user-defined data with a key */

#include <math.h>
#include <stdio.h>

#define MAX_SIZE 100000

// Generic Data with key for search purpose if only one element is present that
// becomes the key.
struct data {
  int key;
};

/* Function to jump search an element in array.
   The idea of jump search is search in intervals of sorted array for the key,
   first 0 index is searched then m index then 2m, 3m .. this ways it goes on
   until we find a range where arr[xm].key < key and arr[(x+1)m].key >= key In
   such a case our key must be in that range and then we cxan apply linear
   search on it.
*/

int jump_search(struct data arr[], int size, int key) {
  int m = sqrt(size);
  int l = 0;
  int r = m;
  while (arr[r - 1].key < key) {
    l = r;
    if (r < size && r + m > size) {
      r = size;
    } else {
      r += m;
    }
    if (r > size) {
      return -1;
    }
  }
  while (arr[l].key < key) {
    l++;
    if (l >= r) {
      return -1;
    }
  }
  return l;
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
  int result = jump_search(arr, size, key);  // Function Call
  if (result == -1) {
    printf("Key not found");
  } else {
    printf("Key was found in %d position", result + 1);
  }
  return 0;
}
