#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
  int n, c;
  int l[100000];
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> l[i];

  sort(l, l+n);
  int head = 0, tail = n-1;
  int ans = 0;
  while (tail >= head) {
    ans++;
    if (tail == head) {
      break;
    } else if (l[tail] + l[head] < c) {
      head++; tail--;
    } else {
      tail--;
    }
  }

  cout << ans << endl;
}