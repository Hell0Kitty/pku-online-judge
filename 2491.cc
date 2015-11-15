#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, string> ssmap;
map<string, int> simap;

int main() {
  int count;
  cin >> count;
  for (int i = 1; i <= count; i++) {
    ssmap.clear();
    simap.clear();
    vector<string> vs;
    int stepNum;
    cin >> stepNum;
    string str1, str2;
    for (int j = 0; j < stepNum - 1; j++) {
      cin >> str1 >> str2;
      ssmap[str1] = str2;
      simap[str1]++;
      simap[str2]++;
    }
    string head_tail[2];
    int k = 0;
    for (map<string, int>::iterator it = simap.begin(); it != simap.end();
         it++) {
      if (it->second == 1) {
        head_tail[k++] = it->first;
      }
    }
    string head;
    for (int j = 0; j < 2; j++) {
      if (ssmap[head_tail[j]].size() == 0) {
        head = head_tail[1 - j];
      }
    }
    cout << "Scenario #" << i << ":" << endl
         << head << endl;
    while (ssmap[head].size() != 0) {
      cout << ssmap[head] << endl;
      head = ssmap[head];
    }
    cout << endl;
  }
}