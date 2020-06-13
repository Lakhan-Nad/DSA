/* In this problem, your goal is to add parentheses to a given arithmetic
expression to maximize its value.
*/

#include <stdio.h>
#include <string.h>

#define maxSymbols 200
#define maxNumbers 201
#define maxExpLen 40000

#define Inf 100000000
#define NInf -100000000

long long calculate(long long a, long long b, char op) {
  switch (op) {
    case '+':
      return (a + b);
    case '-':
      return (a - b);
    case '*':
      return (a * b);
    case '/':
      return (a / b);
    case '%':
      return (a % b);
    default:
      return 0;
  }
}

long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}

long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}

long long parenthesis(long long arr[], int numbers, char ops[]) {
  long long maxDP[numbers][numbers];
  long long minDP[numbers][numbers];
  for (int i = 0; i < numbers; i++) {
    for (int t = 0; t < numbers - i; t++) {
      int j = i + t;
      if (t == j) {
        maxDP[t][j] = arr[t];
        minDP[t][j] = arr[t];
      } else {
        long long minVal = Inf;
        long long maxVal = NInf;
        for (int k = t; k < j; k++) {
          long long a = calculate(minDP[t][k], minDP[k + 1][j], ops[k]);
          long long b = calculate(minDP[t][k], maxDP[k + 1][j], ops[k]);
          long long c = calculate(maxDP[t][k], minDP[k + 1][j], ops[k]);
          long long d = calculate(maxDP[t][k], maxDP[k + 1][j], ops[k]);
          minVal = min(minVal, a);
          minVal = min(minVal, b);
          minVal = min(minVal, c);
          minVal = min(minVal, d);
          maxVal = max(maxVal, a);
          maxVal = max(maxVal, b);
          maxVal = max(maxVal, c);
          maxVal = max(maxVal, d);
        }
        minDP[t][j] = minVal;
        maxDP[t][j] = maxVal;
      }
    }
  }
  return maxDP[0][numbers - 1];
}

void main() {
  long long arr[maxNumbers];
  char op[maxSymbols];
  long long temp = 0;
  char str[maxExpLen];
  scanf("%s", str);
  int len = strlen(str);
  int o = 0;
  int n = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      temp = temp * 10 + (str[i] - '0');
    } else {
      arr[n++] = temp;
      temp = 0;
      op[o++] = str[i];
    }
  }
  arr[n++] = temp;
  if (n - o != 1) {
    return;
  }
  long long maxValue = parenthesis(arr, n, op);
  printf("%lld", maxValue);
}