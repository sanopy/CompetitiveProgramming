#include <vector>
#include <iostream>

using namespace std;

template<class T> class BIT {
  vector<T> dat;

public:
  BIT(int n) {
    dat.resize(n + 1);
  }

  void add(int i, T x) {
    while (i <= dat.size()) {
      dat[i] += x;
      i += i & -i;
    }
  }

  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += dat[i];
      i -= i & -i;
    }
    return s;
  }

  T sum(int s, int t) {
    return sum(t) - sum(s-1);
  }
};

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;

  BIT<uint64_t> bit(n);
  for (int i = 0; i < q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0)
      bit.add(x, y);
    else
      cout << bit.sum(x, y) << endl;
  }
}
