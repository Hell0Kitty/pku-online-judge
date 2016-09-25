#include <cstdio>
#include <stack>
#include <cstring>
#include <cstdlib>
using namespace std;
int main() {
  int i, j, k, T;
  int num, flag;
  while (scanf("%d", &T), T) {
    flag = 0;  //必须再次初始化为0
    while (1) {
      stack<int> s;
      int temp = 1;
      s.push(temp);
      for (i = 1; i <= T; i++) {
        scanf("%d", &num);
        if (0 == num) {
          flag = 1;
          break;
        }
        if (s.empty()) {
          temp++;
          s.push(temp);
        }
        int top = s.top();
        while (top != num) {
          if (temp == T) break;
          temp++;
          s.push(temp);
          top = s.top();
        }
        if (top == num) s.pop();
      }
      if (flag) break;
      if (s.empty())
        puts("Yes");
      else
        puts("No");
    }
    printf("\n");
  }
  return 0;
}
