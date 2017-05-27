#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
  long long n, a, b;
  cin >> n >> a >> b;

  if (a > b)
    cout << 0 << endl;
  else {
    long long l = b + (n-1) * a;
    long long h = a + (n-1) * b;
    cout << max(0LL, h-l+1) << endl;
  }
}
