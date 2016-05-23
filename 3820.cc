#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

#define sta1 1
#define sta2 2
#define sta3 3
#define sta4 4
#define sta5 5
#define sta6 6
#define sta7 7
#define sta8 8
#define sta9 9
#define sta10 10
#define sta11 11
#define stafalse 12
#define sta13 13
#define sta14 14
#define sta15 15

char str[10000100];

int statuNow;
stack<int> st;
void autoMachine(char ch, int idx) {
  switch (statuNow) {
    case sta1:
      if (ch == '<')
        statuNow = sta2;
      else if (ch == '&')
        statuNow = sta6;
      else if (ch == '>')
        statuNow = stafalse;
      else if (32 <= ch && ch <= 127)
        statuNow = sta1;
      else
        statuNow = stafalse;
      break;
    case sta2:
      if (ch == '/')
        statuNow = sta3;
      else if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9'))
        statuNow = sta4;
      else
        statuNow = stafalse;
      break;
    case sta3:
      if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9'))
        statuNow = sta3;
      else if (ch == '>') {
        bool flag = true;

        if (st.empty())
          flag = false;
        else {
          int lastStr = st.top(), thisStr = idx;
          while (str[lastStr] == str[thisStr]) lastStr--, thisStr--;
          if (str[thisStr] == '/' && str[lastStr] == '<')
            flag = true, st.pop();
          else
            flag = false;
        }

        if (flag)
          statuNow = sta1;
        else
          statuNow = stafalse;
      } else
        statuNow = stafalse;
      break;
    case sta4:
      if (('a' <= ch && ch <= 'z') || ('0' <= ch && ch <= '9'))
        statuNow = sta4;
      else if (ch == '/')
        statuNow = sta5;
      else if (ch == '>')
        statuNow = sta1, st.push(idx);
      else
        statuNow = stafalse;
      break;
    case sta5:
      if (ch == '>')
        statuNow = sta1;
      else
        statuNow = stafalse;
      break;
    case sta6:
      if (ch == 'l')
        statuNow = sta7;
      else if (ch == 'a')
        statuNow = sta8;
      else if (ch == 'g')
        statuNow = sta9;
      else if (ch == 'x')
        statuNow = sta13;
      else
        statuNow = stafalse;
      break;
    case sta7:
      if (ch == 't')
        statuNow = sta11;
      else
        statuNow = stafalse;
      break;
    case sta8:
      if (ch == 'm')
        statuNow = sta10;
      else
        statuNow = stafalse;
      break;
    case sta9:
      if (ch == 't')
        statuNow = sta11;
      else
        statuNow = stafalse;
      break;
    case sta10:
      if (ch == 'p')
        statuNow = sta11;
      else
        statuNow = stafalse;
      break;
    case sta11:
      if (ch == ';')
        statuNow = sta1;
      else
        statuNow = stafalse;
      break;
    case sta13:
      if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') ||
          ('0' <= ch && ch <= '9'))
        statuNow = sta14;
      else
        statuNow = stafalse;
      break;
    case sta14:
      if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') ||
          ('0' <= ch && ch <= '9'))
        statuNow = sta15;
      else
        statuNow = stafalse;
      break;
    case sta15:
      if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') ||
          ('0' <= ch && ch <= '9'))
        statuNow = sta14;
      else if (ch == ';')
        statuNow = sta1;
      else
        statuNow = stafalse;
      break;
    default:
      ;
  }
}

int main() {
  while (gets(str) != NULL) {
    while (!st.empty()) st.pop();
    statuNow = sta1;
    int len = strlen(str);
    for (int i = 0; i < len; i++) autoMachine(str[i], i);
    if (statuNow == sta1 && st.empty())
      printf("valid\n");
    else
      printf("invalid\n");
  }
}
