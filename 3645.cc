#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
int main() {
  string str;
  while (getline(cin, str)) {
    if (str == "()") break;
    stack<double> q;
    for (int i = 0; i < str.size();) {
      if (str[i] == ' ' || str[i] == '(')
        i++;
      else if (isdigit(str[i]) || str[i] == '-')  //考虑负数
      {
        string temp;
        for (; i < str.size() && str[i] != ' ' && str[i] != ')'; i++) {
          temp += str[i];
        }
        double x = atof(temp.c_str());
        q.push(x);
      } else {
        double p, x, y;
        y = q.top();
        q.pop();
        x = q.top();
        q.pop();
        p = q.top();
        q.pop();
        double cnt = p * (x + y) + (1 - p) * (x - y);
        q.push(cnt);
        i++;
      }
    }
    double ans = q.top();
    printf("%.2lf\n", ans);
  }
  return 0;
}
