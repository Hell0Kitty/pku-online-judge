
#include <stdio.h>
#include <string.h>
#include <memory.h>

#include <iostream>
#include <memory>
#define MAX_N 100
using namespace std;

int exp[MAX_N + 1];
int curExp[MAX_N + 1];
int expLen, expVal, curVal;
int opType[3] = {-1, -2, -6};
bool found = false;

int stackv1[MAX_N + 1];
int stackv2[MAX_N + 1];
int head1;
int head2;

int trimParath() {
  head1 = head2 = 0;
  int top, val1, val2;
  for (int i = 1; i <= expLen; i++) {
    int type = curExp[i];
    if (type >= 0)
      stackv1[head1++] = type;
    else {
      if (type == -3)
        stackv2[head2++] = type;
      else if (type == -1 || type == -2 || type == -6) {
        top = stackv2[head2 - 1];
        if (top == -3)
          stackv2[head2++] = type;
        else if (top == -1 || top == -2 || top == -6) {
          head2--;
          val2 = stackv1[--head1];
          val1 = stackv1[--head1];
          if (top == -1)
            stackv1[head1++] = val1 + val2;
          else if (top == -2)
            stackv1[head1++] = val1 - val2;
          else if (top == -6)
            stackv1[head1++] = val1 * val2;
          stackv2[head2++] = type;
        } else
          stackv2[head2++] = type;
      } else if (type == -4) {
        top = stackv2[--head2];
        if (top == -1 || top == -2 || top == -6) {
          val2 = stackv1[--head1];
          val1 = stackv1[--head1];
          if (top == -1)
            stackv1[head1++] = val1 + val2;
          else if (top == -2)
            stackv1[head1++] = val1 - val2;
          else if (top == -6)
            stackv1[head1++] = val1 * val2;
          if (stackv2[head2 - 1] == -3) head2--;
        }
      }
    }
  }
  while (head2 != 0) {
    top = stackv2[--head2];
    if (top == -1 || top == -2 || top == -6) {
      val2 = stackv1[--head1];
      val1 = stackv1[--head1];
      if (top == -1)
        stackv1[head1++] = val1 + val2;
      else if (top == -2)
        stackv1[head1++] = val1 - val2;
      else if (top == -6)
        stackv1[head1++] = val1 * val2;
    }
  }
  return stackv1[0];
}

void dfsT(int curPos) {
  if (found) return;
  if (curPos > expLen) {
    if (curExp[4] == -6 && curExp[6] == -2 && curExp[8] == -6) {
      int a = 2;
    }
    int res = trimParath();
    if (res == expVal) found = true;
    return;
  }
  if (exp[curPos] != -5 && !found) {
    curExp[curPos] = exp[curPos];
    dfsT(curPos + 1);
    return;
  }
  for (int i = 0; i < 3 && !found; i++) {
    curExp[curPos] = opType[i];
    dfsT(curPos + 1);
  }
}
int main() {
  char ch;
  int seq = 0;
  bool neg = false;
  while ((ch = getchar()) != '0') {
    seq++, found = neg = false;
    expVal = 0;
    while (ch == ' ') ch = getchar();
    if (ch == '-')
      neg = true;
    else
      expVal = int(ch - '0');
    while ((ch = getchar()) != ' ' && ch != '=')
      expVal = expVal * 10 + int(ch - '0');

    if (neg) expVal = -expVal;

    if (ch != '=')
      while ((ch = getchar()) != '=')
        ;
    while ((ch = getchar()) == ' ')
      ;

    bool preDigit = false;
    bool firstV = true;
    curVal = 0, expLen = 0;

    bool allEven = true;

    while (ch != 10) {
      if (ch >= '0' && ch <= '9') {
        preDigit = true;
        curVal = curVal * 10 + int(ch - '0');

        if (firstV && expLen >= 1 && (exp[expLen] >= 0 || exp[expLen] == -4))
          exp[++expLen] = -5;
        firstV = false;
      } else {
        firstV = true;
        if (preDigit) {
          exp[++expLen] = curVal;

          if (curVal % 2 != 0) allEven = false;
          curVal = 0;
          preDigit = false;
        }
        if (ch == '(') {
          if (expLen >= 1 && (exp[expLen] == -4 || exp[expLen] >= 0))
            exp[++expLen] = -5;
          exp[++expLen] = -3;
        } else if (ch == ')')
          exp[++expLen] = -4;
      }
      ch = getchar();
    }
    if (preDigit) {
      exp[++expLen] = curVal;
      if (curVal % 2 != 0) allEven = false;
    }

    cout << "Equation #" << seq << ":" << endl;

    dfsT(1);
    if (found) {
      // printf("%I64d=", expVal);
      cout << expVal << "=";
      for (int i = 1; i <= expLen; i++) {
        int type = curExp[i];
        if (type >= 0) cout << type;
        // printf("%I64d", type);
        else {
          if (type == -1)
            cout << "+";
          else if (type == -2)
            cout << "-";
          else if (type == -3)
            cout << "(";
          else if (type == -4)
            cout << ")";
          else if (type == -6)
            cout << "*";
        }
      }
    } else
      cout << "Impossible";
    cout << endl << endl;
  }
  return 0;
}