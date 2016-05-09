#include <iostream>
#include <queue>
#include <stdio.h>
#include <functional>
#include <vector>
using namespace std;
int main() {
  double sum, s1, s2;
  int n, n1, n2, i, j, k, v;
  priority_queue<int, vector<int>, less<int> > q2;
  priority_queue<int, vector<int>, greater<int> > q1;
  while (1) {
    scanf("%d %d %d", &n1, &n2, &n);
    if (n && n1 && n2) {
      sum = i = j = 0;
      k = n;
      while (k--) {
        scanf("%d", &v);
        sum += v;
        if (i < n1) {
          q1.push(v);
          i++;
        } else if (q1.top() < v) {
          q1.pop();
          q1.push(v);
        }
        if (j < n2) {
          q2.push(v);
          j++;
        } else if (q2.top() > v) {
          q2.pop();
          q2.push(v);
        }
      }
      s1 = 0;
      for (i = 0; i < n1; i++) {
        s1 += q1.top();
        q1.pop();
      }
      s2 = 0;
      for (j = 0; j < n2; j++) {
        s2 += q2.top();
        q2.pop();
      }
      sum -= s1 + s2;
      n -= n1 + n2;
      printf("%.6f\n", double(sum) / double(n));
    } else
      break;
  }
  return 0;
}
