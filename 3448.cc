#include <stdio.h>
#include <string.h>
#define N 10050
#define PLUS 1
#define SUB 2
char *hundred[10] = {"",  "C",  "CC",  "CCC",  "CD",
                     "D", "DC", "DCC", "DCCC", "CM"};
char *ten[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char *one[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
int reg[10];

void analysis(char *cmd);

int decode(char c);
int roman_to_int(char *rm);
void int_to_roman(int n, char *rm);
void reset_reg();
void substr(char *dest, char *src, int begin, int end);

int main() {
  char cmd[N];
  reset_reg();
  while (1) {
    scanf("%s", cmd);
    if (!strcmp("QUIT", cmd)) {
      printf("Bye");
      break;
    }
    if (!strcmp("RESET", cmd)) {
      reset_reg();
      printf("Ready\n");
    } else
      analysis(cmd);
  }
  return 0;
}
void analysis(char *cmd) {
  int i, reg_id, pbegin, result = 0, t, mode = PLUS;
  char result_rm[10000], str[10000], num[10000];
  sscanf(cmd, "%d=%s", &reg_id, str);
  i = -1;
  pbegin = 0;
  do {
    i++;
    if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
      substr(num, str, pbegin, i - 1);
      if (num[0] >= '0' && num[0] <= '9') {
        sscanf(num, "%d", &t);
        t = reg[t];
        if (t == -1) {
          printf("Error\n");
          return;
        }
      } else
        t = roman_to_int(num);
      if (mode == PLUS)
        result += t;
      else if (mode == SUB)
        result -= t;
      pbegin = i + 1;
      mode = (str[i] == '+' ? PLUS : SUB);
    }
  } while (str[i] != '\0');
  if (result > 10000 || result < 0) {
    printf("Error\n");
    return;
  }
  reg[reg_id] = result;
  int_to_roman(result, result_rm);
  printf("%d=%s\n", reg_id, result_rm);
}
int roman_to_int(char *rm) {
  int i, len = strlen(rm), result = 0, t1, t2;
  if (rm[0] == 'O') return 0;
  for (i = 0; i < len; i++) {
    t1 = decode(rm[i]);
    if (i > 0) {
      t2 = decode(rm[i - 1]);
      if (t2 < t1) result -= t2;
    }
    if (i < len - 1) {
      t2 = decode(rm[i + 1]);
      if (t2 > t1) continue;
      result += t1;
    }
  }
  result += decode(rm[len - 1]);
  return result;
}
void int_to_roman(int n, char *rm) {
  char result[1000];
  int d, i, rest;
  if (!n) {
    strcpy(rm, "O");
    return;
  }
  memset(rm, 0, sizeof(char) * 1000);
  memset(result, 0, sizeof(char) * 1000);
  rest = n;
  if (rest / 1000) {
    d = rest / 1000;
    for (i = 0; i < d; i++) result[i] = 'M';
    result[d] = '\0';
    rest = rest - d * 1000;
  }
  if (rest / 100) {
    d = rest / 100;
    rest = rest - d * 100;
    strcat(result, hundred[d]);
  }
  if (rest / 10) {
    d = rest / 10;
    rest = rest - d * 10;
    strcat(result, ten[d]);
  }
  if (rest) strcat(result, one[rest]);

  strcpy(rm, result);
}
int decode(char c) {
  switch (c) {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
  }
  return -1;
}
void reset_reg() {
  int i;
  for (i = 0; i < 10; i++) reg[i] = -1;
}
void substr(char *dest, char *src, int begin, int end) {
  int i, pos = 0;
  for (i = begin; i <= end; i++) {
    dest[pos] = src[i];
    pos++;
  }
  dest[pos] = '\0';
}
