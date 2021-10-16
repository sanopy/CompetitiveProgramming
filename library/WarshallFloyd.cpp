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
