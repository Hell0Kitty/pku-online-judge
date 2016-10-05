#include <iostream>
#include <cstring>
using namespace std;
int data[51][27];
int map[51][51];
int main() {
  memset(data, 0, sizeof(data));
  memset(map, 0, sizeof(map));
  int num;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    char str1[30], str2[30];
    cin >> str1 >> str2;
    if (strcmp(str1, ".") != 0)
      for (int j = 0; j < strlen(str1); j++) data[i][str1[j] - 'A'] = 1;
    if (strcmp(str2, ".") != 0)
      for (int j = 0; j < strlen(str2); j++) data[i][str2[j] - 'A'] = -1;
  }
  while (true) {
    int t1, t2;
    cin >> t1 >> t2;
    if (!t1 && !t2) break;
    map[t2][++map[t2][0]] = t1;
  }
  while (true) {
    bool flag = false;
    for (int i = 1; i <= num; i++) {
      for (int j = 1; j <= map[i][0]; j++) {
        for (int k = 0; k < 26; k++) {
          if (data[map[i][j]][k] == 1 && data[i][k] == 0) {
            flag = true;
            data[i][k] = 1;
          }
        }
      }
    }
    if (!flag) break;
  }
  for (int i = 1; i <= num; i++) {
    cout << ":";
    for (int j = 0; j < 26; j++)
      if (data[i][j] == 1) cout << (char)(j + 65);
    cout << ":" << endl;
  }
  return 0;
}
