#include <iostream>
using namespace std;

void printParenthesses(int i, int open, string s) {
  if (i == 0 && open == 0) {
    cout << s << endl;
    return;
  }
  if (i == 0 || open < 0)
    return;

  printParenthesses(i - 1, open + 1, s + '(');
  printParenthesses(i - 1, open - 1, s + ')');
}

int main(void) {
  int N;
  cin >> N;

  printParenthesses(N, 0, "");
}
