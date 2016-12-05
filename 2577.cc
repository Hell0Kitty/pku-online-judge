#include <cstdio>
#include <cstring>

int hotal[10];
int memory[1000];
int runedCommandNum;

bool readIntInThisLine(int nowPosition) {
  char now;
  int num = 0;

  now = getchar();
  if (now == '\n') return false;
  if (now == EOF) return false;

  while (now != '\n') {
    num = num * 10 + now - '0';
    now = getchar();
  }
  memory[nowPosition] = num % 1000;
  return true;
}

bool runCommandAt(int nowPosition, int &nextPosition) {
  char command[10];
  sprintf(command, "%03d", memory[nowPosition]);

  nextPosition = nowPosition + 1;
  switch (command[0]) {
    case '1':
      if (command[1] == '0' && command[2] == '0')
        return false;
      else
        return true;
    case '2':
      hotal[command[1] - '0'] = command[2] - '0';
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '3':
      hotal[command[1] - '0'] += command[2] - '0';
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '4':
      hotal[command[1] - '0'] *= command[2] - '0';
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '5':
      hotal[command[1] - '0'] = hotal[command[2] - '0'];
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '6':
      hotal[command[1] - '0'] += hotal[command[2] - '0'];
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '7':
      hotal[command[1] - '0'] *= hotal[command[2] - '0'];
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '8':
      hotal[command[1] - '0'] = memory[hotal[command[2] - '0']];
      hotal[command[1] - '0'] %= 1000;
      return true;
    case '9':
      memory[hotal[command[2] - '0']] = hotal[command[1] - '0'];
      memory[hotal[command[2] - '0']] %= 1000;
      return true;
    case '0':
      if (hotal[command[2] - '0'] != 0) {
        nextPosition = hotal[command[1] - '0'];
      }
      return true;
  }
}

void run() {
  int nowPosition = 0;
  int nextPosition;

  runedCommandNum = 0;
  while (runCommandAt(nowPosition, nextPosition)) {
    // printf("nextPosition = %d, command = %03d\n", nextPosition,
    // memory[nextPosition]);
    nowPosition = nextPosition;
    runedCommandNum++;
  }
  runedCommandNum++;
  printf("%d\n", runedCommandNum);
}

int main() {
  int n;
  memset(memory, 0, sizeof(memory));
  memset(hotal, 0, sizeof(hotal));
  int now = 0;
  while (scanf("%d", &n) != EOF) {
    memory[now++] = n % 1000;
  }
  run();
  return 0;
}
