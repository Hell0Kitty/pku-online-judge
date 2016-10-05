#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, p = 1;
  while (cin >> n, n) {
    vector<pair<int, int> > v;
    cout << "Genome " << p << endl;
    int r;
    cin >> r;
    while (r--) {
      int x, y;
      cin >> x >> y;
      v.push_back(make_pair(x, y));
    }
    int q;
    cin >> q;
    while (q--) {
      int x;
      cin >> x;
      int pos = x;
      for (int i = 0; i < v.size(); i++)
        if (pos <= v[i].second && pos >= v[i].first)
          pos = v[i].first + v[i].second - pos;
      cout << pos << endl;
    }
    p++;
  }

  return 0;
}
