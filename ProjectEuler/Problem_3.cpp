#include <cstdio>
#include <cmath>
#include <stack>
using namespace std;

#define N 600851475143LL
#define SQRT_N 775146

bool num[SQRT_N+1];
stack<long long> prime;

int main(void) {
  for (long long i = 2; i <= SQRT_N; i++) {
    if (!num[i]) {
      prime.push(i);
      for (long long j = 2; i*j <= SQRT_N; j++) {
        num[i*j] = true;
      }
    }
  }

  while (true) {
    long long p = prime.top(); prime.pop();
    if (N % p == 0) {
      printf("%lld\n", p);
      break;
    }
  }
}
