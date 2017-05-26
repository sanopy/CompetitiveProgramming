#include <iostream>
using namespace std;

int days_of_month(int y, int m) {
  if (y % 3 == 0)
    return 20;
  else if (m % 2 == 1)
    return 20;
  else
    return 19;
}

int main(void) {
  int n;
  cin >> n;
  while (n--) {
    int Y, M, D;
    cin >> Y >> M >> D;
    int days = days_of_month(Y, M) - D + 1;
    for (int y = Y; y < 1000; y++) {
      for (int m = y==Y ? M+1 : 1; m <= 10; m++) {
        days += days_of_month(y, m);
      }
    }
    cout << days << endl;
  }
}
