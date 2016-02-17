#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int main() {
  int t = 0, T;
  scanf("%d", &T);
  while ((t++) < T) {
    char s1[150], s2[150], s3[310];
    int n;
    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    map<string, bool> book;
    int step = 0;
    while (true) {
      char s[310];
      int ps = 0;
      for (int i = 0; i < n; i++) {
        s[ps++] = s2[i];
        s[ps++] = s1[i];
      }
      s[ps] = '\0';
      step++;
      if (!strcmp(s, s3)) {
        printf("%d %d\n", t, step);
        break;
      }
      if (book[s] == true && strcmp(s, s3)) {
        printf("%d -1\n", t);
        break;
      }
      book[s] = true;
      for (int i = 0; i < n; i++) s1[i] = s[i];
      s1[n] = '\0';
      for (int i = n, j = 0; i < 2 * n; i++, j++) s2[j] = s[i];
      s2[n] = '\0';
    }
  }
  return 0;
}
