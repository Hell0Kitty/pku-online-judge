#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int room[11][11];  // room[i][j]:房间空闲的起始时刻
bool updated[11][11];  //起始时刻是否已更新

vector<P> agent[26];

int time[26], sta[26];

int done[26];  //已经访问的房间数目

struct S  //行程
    {
  int des;
  int cost;
  S(int des, int cost) : des(des), cost(cost) {}
};

struct E  //排队
    {
  int code;
  int beg;
  int pos;
  E(int code, int beg, int pos) : code(code), beg(beg), pos(pos){};
};

bool operator<(const E &a, const E &b) {
  //两人不是站在同一队列中等待
  if (a.pos != b.pos) return a.beg > b.beg;
  //两人同时到达
  if (a.beg == b.beg) return a.code > b.code;

  int f = a.pos / 100, r = a.pos % 100;

  //等电梯
  if (a.pos % 100 == 0) {
    int t1 = (a.beg % 5 ? (a.beg / 5 + 1) * 5 : a.beg);
    int t2 = (b.beg % 5 ? (b.beg / 5 + 1) * 5 : b.beg);
    //两人乘同一班电梯，资历高的先进
    if ((t1 <= room[f][r] && t2 <= room[f][r]) || t1 == t2)
      return a.code > b.code;
    return t1 > t2;
  } else  //等房间
  {
    //两人都得等，资历高的先进
    if (a.beg <= room[f][r] && b.beg <= room[f][r])
      return a.code > b.code;  //!room[f][r]更新会影响这种比较
    //至少有一个人不用等，先到的先进
    else
      return a.beg > b.beg;
  }
}

priority_queue<E, vector<E> > que;  //排队
vector<S> record[26];               //行程

void input() {
  FILE *fp = stdin;  //提交时改成stdin
  char c;
  int h, m, s, pos, dur;
  while (fscanf(fp, " %[A-Z] ", &c)) {
    int idx = c - 'A';
    fscanf(fp, "%d:%d:%d", &h, &m, &s);
    time[idx] = sta[idx] = 3600 * h + 60 * m + s;

    while (fscanf(fp, "%d", &pos), pos) {
      fscanf(fp, "%d", &dur);
      agent[idx].push_back(P(pos, dur));
    }
    agent[idx].push_back(P(pos, 0));  //! Exit
  }
}

void init() {
  for (int i = 0; i < 26; i++) {
    if (!agent[i].size()) continue;
    if (agent[i][0].first / 100 == 1)
      record[i].push_back(S(agent[i][0].first, 30));  //往一层某房间
    else
      record[i].push_back(S(100, 30));  //往一层电梯
    time[i] += 30;
    que.push(E(i, time[i], record[i].back().des));
  }
}

void simulator() {
  int wait, id, cost, to, f, r;
  while (!que.empty()) {
    E e = que.top();
    que.pop();
    id = e.code;
    f = e.pos / 100;
    r = e.pos % 100;
    if (updated[f][r]) {
      que.push(e);
      updated[f][r] = false;
      continue;
    }

    if (r == 0)  //等电梯
    {
      if (e.beg <= room[f][r])
        wait = room[f][r] - e.beg;
      else
        wait = (e.beg % 5 ? 5 - e.beg % 5 : 0);
      if (wait) record[id].push_back(S(e.pos, wait));
      time[id] += wait;
      room[f][r] = time[id] + 5;
      updated[f][r] = true;
      to = agent[id][done[id]].first;
      if (to == 0)  //!Exit
      {
        cost = 30 * (e.pos / 100 - 1);
        record[id].push_back(S(100, cost));
        record[id].push_back(S(to, 30));
        continue;
      }
      cost = 30 * (max(to / 100, e.pos / 100) - min(to / 100, e.pos / 100));
      record[id].push_back(S(to / 100 * 100, cost));  //在电梯里
      time[id] += cost;
      record[id].push_back(S(to, 10));  //往房间
      time[id] += 10;
      que.push(E(id, time[id], to));
    } else  //等房间
    {
      wait = max(room[f][r] - e.beg, 0);
      if (wait) record[id].push_back(S(e.pos, wait));
      time[id] += wait;
      cost = agent[id][done[id]].second;
      record[id].push_back(S(-e.pos, cost));  //取反
      time[id] += cost;

      room[f][r] = time[id];
      updated[f][r] = true;

      done[id]++;
      to = agent[id][done[id]].first;
      if (to == 0 && f == 1)  //!Exit
      {
        record[id].push_back(S(to, 30));
        continue;
      }
      if (to / 100 != f) to = f * 100;  //需等电梯
      record[id].push_back(S(to, 10));  //往电梯
      time[id] += 10;
      que.push(E(id, time[id], to));
    }
  }
}

void t_p(int t) {
  int h = t / 3600, m = (t % 3600) / 60, s = t % 3600 % 60;
  printf("%02d:%02d:%02d ", h, m, s);
}

void e_p(int pre, int cur) {
  if (pre == 0) {
    printf("Entry\n");
    return;
  }
  if (cur == 0) {
    printf("Exit\n");
    return;
  }
  if (cur < 0) {
    printf("Stay in room %04d\n", -cur);
    return;
  }
  if (pre == cur) {
    if (cur % 100 == 0)
      printf("Waiting in elevator queue\n");
    else
      printf("Waiting in front of room %04d\n", cur);
    return;
  }
  if (pre % 100 == 0 && cur % 100 == 0) {
    printf("Stay in elevator\n");
    return;
  };
  if (pre < 0) {
    if (cur % 100 == 0)
      printf("Transfer from room %04d to elevator\n", -pre);
    else
      printf("Transfer from room %04d to room %04d\n", -pre, cur);
    return;
  } else
    printf("Transfer from elevator to room %04d\n", cur);
}

void output() {
  int pre_pos, cur_pos, t;
  for (int i = 0; i < 26; i++) {
    if (!record[i].size()) continue;
    t = sta[i];
    pre_pos = 0;

    printf("%c\n", 'A' + i);
    for (int j = 0; j != record[i].size(); j++) {
      t_p(t);
      t_p(t += record[i][j].cost);
      cur_pos = record[i][j].des;
      e_p(pre_pos, cur_pos);
      pre_pos = cur_pos;
    }
    printf("\n");
  }
}

int main() {
  input();
  init();
  simulator();
  output();
  return 0;
}
