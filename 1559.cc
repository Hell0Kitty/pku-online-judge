#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int N = 100005;
string expression;
char ex[N];
int values[N];
string lefts;
string rights;
char oper[N];
int sign[N];
int lval;
int lop;

void handle() {
  int len = expression.length();
  int flag = 1;
  int ans = 0;
  rights = "";
  lval = 0;
  lop = 0;
  int ishavenum = 0;
  memset(sign, 0, sizeof(sign));

  for (int i = 0; i < len; i++) {
    if (expression[i] >= '0' && expression[i] <= '9') {
      ans = ans * 10 + expression[i] - '0';
      ishavenum = 1;
      flag = 0;
    } else if (expression[i] == ' ') {
      if (ishavenum) {
        values[lval] = (sign[lval] == -1) ? -ans : ans;
        lval++;
      }
      ans = 0;
      // flag = 0;
      ishavenum = 0;
      //
    } else if (expression[i] == '=') {
      if (ishavenum) {
        values[lval] = (sign[lval] == -1) ? -ans : ans;
        lval++;
      }
      ans = 0;
      flag = 0;
      ishavenum = 0;

      rights = "= ";
      for (int j = i + 1; j < len; j++)
        if (expression[j] == ' ')
          continue;
        else
          rights += expression[j];
      i = len;
    } else {
      if (ishavenum) {
        if (ishavenum) values[lval] = (sign[lval] == -1) ? -ans : ans;
        lval++;
        ans = 0;
        flag = 0;
        ishavenum = 0;
      }

      if (flag) {
        if (expression[i] == '+')
          sign[lval] = 1;
        else
          sign[lval] = -1;
        flag = 0;
      } else {
        oper[lop++] = expression[i];
        flag = 1;
      }
    }
  }
}

void Print(string l, int i, int preres) {
  cout << l;
  cout << preres << " ";

  for (int j = i + 1; j < lop; j++) {
    cout << oper[j] << " ";
    // if(sign[j+1] == 1) cout<<"+";
    cout << values[j + 1] << " ";
  }
  cout << rights << endl;
}
string convert(int num) {
  string res = "";
  if (num < 0) {
    res = "-";
    num = -num;
  }
  int temp[N];
  int l = 0;
  if (num == 0) res = "0";
  while (num) {
    temp[l++] = num % 10;
    num /= 10;
  }
  for (int i = l - 1; i >= 0; i--) res += temp[i] + '0';
  return res;
}
void printmulAndDiv() {
  int pre = -2;
  int rlval = 0;
  int rlop = 0;
  int preres = 0;
  string l = "";

  for (int i = 0; i < lop; i++) {
    if (oper[i] == '*') {
      if (pre == i - 1) {
        preres = preres * values[i + 1];
      } else {
        // values[rlval++] = preres;
        // if(l == "") l =
        preres = values[i] * values[i + 1];
      }
      pre = i;
      Print(l, i, preres);
    } else if (oper[i] == '/') {
      if (pre == i - 1) {
        preres = preres / values[i + 1];
      } else {
        preres = values[i] / values[i + 1];
      }
      pre = i;
      Print(l, i, preres);
    } else {
      oper[rlop++] = oper[i];
      if (pre == i - 1)
        values[rlval] = preres;
      else {
        values[rlval] = values[i];
        sign[rlval] = sign[i];
      }
      if (i != rlval) sign[i] = 0;
      // rlval++;

      l += convert(values[rlval++]);
      l += " ";
      l += oper[i];
      l += " ";
    }
  }
  if ((pre == lop - 1) && ((oper[lop - 1] == '*') || (oper[lop - 1] == '/'))) {
    values[rlval] = preres;
  } else {
    values[rlval] = values[lop];
    sign[rlval] = sign[lop];
  }
  // if(lop != rlval) sign[lop] = 0;
  rlval++;

  lop = rlop;
  lval = rlval;
}
void End() {
  int res = values[0];
  for (int i = 0; i < lop; i++) {
    if (oper[i] == '+')
      res = res + values[i + 1];
    else
      res = res - values[i + 1];

    printf("%d ", res);
    for (int j = i + 1; j < lop; j++) {
      printf("%c ", oper[j]);
      // if(sign[j+1] == 1) printf("+");
      printf("%d ", values[j + 1]);
    }
    cout << rights << endl;
    ;
  }
}
int main() {
  while (gets(ex) != NULL) {
    expression = ex;
    handle();
    Print("", -1, values[0]);
    printmulAndDiv();
    End();
    printf("\n");
  }
  return 0;
}
