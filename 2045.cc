#include <iostream>
#include <string.h>
#include <map>
#include <ctype.h>
using namespace std;
map<string, int> word_v;
int stack[100];
int top;
int main() {
  string name;
  int v;
  while (1) {
    cin >> name;
    if (name.compare("END_OF_FIRST_PART") == 0) break;
    cin >> v;
    word_v[name] = v;
  }
  string f;
  while (1) {
    int sum, top = 0, unknow = 0;
    memset(stack, 0, sizeof(stack));
    string temp;
    cin >> f;
    if (f[0] == '0') return 0;
    for (int i = 0; i < f.length(); i++) {
      temp.clear();
      if (isupper(f[i])) {
        temp += f[i];
        if (i + 1 <= f.length() - 1 && islower(f[i + 1])) {
          temp += f[i + 1];
          if (word_v[temp] == 0) {
            cout << "UNKNOWN" << endl;
            unknow = 1;
            break;
          }
          if (i + 2 <= f.length() - 1 && isdigit(f[i + 2])) {
            int number;
            if (i + 3 <= f.length() - 1 && isdigit(f[i + 3])) {
              number = (f[i + 2] - '0') * 10 + (f[i + 3] - '0');
            } else
              number = f[i + 2] - '0';
            stack[++top] = word_v[temp] * number;
            i += 2;
            continue;
          }
          stack[++top] = word_v[temp];
          ++i;
          continue;
        }
        if (word_v[temp] == 0) {
          cout << "UNKNOWN" << endl;
          unknow = 1;
          break;
        }
        if (i + 1 <= f.length() - 1 && isdigit(f[i + 1])) {
          int number;
          if (i + 2 <= f.length() - 1 && isdigit(f[i + 2])) {
            number = (f[i + 1] - '0') * 10 + (f[i + 2] - '0');
          } else
            number = f[i + 1] - '0';
          stack[++top] = word_v[temp] * number;
          ++i;
          continue;
        }
        stack[++top] = word_v[temp];
      } else if (f[i] == '(') {
        stack[++top] = -2;
      } else if (f[i] == ')') {
        int tempsum = 0;
        int number = f[i + 1] - '0';
        while (stack[top] != -2) {
          tempsum += stack[top];
          --top;
        }
        if (i + 2 <= f.length() - 1 && isdigit(f[i + 2]))
          number = (f[i + 1] - '0') * 10 + (f[i + 2] - '0');
        tempsum = tempsum * number;
        stack[top] = tempsum;
        ++i;
      }
    }
    if (!unknow) {
      int an = 0;
      for (int i = 0; i <= top; i++) an += stack[i];
      cout << an << endl;
    }
  }
  return 0;
}
