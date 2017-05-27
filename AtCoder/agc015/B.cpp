#include <iostream>
#include <string>
using namespace std;
int main(void) {
  string s;
  cin >> s;
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U')
      ans += i*2 + s.size()-1-i;
    else
      ans += i + (s.size()-1-i) * 2;
  }
  cout << ans << endl;
}
