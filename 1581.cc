#include <iostream>
#include <string>
using namespace std;

int n, winprob, winpoint, nowprob, nowpoint;
string winname, nowname;

int main() {
  int i, a, b, j;

  cin >> n;
  winprob = -1;
  for (i = 0; i < n; i++) {
    cin >> nowname;
    nowprob = 0;
    nowpoint = 0;
    for (j = 0; j < 4; j++) {
      cin >> a >> b;
      if (b > 0) {
        nowprob++;
        nowpoint = nowpoint + b + (a - 1) * 20;
      }
      if (nowprob > winprob || (nowprob == winprob && nowpoint < winpoint)) {
        winname = nowname;
        winprob = nowprob;
        winpoint = nowpoint;
      }
    }
  }
  cout << winname << " " << winprob << " " << winpoint << endl;
  return 0;
}
