#include <cstdio>
#include <cstring>
#include <algorithm>
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;

const int L = 19, N = 1 << (L - 1);
const char EPT = 'O';

char _s[L], _rs[L];
char _t[L], _rt[L];
bool _flg[128];
int _dis[N];
int _pre[L][L][L];
int _send, _tend;

int KMP(char p[], char t[], int pre[]) {
  int res = 0;
  for (int i = 0, j = -1; 0 != t[i]; ++i) {
    for (; - 1 < j && p[j + 1] != t[i]; j = pre[j])
      ;
    if (p[j + 1] == t[i]) ++j;
    if (res < j + 1) res = j + 1;
    if (0 == p[res]) break;
  }
  return res;
}
void Decode(int inx, char s[], char rs[]) {
  for (int i = 0, j = 1; i < _tend; ++i, j <<= 1) {
    // if (inx & i) rs[i] = _t[i];
    if (inx & j)
      s[i] = _t[i];
    else
      s[i] = EPT;
  }
  rs[_tend] = 0;
  reverse_copy(s, s + _tend, rs);
  s[_tend] = 0;
}

int DFS(int d, int inx) {
  if (-1 != _dis[inx]) return _dis[inx];
  char t[L], rt[L];
  Decode(inx, t, rt);
  int prelen = 0;
  int bst = _tend;
  for (int i = 0, j; 0 != t[i]; ++i) {
    for (j = i; EPT == t[j]; ++j)
      ;
    if (j == i) {
      prelen = 0;
      continue;
    }
    char ch = _t[j];
    _t[j] = 0;
    int *pre = _pre[i][j];
    int len = KMP(_t + i, _s, pre);
    len = max(len, KMP(_t + i, _rs, pre));
    len = max(len, KMP(_t + i, t, pre));
    len = max(len, KMP(_t + i, rt, pre));
    _t[j] = ch;
    if (prelen <= len) {
      int nxt = inx | (((1 << (i + len)) - 1) ^ ((1 << i) - 1));
      int ret = DFS(d + 1, nxt);
      bst = min(bst, ret + 1);
    }
    prelen = max(prelen - 1, len);
  }
  return _dis[inx] = bst;
}
void CalPre(char p[], int pre[]) {
  pre[0] = -1;
  for (int i = 1, j = -1; 0 != p[i]; ++i) {
    for (; - 1 < j && p[j + 1] != p[i]; j = pre[j])
      ;
    if (p[j + 1] == p[i]) ++j;
    pre[i] = j;
  }
}

void InitPre() {
  for (int i = 0; 0 != _t[i]; ++i) {
    for (int j = i + 1; 0 != _t[j - 1]; ++j) {
      char ch = _t[j];
      _t[j] = 0;
      CalPre(_t + i, _pre[i][j]);
      _t[j] = ch;
    }
  }
}

void Init() {
  _send = strlen(_s);
  _tend = strlen(_t);
  reverse_copy(_s, _s + _send, _rs);
  _rs[_send] = 0;
  reverse_copy(_t, _t + _tend, _rt);
  _rt[_tend] = 0;
  memset(_dis, -1, sizeof(_dis));
  _dis[(1 << _tend) - 1] = 0;
  InitPre();
}

int main() {
  int tc, i;
  scanf("%d\n", &tc);
  while (tc--) {
    _flg['A'] = _flg['C'] = _flg['G'] = _flg['T'] = false;
    gets(_s);
    gets(_t);
    for (i = 0; 0 != _s[i]; ++i) {
      _flg[_s[i]] = true;
    }
    for (i = 0; 0 != _t[i]; ++i) {
      if (!_flg[_t[i]]) break;
    }
    if (0 != _t[i]) {
      puts("impossible");
      continue;
    }
    Init();
    printf("%d\n", DFS(0, 0));
  }
  return 0;
}
