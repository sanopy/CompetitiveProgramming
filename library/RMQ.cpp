#include <vector>

using namespace std;

template<class T>class RMQ {
  int N;
  T INF;
  vector<T> dat;

  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return dat[k];
    T vl = this->query(a, b, k * 2 + 1, l, (l + r) / 2);
    T vr = this->query(a, b, k * 2 + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

public:
  RMQ(int n, T inf) {
    INF = inf;
    N = 1;
    while(N < n)
      N *= 2;
    dat.resize(2 * N - 1, INF);
  }

  void update(int i, T x) {
    i += N - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;
      dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }

  T query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
};
