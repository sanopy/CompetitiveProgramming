#include <iostream>

using namespace std;

int gcd(int x, int y) {
  if (x % y == 0)
    return y;
  else
    return gcd(y, x % y);
}

int main(void) {
  long long a, b;
  while (cin >> a >> b) {
    int _gcd = gcd(a, b);
    int _lcm = (a * b) / _gcd;
    cout << _gcd << ' ' << _lcm << endl;
  }
}
