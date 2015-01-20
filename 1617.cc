#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int i, j, len1, len2;
  string keyword, ciphertext, ans, tmp1, tmp2, order, div[100];
  while (cin >> keyword) {
    if (keyword == "THEEND") break;
    cin >> ciphertext;
    order.clear();
    ans.clear();
    tmp1 = tmp2 = keyword;
    len1 = keyword.length();
    len2 = ciphertext.length();
    sort(tmp1.begin(), tmp1.end());
    //这个序列号的得到需要很好的理解，要不就很难得出正确的结果！
    for (i = 0; i < len1; i++) {
      for (j = 0; j < len1; j++) {
        if (tmp1[j] == tmp2[i]) {
          order.push_back(j + 48);
          tmp1[j] = '0';
          break;
        }
      }
    }
    for (i = 0; i < 100; i++) div[i].clear();
    for (i = 0, j = -1; i < len2; i++) {
      if (i % (len2 / len1) == 0) j++;
      div[j].push_back(ciphertext[i]);
    }
    for (i = 0; i < len2 / len1; i++)
      for (j = 0; j < order.length(); j++) {
        ans.push_back(div[order[j] - 48][i]);
      }

    cout << ans << endl;
  }
}
