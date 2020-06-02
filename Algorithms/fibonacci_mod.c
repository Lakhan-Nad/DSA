/* Calculate Fn%m where Fn is nth fibonacci number and m is any integer

    tl;dr: F(modm) is periodic.
           This is a natural consequence of the following two statements:
           Modulo m, there are m^2 possible pairs of residues, and hence some
   pair of consecutive terms of F(modm) must repeat. Any pair of consecutive
   terms of F(mod m) determines the entire sequence both forward and backward.

    The logic used to solve this problem is just observation.
    We can have m different values of x%m from 0 to m-1 for any value of x.
    Now we know Fn = Fn-1 + Fn-2
    Since Fn is sum of last two terms every term in fibonacci series can be
   represented by a pair of two terms (last two terms whose sum is current
   number) except the first two tems of series F1 i.e. 0 and F2 i.e. 1 Now for
   Fn%m every term is an integer in range 0 to m-1 and every term can be
   represented as a pair of two terms (Even 0 as [0,0] and 1 as [0,1]) now if we
   produce the series of Fn%m where n is a very large number, since any term is
   sum of last two when a xth term is calculated it will be Fx-1 + Fx-2, but if
   x is greater than or equal to m^2 then we must have seen all possible
    placements of (a,b) where a, b E (0 to m-1) terms except (0,0) in the series
   till now. So the current last two terms that is Fx-1, Fx must have previously
   occured in series previouly also Now the next term in series is (Fx-1 + Fx)
   and the next is (Fx+Fx+1) which shall repeat itself. Hence a period is
   formed.
   This can prove that a maximum length of Pisano period is m^2 - 1.
   This period always starts repeating at 0,1. The proof can be given by a
   simple argument Any pair always detrmine the whole sequence both forwars and
   backward. So if cycle would have started at anywher in between two pair.Then
   this would mean that we would have already got a recurring element.
*/

#include <stdio.h>

long long pisanoPeriod(long long n) {
  long long a = 0;
  long long b = 1;
  long long c;
  long long i;
  for (i = 3; i < n * n; i++) {
    c = (a + b) % n;
    a = b;
    b = c;
    if (b == 1 && a == n - 1) {
      break;
    }
  }
  return i;
}

long long fibannociModM(long long n, long long m) {
  if (m <= 0)
    return -1;
  else if (m == 1)
    return 0;
  long long p = pisanoPeriod(m);
  long long z = (int)(n % (long long)p);
  if (z == 0) return 0;  // Always Pisano Period ends with 1 :)
  long long a = 0;
  long long b = 1;
  long long c;
  for (long long i = 2; i <= z; i++) {
    c = (a + b) % m;
    a = b;
    b = c;
  }
  return c;
}

int main() {
  long long n;
  long long m;
  scanf("%lld %lld", &n, &m);
  long long result = fibannociModM(n, m);
  printf("%lld", result);
}
