#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define N 100

typedef struct team {
  int place[2];
  int number;
  int sum;
  int type;
  int location;
  int offset;
} Team;

Team tm[N + 1];
char line[300];
vector<Team*> vds;
vector<Team*> vsingle;

bool cmp(const Team* const a, const Team* const b) {
  if (a->sum != b->sum)
    return a->sum < b->sum;
  else
    return a->number < b->number;
}

bool cmpTeam(const Team* const a, const Team* const b) {
  if (a->location != b->location)
    return a->location < b->location;
  else if (a->offset != b->offset)
    return a->offset < b->offset;
  else
    return a->number < b->number;
}

class Check {
 private:
  int min;
  int max;

 public:
  Check() {
    min = 0;
    max = 101;
  }
  void setMax(int m) {
    if (m < max) max = m;
  }
  void setMin(int m) {
    if (m > min) min = m;
  }

  int result() {
    if (min < max) {
      return min;
    } else {
      return -1;
    }
  }
};

int main() {
  int t;
  char* ptr;
  scanf("%d", &t);
  getchar();

  int place = 1;
  for (int i = 1; i <= t; i++) {
    gets(line);
    ptr = strtok(line, " \0");  // 读入时可以处理多余的空格
    int count = 0;
    while (ptr != NULL) {
      count++;
      int number = atoi(ptr);
      tm[number].number = number;
      tm[number].type = 1;
      tm[number].place[0] = place;
      tm[number].sum = place;
      ptr = strtok(NULL, " ");
    }
    place += count;
  }

  scanf("%d", &t);
  getchar();

  place = 1;
  for (int i = 1; i <= t; i++) {
    gets(line);
    ptr = strtok(line, " \n");  // 读入时可以处理多余的空格
    int count = 0;
    while (ptr != NULL) {
      count++;
      int number = atoi(ptr);
      tm[number].number = number;
      tm[number].type += 2;
      tm[number].place[1] = place;
      tm[number].sum += place;

      if (tm[number].type == 3) {
        vds.push_back(&tm[number]);
      }
      ptr = strtok(NULL, " ");
    }
    place += count;
  }
  sort(vds.begin(), vds.end(), cmp);
  int last = 0;
  int index = 1;
  int count = 0;
  for (vector<Team*>::iterator it = vds.begin(); it != vds.end(); ++it) {
    Team* tm = *it;
    if (tm->sum == last) {
      count++;
      tm->location = index;
    } else {
      index += count;
      count = 1;
      tm->location = index;
      last = tm->sum;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (tm[i].type == 1 || tm[i].type == 2) {
      Check ck;
      bool eq = false;
      bool same = true;
      for (vector<Team*>::iterator it = vds.begin(); it != vds.end(); ++it) {
        Team* td = *it;
        int ch = tm[i].sum - td->place[tm[i].type - 1];
        if (ch == 0) {
          if (!eq) {
            eq = true;
            tm[i].location = td->location;
          } else {
            if (tm[i].location != td->location) {
              same = false;
              break;
            }
          }
        } else if (ch < 0) {
          ck.setMax(td->location);
        } else {
          ck.setMin(td->location);
        }
      }
      if (!eq) {
        int re = ck.result();
        if (re > -1) {
          tm[i].location = re;
          tm[i].offset = tm[i].sum;
          vsingle.push_back(&tm[i]);
        }
      } else {
        if (same) {
          vsingle.push_back(&tm[i]);
        }
      }
    }
  }
  vds.insert(vds.end(), vsingle.begin(), vsingle.end());
  sort(vds.begin(), vds.end(), cmpTeam);

  int last_location = 0;
  int last_offset = 0;
  index = 1;
  count = 0;
  for (vector<Team*>::iterator it = vds.begin(); it != vds.end(); ++it) {
    Team* tm = *it;
    if (tm->location == last_location && tm->offset == last_offset) {
      count++;
      tm->sum = index;
    } else {
      index += count;
      count = 1;
      tm->sum = index;
      last_location = tm->location;
      last_offset = tm->offset;
    }
  }

  last = vds[0]->sum;
  printf("%d", vds[0]->number);
  for (int i = 1; i < vds.size(); i++) {
    if (vds[i]->sum == last) {
      printf(" %d", vds[i]->number);
    } else {
      printf("\n%d", vds[i]->number);
      last = vds[i]->sum;
    }
  }
  puts("");
  return 0;
}
