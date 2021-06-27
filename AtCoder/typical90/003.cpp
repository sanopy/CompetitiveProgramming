#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int INF = 1<<28;

int N;
vector<vector<int>> G;
vector<bool> visited;

pair<int, int> dist(int node) {
  if (visited[node])
    return {-INF, 0};

  int res = 0, farthest = node;
  visited[node] = true;
  for (uint i = 0; i < G[node].size(); i++) {
    auto d = dist(G[node][i]);
    if (res < d.first + 1)
      res = d.first + 1, farthest = d.second;
  }
  visited[node] = false;

  return {res, farthest};
}

int main(void) {
  int N;
  cin >> N;

  G.resize(N+1);
  for (int i = 0; i < N-1; i++) {
    int A, B;
    cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  visited.resize(N+1, false);
  const int farthest = dist(1).second;
  cout << dist(farthest).first + 1 << endl;
}
