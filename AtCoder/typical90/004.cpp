#include <iostream>
#include <vector>
using namespace std;

int A[2000][2000], B[2000][2000];
int row[2000], col[2000];

int main(void) {
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      cin >> A[i][j];

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      row[i] += A[i][j], col[j] += A[i][j];

  for (int i = 0; i < H; i++) {
    cout << row[i] + col[0] - A[i][0];
    for (int j = 1; j < W; j++)
      cout << ' ' << row[i] + col[j] - A[i][j];
    cout << endl;
  }
}
