#include <vector>

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
