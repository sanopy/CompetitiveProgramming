#include <iostream>
#include <cmath>

using namespace std;

const int N_MAX = 1000000;
bool isPrime[N_MAX];

int main(void) {
  for (int i = 2; i < N_MAX; i++)
    isPrime[i] = true;

  int _sqrt = sqrt(N_MAX) + 1;
  for (int i = 2; i <= _sqrt; i++) {
    if (isPrime[i])
      for (int j = i + i; j < N_MAX; j += i)
        isPrime[j] = false;
  }

  int n;
  while (cin >> n) {
    int ans = 0;
    for (int i = 2; i <= n; i++)
      if (isPrime[i])
        ans++;
    cout << ans << endl;
  }
}
