#include <iostream>
#include <algorithm>

using namespace std;

int time[1010], n;

int solve(int time[], int n) {
  if (n == 1) return time[0];
  if (n == 2) return time[1];
  if (n == 3) return time[0] + time[1] + time[2];
  if (2 * time[1] < (time[0] + time[n - 2]))
    return time[0] + 2 * time[1] + time[n - 1] + solve(time, n - 2);
  else
    return 2 * time[0] + time[n - 1] + time[n - 2] + solve(time, n - 2);
}

void bridge(int time[], int n) {
  if (n == 1) {
    cout << time[0] << endl;
    return;
  }

  if (n == 2) {
    cout << time[0] << " " << time[1] << endl;
    return;
  }

  if (n == 3) {
    cout << time[0] << " " << time[2] << endl;
    cout << time[0] << endl;
    cout << time[0] << " " << time[1] << endl;
    return;
  }

  if (2 * time[1] < time[0] + time[n - 2]) {
    cout << time[0] << " " << time[1] << endl;
    cout << time[0] << endl;
    cout << time[n - 2] << " " << time[n - 1] << endl;
    cout << time[1] << endl;
  }

  else {
    cout << time[0] << " " << time[n - 1] << endl;
    cout << time[0] << endl;
    cout << time[0] << " " << time[n - 2] << endl;
    cout << time[0] << endl;
  }

  bridge(time, n - 2);
}

int main() {
  int i, j, k;
  while (cin >> n) {
    for (i = 0; i < n; i++) cin >> time[i];

    sort(time, time + n);

    cout << solve(time, n) << endl;

    bridge(time, n);
  }
  return 0;
}
