#include <vector>
#include <iostream>

using namespace std;

const uint INF = (uint)(1<<31) - 1;

class RMQ {
  int N;
  vector<uint> dat;

  uint query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return dat[k];
    uint vl = this->query(a, b, k * 2 + 1, l, (l + r) / 2);
    uint vr = this->query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

public:
  RMQ(int n) {
    N = 1;
    while(N < n)
      N *= 2;
    dat.clear();
    dat.resize(2 * N - 1, INF);
  }

  void update(int i, uint x) {
    i += N - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  uint query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
};

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  RMQ r(n);
  for (int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0)
      r.update(x, y);
    else
      cout << r.query(x, ++y) << endl;
  }
}
