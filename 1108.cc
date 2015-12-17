
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct window {
  char c;
  int hig, wid;
  int rc, lc;
  bool al;
} wi[70];
char str[70];
int stack[70];
int top;
char res[70][70];
void change(int len, bool worh, int w) {
  int rl, ll, rn, ln;
  if (isalpha(wi[w].c)) {
    if (worh)  // change wid
      wi[w].wid = len;
    else
      wi[w].hig = len;
    return;
  }
  if (worh) {
    wi[w].wid = len;  // do not forget
    if (wi[w].c == '-') {
      change(len, worh, wi[w].lc);
      change(len, worh, wi[w].rc);
    } else {
      ll = wi[wi[w].lc].wid;
      rl = wi[wi[w].rc].wid;
      if ((len * ll) % (rl + ll) == 0)
        ln = len * ll / (rl + ll);
      else
        ln = len * ll / (rl + ll) + 1;
      rn = len - ln;
      change(ln, worh, wi[w].lc);
      change(rn, worh, wi[w].rc);
    }
  } else {
    wi[w].hig = len;  // do not forget!
    if (wi[w].c == '|') {
      change(len, worh, wi[w].lc);
      change(len, worh, wi[w].rc);
    } else {
      ll = wi[wi[w].lc].hig;
      rl = wi[wi[w].rc].hig;
      if ((len * ll) % (rl + ll) == 0)
        ln = len * ll / (rl + ll);
      else
        ln = len * ll / (rl + ll) + 1;
      rn = len - ln;
      change(ln, worh, wi[w].lc);
      change(rn, worh, wi[w].rc);
    }
  }
  return;
}
void together(int a, int b, int d) {
  if (wi[a].c == '-') {
    if (wi[b].wid != wi[d].wid) {
      if (wi[b].wid > wi[d].wid)
        change(wi[b].wid, true, d);
      else
        change(wi[d].wid, true, b);
    }
    wi[a].wid = wi[b].wid;
    wi[a].hig = wi[b].hig + wi[d].hig;
  } else {
    if (wi[b].hig != wi[d].hig) {
      if (wi[b].hig > wi[d].hig)
        change(wi[b].hig, false, d);
      else
        change(wi[d].hig, false, b);
    }
    wi[a].wid = wi[b].wid + wi[d].wid;
    wi[a].hig = wi[b].hig;
  }
  wi[a].al = true;
  wi[a].lc = b;
  wi[a].rc = d;
}
void construct(int sx, int sy, struct window *r) {
  int i;
  if (isalpha(r->c)) {
    res[sx][sy] = r->c;
    res[sx][sy + r->wid] = res[sx + r->hig][sy + r->wid] =
        res[sx + r->hig][sy] = '*';
    for (i = sy + 1; i < sy + r->wid; i++) {
      if (res[sx][i] != '*') res[sx][i] = '-';
      if (res[sx + r->hig][i] != '*') res[sx + r->hig][i] = '-';
    }
    for (i = sx + 1; i < sx + r->hig; i++) {
      if (res[i][sy] != '*') res[i][sy] = '|';
      if (res[i][sy + r->wid] != '*') res[i][sy + r->wid] = '|';
    }
  } else if (r->c == '-') {
    construct(sx, sy, &wi[r->lc]);
    construct(sx + wi[r->lc].hig, sy, &wi[r->rc]);
  } else {
    construct(sx, sy, &wi[r->lc]);
    construct(sx, sy + wi[r->lc].wid, &wi[r->rc]);
  }
}
int main() {
  int ca, t, i, j;
  char ch;
  scanf("%d", &ca);
  getchar();
  for (t = 1; t <= ca; t++) {
    scanf("%s", str);
    top = 0;
    for (i = 0; i < 70; i++) {
      wi[i].hig = wi[i].wid = 0;
      wi[i].lc = wi[i].rc = -1;
    }
    for (i = 0; str[i] != '\0'; i++) {
      wi[i].c = str[i];
      if (str[i] == '|' || str[i] == '-') {
        stack[top++] = i;
        wi[i].al = false;
      } else {
        wi[i].hig = wi[i].wid = 2;
        wi[i].al = true;
        stack[top++] = i;
        if (top >= 3 && wi[stack[top - 3]].al == false &&
            wi[stack[top - 2]].al == true) {
          while (top >= 3 && wi[stack[top - 3]].al == false &&
                 wi[stack[top - 2]].al == true) {
            together(stack[top - 3], stack[top - 2], stack[top - 1]);
            top = top - 2;
          }
        }
      }
    }
    for (i = 0; i < 70; i++)
      for (j = 0; j < 70; j++) res[i][j] = ' ';
    construct(0, 0, &wi[stack[0]]);
    printf("%d\n", t);
    for (i = 0; i <= wi[stack[0]].hig; i++) {
      for (j = 0; j <= wi[stack[0]].wid; j++) printf("%c", res[i][j]);
      printf("\n");
    }
  }
  return 0;
}