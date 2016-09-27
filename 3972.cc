#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
using namespace std;

char stdcmd[] = {"><+-,.[]\0"};

string cmd, in;
char out[30001];
int nex[30001];
char c;
int pc, pi, po;

stack<int> st;

int main() {
  int tt;

  scanf("%d", &tt);
  getchar();

  for (int t = 1; t <= tt; t++) {
    bool f = true;

    cmd = in = "";
    memset(out, 0, sizeof(out));
    memset(nex, 0, sizeof(nex));

    while (f) {
      c = getchar();
      if (c == '$') break;
      if (strchr(stdcmd, c) != NULL) cmd += c;
    }
    getchar();

    while (f) {
      c = getchar();
      if (c == '$') break;
      in += c;
    }

    int last;

    while (!st.empty()) st.pop();

    for (int i = 0; i < cmd.size(); i++) {
      if (cmd[i] == '[') st.push(i);
      if (cmd[i] == ']') {
        nex[i] = st.top();
        st.pop();
      }
    }

    while (!st.empty()) st.pop();

    for (int i = cmd.size() - 1; i >= 0; i--) {
      if (cmd[i] == ']') st.push(i);
      if (cmd[i] == '[') {
        nex[i] = st.top();
        st.pop();
      }
    }

    pc = 0;
    pi = 0;
    po = 0;

    printf("Case %d: ", t);

    while (pc != cmd.size()) {
      if (po == 30000) po = 0;
      if (po == -1) po = 29999;

      if (cmd[pc] == '<') {
        po--;
        pc++;
        continue;
      }
      if (cmd[pc] == '>') {
        po++;
        pc++;
        continue;
      }
      if (cmd[pc] == '+') {
        out[po]++;
        pc++;
        continue;
      }
      if (cmd[pc] == '-') {
        out[po]--;
        pc++;
        continue;
      }
      if (cmd[pc] == '.') {
        putchar(out[po]);
        pc++;
        continue;
      }
      if (cmd[pc] == ',') {
        out[po] = in[pi++];
        pc++;
        continue;
      }
      if (cmd[pc] == '[') {
        if (out[po] == '\0') pc = nex[pc];
        pc++;
        continue;
      }
      if (cmd[pc] == ']') {
        if (out[po] != '\0') pc = nex[pc];
        pc++;
        continue;
      }
    }

    puts("");
  }

  return 0;
}
