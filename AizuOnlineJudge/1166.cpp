#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> Pi;
typedef pair<Pi, int> Pii;

int w, h;
int ver[64][64], hor[64][64];

int bfs() {
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, 1, -1};
  bool used[64][64];
  queue<Pii> que;
  que.push(make_pair(make_pair(0, 0), 1)); // ((x, y), step)
  memset(used, false, sizeof(used));

  while (que.size()) {
    Pii p = que.front(); que.pop();
    int x = p.first.first, y = p.first.second, step = p.second;
    if (x == w-1 && y == h-1)
      return step;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h)
        continue;
      if (x != nx && ver[y][min(x, nx)] == 1)
        continue;
      if (y != ny && hor[min(y, ny)][x] == 1)
        continue;
      if (used[ny][nx])
        continue;
      used[ny][nx] = true;
      que.push(make_pair(make_pair(nx, ny), step+1));
    }
  }

  return 0;
}

int main(void) {
  for ( ; ; ) {
    scanf("%d %d", &w, &h);
    if (w + h == 0)
      break;
    for (int i = 0; i < h-1; i++) {
      for (int j = 0; j < w-1; j++)
        scanf("%d", ver[i]+j);
      for (int j = 0; j < w; j++)
        scanf("%d", hor[i]+j);
    }
    for (int j = 0; j < w-1; j++)
      scanf("%d", ver[h-1]+j);

    printf("%d\n", bfs());
  }
}