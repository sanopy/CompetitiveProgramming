#include <iostream>
#include <deque>

using namespace std;

int N, L, K;
deque<int> A;

bool canDivide(int score) {
  int l = 0, cnt = 0;

  for (uint i = 1; i < A.size(); i++) {
    int d = A[i] - A[i-1];
    if (l + d >= score)
      l = 0, cnt++;
    else
      l += d;
  }
  if (l < score)
    cnt--;

  if (cnt >= K)
    return true;
  else
    return false;
}

int main(void) {
  cin >> N >> L >> K;
  A.resize(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  A.push_front(0);
  A.push_back(L);

  int head = 0, tail = L;
  while (tail - head > 1) {
    int mid = (head + tail) / 2;
    if (canDivide(mid))
      head = mid;
    else
      tail = mid;
  }

  cout << head << endl;
}
