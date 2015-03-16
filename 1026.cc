#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N = 210;
int a[N], mod[N];
char str[N], ans[N];

int main() {
  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      ans[i] = ' ';
    }
    ans[n] = '\0';
    for (int i = 0; i < n; i++) {
      int key = i + 1, len = 0;
      while (1) {
        len++;
        key = a[key - 1];
        if (key == i + 1) break;
      }
      mod[i] = len;
      // cout<<mod[i]<<endl;
    }
    int k;
    while (cin >> k && k) {
      getchar();
      gets(str);
      // cout<<str<<endl;
      for (int i = 0; i < n; i++) ans[i] = ' ';
      ans[n] = '\0';
      int len = strlen(str);
      for (int i = 0; i < len; i++) {
        if (str[i] == ' ') continue;
        int temp = k % mod[i];
        // cout<<mod[i]<<" ";
        int pos = i + 1;
        for (int j = 0; j < temp; j++) {
          pos = a[pos - 1];
        }
        ans[pos - 1] = str[i];
      }
      cout << ans << endl;
    }
    cout << endl;
  }
  return 0;
}
