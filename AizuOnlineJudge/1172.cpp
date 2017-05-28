#include <iostream>
using namespace std;

#define N 123456

bool prime[(N+1)*2];
int main(void) {
  prime[0] = prime[1] = true;
  for (int i = 2; i*i <= 2*N; i++) {
    if (!prime[i]) {
      for (int j = 2; i*j <= 2*N; j++) {
        prime[i*j] = true;
      }
    }
  }

  int n;
  while(cin >> n, n) {
    int ret = 0;
    for (int i = n+1; i <= 2*n; i++) {
      if (!prime[i])
        ret++;
    }
    cout << ret << endl;
  }

  return 0;
}
