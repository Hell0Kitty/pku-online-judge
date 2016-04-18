#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
  char s1[1001], s2[1001];
  int l1, l2, i, j, k;
  while (gets(s1)) {
    gets(s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    sort(s1, s1 + l1);
    sort(s2, s2 + l2);
    k = 0;
    for (i = 0; s1[i] != 0; i++) {
      for (j = k; s2[j] != 0; j++)
        if (s1[i] == s2[j]) {
          printf("%c", s1[i]);
          s2[j] = '*';
          k = j;
          break;
        }
    }
    cout << endl;
  }
}
