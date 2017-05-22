#include <iostream>
#include <string>
using namespace std;

const int maxn = 200;

string namelist[maxn];
int listnum = 0, father[maxn][3];

int toint(string st) {
  int i, l = st.length(), x = 0;

  for (i = 0; i < l; i++) x = x * 10 + st[i] - '0';
  return x;
}

int inlist(string st) {
  int i;

  for (i = 0; i < listnum; i++)
    if (st == namelist[i]) return i;
  return -1;
}

void exchange(int *a, int *b) {
  int t;

  t = *a;
  *a = *b;
  *b = t;
}

void simplify(int *a, int *b) {
  int a1 = *a, b1 = *b;

  if (a1 < b1) exchange(&a1, &b1);
  while (b1 != 0) {
    a1 = a1 % b1;
    exchange(&a1, &b1);
  }
  *a = *a / a1;
  *b = *b / a1;
}

int findancestor(int pos, int *v, int *va) {
  int v1, v1a, a = father[pos][1], b = father[pos][2];

  if (father[pos][0] == pos) {
    *v = 1;
    *va = 1;
    return pos;
  }
  father[pos][0] = findancestor(father[pos][0], &v1, &v1a);
  father[pos][1] = a * v1;
  father[pos][2] = b * v1a;
  *v = father[pos][1];
  *va = father[pos][2];
  simplify(&father[pos][1], &father[pos][2]);
  return father[pos][0];
}

void assertion(string st) {
  string name1, name2, temp;
  int value1, value2, pos, pos1, pos2, ancestor1, ancestor2, v1, v2, v1a, v2a;

  st.erase(0, 2);
  pos = st.find(" ");
  temp = st.substr(0, pos);
  st.erase(0, pos + 1);
  value2 = toint(temp);

  pos = st.find(" ");
  name1 = st.substr(0, pos);
  st.erase(0, pos + 3);

  pos = st.find(" ");
  temp = st.substr(0, pos);
  st.erase(0, pos + 1);
  value1 = toint(temp);

  name2 = st;

  pos1 = inlist(name1);
  pos2 = inlist(name2);
  simplify(&value1, &value2);
  if (pos1 != -1 && pos2 != -1) {
    ancestor1 = findancestor(pos1, &v1, &v1a);
    ancestor2 = findancestor(pos2, &v2, &v2a);
    father[ancestor1][0] = ancestor2;
    father[ancestor1][1] = v2 * v1a * value1;
    father[ancestor1][2] = v1 * v2a * value2;
    simplify(&father[ancestor1][1], &father[ancestor1][2]);
  }
  if (pos1 != -1 && pos2 == -1) {
    exchange(&value1, &value2);
    temp = name1;
    name1 = name2;
    name2 = temp;
    exchange(&pos1, &pos2);
  }
  if (pos2 == -1) {
    pos2 = listnum++;
    namelist[pos2] = name2;
    father[pos2][0] = pos2;
    father[pos2][1] = 1;
    father[pos2][2] = 1;
  }
  pos1 = listnum++;
  namelist[pos1] = name1;
  father[pos1][0] = pos2;
  father[pos1][1] = value1;
  father[pos1][2] = value2;
}

void query(string st) {
  string name1, name2;
  int pos1, pos2, v1, v2, v1a, v2a, value1, value2, pos, ancestor1, ancestor2;

  st.erase(0, 2);
  pos = st.find(" ");
  name1 = st.substr(0, pos);
  st.erase(0, pos + 3);
  name2 = st;
  pos1 = inlist(name1);
  pos2 = inlist(name2);
  ancestor1 = findancestor(pos1, &v1, &v1a);
  ancestor2 = findancestor(pos2, &v2, &v2a);
  if (ancestor1 != ancestor2) {
    cout << "? " << name1 << " = ? " << name2 << endl;
    return;
  }
  value1 = v1 * v2a;
  value2 = v2 * v1a;
  simplify(&value1, &value2);
  cout << value2 << " " << name1 << " = " << value1 << " " << name2 << endl;
}

int main() {
  string st;
  getline(cin, st);
  while (st[0] != '.') {
    if (st[0] == '!')
      assertion(st);
    else
      query(st);
    getline(cin, st);
  }
  return 0;
}
