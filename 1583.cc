#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, int> m;
map<string, int>::iterator it;

int main() {
  int i, len, max = 0, time;
  string word, tmp;
  bool flag;
  while (cin >> word) {
    len = word.length();
    tmp.clear();
    flag = false;
    for (i = 0; i < len; i++) {
      if (isalpha(word[i])) {
        word[i] = tolower(word[i]);
        tmp.push_back(word[i]);
        flag = false;
      } else {
        time = ++m[tmp];
        flag = true;
        if (time > max) max = time;
        tmp.clear();
      }
    }
    if (!flag) {
      time = ++m[tmp];
      if (time > max) max = time;
    }
  }
  cout << max << " occurrences" << endl;
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second == max) cout << it->first << endl;
  }
}
