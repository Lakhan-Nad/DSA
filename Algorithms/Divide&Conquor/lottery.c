/* You are organizing an online lottery. To participate, a person bets on a
single integer. You then draw several ranges of consecutive integers at random.
A participant’s payoff then is proportional to the number of ranges that
contain the participant’s number minus the number of ranges that does not
contain it. You need an efficient algorithm for computing the payoffs for all
participants. A naive way to do this is to simply scan, for all participants,
the list of all ranges. However, you lottery is very popular: you have thousands
of participants and thousands of ranges. For this reason, you cannot afford
a slow naive algorithm.
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
  if (*(int *)(a + 0) != *(int *)(b + 0)) {
    return (*(int *)(a + 0) - *(int *)(b + 0));
  } else {
    return (*(int *)(a + 1) - *(int *)(b + 1));
  }
}

void main() {
  int arr[200000][3];
  int ans[200000];
  int s, p;
  scanf("%d", &s);
  scanf("%d", &p);
  int i;
  for (i = 0; i < 2 * s; i += 2) {
    scanf("%d", &arr[i][0]);
    arr[i][1] = 0;
    scanf("%d", &arr[i + 1][0]);
    arr[i + 1][1] = 2;
  }
  int t = 0;
  for (; i < 2 * s + p; i++) {
    scanf("%d", &arr[i][0]);
    arr[i][1] = 1;
    arr[i][2] = t;
    t++;
  }
  qsort(arr, 2 * s + p, sizeof(int) * 3, cmp);
  int count = 0;
  for (int i = 0; i < 2 * s + p; i++) {
    if (arr[i][1] == 0)
      count++;
    else if (arr[i][1] == 2)
      count--;
    else
      ans[arr[i][2]] = count;
  }
  for (int i = 0; i < t; i++) {
    printf("%d ", ans[i]);
  }
}