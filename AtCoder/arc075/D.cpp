#include <cstdio>

inline bool enough(int n, int a, int b, int *h, int times) {
  int damage = ((long long)b * times > 1e9) ? 1e9: b * times;
  for (int i = 0; i < n; i++) {
    if (h[i] > damage)
      times -= (h[i]-damage) / (a-b) + (((h[i]-damage) % (a-b)) ? 1: 0);
    if (times < 0)
      return false;
  }
  return true;
}

int main(void) {
  int n, a, b;
  int h[100000];

  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++)
    scanf("%d", h+i);

  int head = 0, tail = 1e9;
  while (head < tail) {
    int mid = (head + tail) / 2;
    if (enough(n, a, b, h, mid))
      tail = mid;
    else
      head = mid + 1;
  }

  printf("%d\n", head);
}