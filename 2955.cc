#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    bool *a = new bool[s.length()];
    memset(a, false, s.length());
    stack<int> ist;
    stack<char> cst;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(') {
        ist.push(i);
        cst.push(s[i]);
      } else if (s[i] == '[') {
        ist.push(i);
        cst.push(s[i]);

      } else if (s[i] == ')') {
        // cout << "[dbg] here" << endl;
        if (!cst.empty() && cst.top() == '(') {
          a[i] = true;
          a[ist.top()] = true;
          ist.pop();
          cst.pop();
        } else if (!cst.empty()) {
          //  ist.pop(); cst.pop();
          //  cout << "[dbg] top of cst is: " << cst.top() << endl;
        }

      } else if (s[i] == ']') {
        if (!cst.empty() && cst.top() == '[') {
          a[i] = true;
          a[ist.top()] = true;
          ist.pop();
          cst.pop();
        } else if (!cst.empty()) {
          // ist.pop(); cst.pop();
        }
      }
    }
    int max_len = 0, cur_len = 0;
    cout << "[dbg] dumping result array:" << endl;
    for (int i = 0; i < s.length(); ++i) {
      cout << a[i] << endl;
      if (a[i]) ++cur_len;
    }
    return cur_len;
  }
};

int main(int argc, char const *argv[]) {
  std::ios::sync_with_stdio(false);
  Solution s;
  while (true) {
    string input;
    cin >> input;
    if (input == "end") break;
    int result = s.longestValidParentheses(input);
    cout << result << endl;
  }
  return 0;
}