#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define MAGIC 1000000007
#define M 1010
#define N 102
int n, m;
typedef long long LL;
set<LL> hashpattern;
int occpattern[M][26];
LL hashresult[N];
string result[N];
string pattern[M];
vector<vector<pair<int, char> > > tail;

vector<pair<int, char> > get_tail(string resultj) {
  int occresultj[26] = {0};
  for (int i = 0; i < resultj.length(); i++) occresultj[resultj[i] - 'A']++;
  LL hashj = 0;
  for (int i = 0; i < resultj.length(); i++)
    hashj = hashj * MAGIC + (resultj[i] - 'A' + 1);

  vector<pair<int, char> > ret;
  for (char cand = 'A'; cand <= 'Z'; cand++) {
    int occ = 0;
    for (int i = 0; i < m; i++) {
      bool ok = true;
      for (char cmp = 'A'; cmp <= 'Z'; cmp++) {
        if (occpattern[i][cmp - 'A'] < occresultj[cmp - 'A'] + (cand == cmp)) {
          ok = false;
          break;
        }
      }
      if (ok) occ++;
    }
    ret.push_back(make_pair(occ, cand));
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> pattern[i];
    for (int j = 0; j < pattern[i].length(); j++)
      occpattern[i][pattern[i][j] - 'A']++;
    LL hash = 0;
    for (int j = 0; j < pattern[i].length(); j++)
      hash = hash * MAGIC + (pattern[i][j] - 'A' + 1);
    hashpattern.insert(hash);
  }
  result[0] = "";
  tail.push_back(get_tail(""));
  for (int i = 1; i <= n; i++) {
    int Mocc = -1, best = -1;
    for (int j = 0; j < i; j++) {
      while (!tail[j].empty()) {
        LL newhash = hashresult[j] * MAGIC + (tail[j].back().second - 'A' + 1);
        if (hashpattern.find(newhash) == hashpattern.end()) break;
        tail[j].pop_back();
      }
      if (!tail[j].empty() && tail[j].back().first > Mocc) {
        Mocc = tail[j].back().first;
        best = j;
      }
    }
    result[i] = result[best] + tail[best].back().second;
    hashresult[i] =
        hashresult[best] * MAGIC + (tail[best].back().second - 'A' + 1);
    tail.push_back(get_tail(result[i]));
    tail[best].pop_back();
    cout << result[i] << endl;
  }
}
