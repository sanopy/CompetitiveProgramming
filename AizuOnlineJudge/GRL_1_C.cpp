#include <iostream>
using namespace std;

const long long INF = 1LL<<50;
long long **d;
void init(int V) {
  d = new long long* [V];
  for (int i = 0; i < V; i++) {
    d[i] = new long long [V];
    for (int j = 0; j < V; j++)
      d[i][j] = i == j ? 0 : INF;
  }
}

void WarshallFloyd(int V) {
  for (int k = 0; k < V; k++)
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        if (d[i][k] != INF && d[k][j] != INF)
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void terminate(int V) {
  for (int i = 0; i < V; i++)
    delete d[i];
  delete d;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;

  init(V);

  // input costs
  for (int i = 0; i < E; i++) {
    int s, t, c;
    cin >> s >> t >> c;
    d[s][t] = c;
  }

  WarshallFloyd(V);

  for (int i = 0; i < V; i++) {
    if (d[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      terminate(V);
      return 0;
    }
  }

  for (int i = 0; i < V; i++) {
    if (d[i][0] == INF)
      cout << "INF";
    else
      cout << d[i][0];
    for (int j = 1; j < V; j++)
      if (d[i][j] == INF)
        cout << " INF";
      else
        cout << ' ' << d[i][j];
    cout << endl;
  }

  terminate(V);
}
