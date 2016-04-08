#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;
int main() {
  string s, buf;
  int i, f, n, num = 0;
  while (cin >> n) {
    f = 0;
    map<string, int> mp;
    while (cin >> s && s != "EndOfText") {
      for (i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
          s[i] = tolower(s[i]);
        } else {
          s[i] = ' ';
        }
      }
      stringstream ss(s);
      while (ss >> buf) {
        mp[buf]++;
      }
    }
    if (num != 0) {
      cout << endl;
    }
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
      if (it->second == n) {
        cout << it->first << endl;
        f = 1;
      }
    }
    if (f == 0) {
      cout << "There is no such word." << endl;
    }
    num++;
  }
}
