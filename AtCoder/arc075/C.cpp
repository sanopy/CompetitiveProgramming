#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
  int n, s[128], sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    sum += s[i];
  }
  sort(s, s+n);
  int i = 0, ret = sum;
  while (ret % 10 == 0 && i < n) {
    if (s[i] % 10 != 0)
      ret -= s[i];
    i++;
  }
  cout << (ret % 10 == 0 ? 0 : ret) << endl;
}
