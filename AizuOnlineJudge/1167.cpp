#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp1[1000001], dp2[1000001];
int solve(vector<int> const& v, int n, int dp[]) {
  for (int i = 0; i <= n; i++)
    dp[i] = i;
  for (int i = 0; i < v.size(); i++) {
    for (int j = v[i]; j <= n; j++) {
      dp[j] = min(dp[j], dp[j-v[i]] + 1);
    }
  }
  return dp[n];
}

int main(void) {
  vector<int> tetra, tetra_odd;

  for (int i = 1; ; i++) {
    int t = (i*(i+1)*(i+2) / 6);
    if (t > 1000000)
      break;
    tetra.push_back(t);
    if (t % 2 == 1)
      tetra_odd.push_back(t);
  }

  solve(tetra, 1000000, dp1);
  solve(tetra_odd, 1000000, dp2);

  int n;
  while (cin >> n, n) {
    cout << dp1[n] << ' ' << dp2[n] << endl;
  }

  return 0;
}
