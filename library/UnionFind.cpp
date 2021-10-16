#include <vector>

using namespace std;

class UnionFind {
private:
  vector<int> parent;
  vector<int> rank;

public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int root(int x) {
    if (parent[x] == x)
      return x;
    else
      return parent[x] = root(parent[x]);
  }

  void unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y)
      return;

    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y])
        rank[x]++;
    }
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }
};
