#include <iostream>

using namespace std;

#define SIZE 10000
#define MAX_SIZE 100000

int a[SIZE];
int counts = 0;

void getPrimeTable() {
  counts = 0;
  for (int i = 2; i < MAX_SIZE; i++) {
    int flag = 0;
    for (int j = 0; j < counts; j++) {
      if (i % a[j] == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      a[counts] = i;
      counts++;
    }
  }
}

int main() {
  getPrimeTable();
  int n, m;
  int ans = 0;
  while (cin >> n >> m) {
    if (n == -1 && m == -1) return 0;
    ans = 0;
    for (int i = 0; i < counts; i++) {
      if (a[i] >= n && a[i] <= m) {
        ans++;
      }
      if (a[i] > m) {
        break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
