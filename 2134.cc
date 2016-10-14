#include <stdio.h>
#include <string.h>

typedef struct { int tg, tr, init, tc; } tralight;
typedef struct { int place, speed, time; } cmd;
tralight list[110];
int ltpos[110];
cmd queue[30010];
int now, add;
char sch[110][110][310];

int situ(tralight a, int time) {
  int t = a.tc + time;
  t %= (a.tg + a.tr);
  if (a.init == 0) {
    if (t >= a.tr)
      return 1;
    else
      return 0;
  } else {
    if (t >= a.tg)
      return 0;
    else
      return 1;
  }
}

int main() {
  int l, n, i, cp, cs, ct, tp, ts, p, fl, ans;
  char ar[5];
  scanf("%d %d", &l, &n);
  memset(ltpos, -1, sizeof(ltpos));
  memset(sch, 0, sizeof(sch));
  for (i = 0; i < n; i++) {
    scanf("%d %d %d %s %d", &p, &list[i].tg, &list[i].tr, ar, &list[i].tc);
    if (ar[0] == 'R')
      list[i].init = 0;
    else
      list[i].init = 1;
    ltpos[p] = i;
  }
  now = add = 0;
  queue[add].place = 0, queue[add].speed = 0, queue[add].time = 0;
  add++;
  sch[0][0][0] = 1;
  while (now != add) {
    cp = queue[now].place, cs = queue[now].speed, ct = queue[now].time;
    now++;
    if (cp == l && cs == 1) {
      ans = ct;
      break;
    }
    ts = cs - 1;
    if (ts < 0) ts = 0;
    tp = cp + cs;
    if (ltpos[cp] != -1) {
      if (situ(list[ltpos[cp]], ct) == 0 && cs != 0) continue;
    }
    for (i = cp + 1, fl = 0; i < tp; i++) {
      if (ltpos[i] != -1) {
        if (situ(list[ltpos[i]], ct) == 0) {
          fl = 1;
          break;
        }
      }
    }
    if (fl == 1)
      continue;
    else if (sch[tp][ts][ct + 1] == 0) {
      queue[add].place = tp, queue[add].speed = ts, queue[add].time = ct + 1;
      sch[tp][ts][ct + 1] = 1;
      add++;
    }
    ts++;
    if (sch[tp][ts][ct + 1] == 0) {
      queue[add].place = tp, queue[add].speed = ts, queue[add].time = ct + 1;
      sch[tp][ts][ct + 1] = 1;
      add++;
    }
    ts++;
    if (ts > cs + 1) continue;
    if (sch[tp][ts][ct + 1] == 0) {
      queue[add].place = tp, queue[add].speed = ts, queue[add].time = ct + 1;
      sch[tp][ts][ct + 1] = 1;
      add++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
