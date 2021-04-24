#include <iostream>

using namespace std;

int n, s;
int solve(int i, int j, int sum) {
  if (i == n && sum == s)
    return 1;
  else if (i >= n || j > 9 || sum > s)
    return 0;
  else
    return solve(i + 1, j + 1, sum + j) + solve(i, j + 1, sum);
}

int main(void) {
  for ( ; ; ) {
    cin >> n >> s;
    if (n == 0 && s == 0)
      break;
    cout << solve(0, 0, 0) << endl;
  }
}
