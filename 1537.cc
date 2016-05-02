#include <iostream>
#include <string.h>
#include <memory>
using namespace std;

int main() {
  enum State {
    PRE_NUM,
    SIGN1,
    PRE_POINT,
    POINT,
    FRACTION,
    E,
    SIGN2,
    EXP,
    FOLLOWBLANK,
    ERROR
  };
  char ch;
  char str[1000];
  State state;
  while (cin >> ch, ch != '*') {
    int idx = 0;
    state = PRE_NUM;
    while (ch != '\n') {
      switch (state) {
        case PRE_NUM:
          if (ch == '+' || ch == '-') {
            state = SIGN1;
            break;
          }
          if (ch >= '0' && ch <= '9') {
            state = PRE_POINT;
            break;
          }
          state = ERROR;
          break;
        case SIGN1:
          if (ch >= '0' && ch <= '9') {
            state = PRE_POINT;
          } else
            state = ERROR;
          break;
        case PRE_POINT:
          if (ch == '.') {
            state = POINT;
            break;
          }
          if (ch == 'e' || ch == 'E') {
            state = E;
            break;
          }
          if (!(ch >= '0' && ch <= '9')) {
            state = ERROR;
          }
          break;
        case POINT:
          if (ch >= '0' && ch <= '9') {
            state = FRACTION;
          } else
            state = ERROR;
          break;
        case FRACTION:
          if (ch == 'e' || ch == 'E') {
            state = E;
            break;
          }
          if (ch == ' ') {
            state = FOLLOWBLANK;
            break;
          }
          if (!(ch >= '0' && ch <= '9')) {
            state = ERROR;
          }
          break;
        case E:
          if (ch == '+' || ch == '-') {
            state = SIGN2;
            break;
          }
          if (ch >= '0' && ch <= '9') {
            state = EXP;
            break;
          }
          state = ERROR;
          break;
        case SIGN2:
          if (ch >= '0' && ch <= '9') {
            state = EXP;
          } else
            state = ERROR;
          break;
        case EXP:
          if (ch == ' ') {
            state = FOLLOWBLANK;
            break;
          }
          if (!(ch >= '0' && ch <= '9')) state = ERROR;
          break;
        case FOLLOWBLANK:
          if (ch != ' ') state = ERROR;
        default:
          break;
      }
      str[idx++] = ch;
      cin.get(ch);
    }
    str[idx] = '\0';
    while (str[--idx] == ' ') str[idx] = '\0';
    cout << str << " is ";
    if (state == ERROR || state == PRE_POINT || state == POINT ||
        state == SIGN1 || state == SIGN2 || state == E)
      cout << "illegal.\n";
    else
      cout << "legal.\n";
    memset(str, 0, ++idx * sizeof(char));
  }
}
