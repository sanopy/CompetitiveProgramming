#include <stdio.h>

#define N 100
#define INF (1<<28)
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int triangle[N][N];
int memo[N+1][N+1];

int maximumPath(int x, int y) {
  if (memo[x][y])
    return memo[x][y];
  if (y >= N)
    return 0;
  if (x > y || y > N)
    return -INF;

  return memo[x][y] = MAX(maximumPath(x, y+1), maximumPath(x+1, y+1)) + triangle[y][x];
}

int main(void) {
  FILE *fp;

  fp = fopen("input/p067_triangle.txt", "r");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++)
      fscanf(fp, "%d", triangle[i] + j);
  }

  printf("%d\n", maximumPath(0, 0));

  return 0;
}