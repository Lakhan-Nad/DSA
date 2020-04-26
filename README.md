# Basic Programmes for better understanding of Data Structures and Algorithms

## Template for CP

```c
#include <stdio.h>

/* Impement as testcase{ body for each testcase} */
#define testcase     \
  long long t;       \
  scanf("%lld", &t); \
  for (long long i = 0; i < t; i++)

/* 10^9 + 7 - Most Commonly Used Value */

#define MOD 1000000007

/* I/O Methods */

#define rd(t) scanf("%d", &t)      // int
#define rld(t) scanf("%ld", &t)    // long
#define rlld(t) scanf("%lld", &t)  // long long
#define rc(c) scanf("%c", &c)      // char
#define rs(s) scanf("%s", s)       // char[]
#define nl printf("\n")            // New Line
#define ns printf(" ");            // Space
#define pd(t) printf("%d", t)
#define pld(t) printf("%ld", t)
#define plld(t) printf("%lld", t)
#define pc(c) printf("%c", c)
#define ps(s) printf("%s", s)

#define ll long long  // Shorthand

/* LOOPS Shorthand */
#define REP(i, n) for (long long i = 0; i < n; i++)
#define REPD(i, n) for (long long i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (long long i = a; i < b; i++)
#define FORD(i, a, b) for (long long i = b; i >= a; i--)

/* Useful Functions */

/* Iterative Binary Exponentiation */
// Default Modulo is assumed to be 10^17
ll fastExp(ll a, ll b, ll mod = 1e17) {
  ll result = 1;
  while (b > 0) {
    if (b & 1) {
      result *= a;
      result %= mod;
    }
    a = (a * a)%mod;
    b /= 2;
  }
  return result;
}

/* Extended GCD algo ax + by = gcd(a,b) */
ll extGCD(ll a, ll m, ll &x, ll &y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return m;
  }
  ll x1, y1;
  ll g = extGCD(m % a, a, x1, y1);
  x = y1 - (m / a) * x1;
  y = x1;
  return g;
}

/* EUCLIDEAN GCD METHOD */
ll gcd(ll a, ll b) {
  ll g = a > b ? a : b;
  ll d = a + b - g;
  ll temp;
  while (g % d) {
    temp = g % d;
    g = d;
    d = temp;
  }
  return d;
}

/* LCM of two Numbers */
// LCM(a,b) = (a*b)/gcd(a,b)
ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

/* Function To Find If a Number is Prime */
// Returns 1 for true 0 for False
// To make compatible with c also
ll isPrime(ll a) {
  for (ll i = 2; i * i <= a; i++)
    if (a % i == 0) {
      return 0;
    }
  return 1;
}

/* Fermats Last Theorem for invModulo */
// Condition is M must be a prime number
// Recommended for Prime Numbers
ll fInvMod(ll a, ll mod) {
  ll x = fastExp(a, mod - 2, mod);
  return x % mod;
}

/* Modulo Inverse for any Number */
// Uses Extended Euclidean Algo
ll invMod(ll a, ll mod) {
  ll x, y;
  ll g = extGCD(a, mod, x, y);
  if (g != 1) {
    return -1;
  } else {
    return ((x + mod) % mod);
  }
}
```
