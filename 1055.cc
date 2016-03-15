#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

struct Bundle {
  int letter_cnt, bun_cnt;
};

Bundle buns[100000];
char buffer[10], invalid_record[100000][10];
int invalid_cnt, zip_cnt[100000], total_letters, total_buns;

bool M[100000];

bool validity_check(char buffer[]) {
  //位数检查
  if (strlen(buffer) != 5) {
    return false;
  }

  //数字检查
  for (int i = 0; i < 5; i++) {
    if (buffer[i] < '0' || buffer[i] > '9') {
      return false;
    }
  }

  //全0检查
  bool flag = true;
  for (int i = 0; i < 5; ++i) {
    if (buffer[i] != '0') {
      flag = false;
      break;
    }
  }
  if (flag) {
    return false;
  }
  return true;
}

void process1(void) {
  //同5位10份以上打包
  for (int i = 10000; i <= 99999; ++i) {
    if (zip_cnt[i] >= 10) {
      while (zip_cnt[i] >= 15) {
        buns[i].letter_cnt += 15;
        ++buns[i].bun_cnt;
        total_letters += 15;
        ++total_buns;
        zip_cnt[i] -= 15;
      }
      if (zip_cnt[i] >= 10) {
        buns[i].letter_cnt += zip_cnt[i];
        ++buns[i].bun_cnt;
        total_letters += zip_cnt[i];
        ++total_buns;
        zip_cnt[i] = 0;
      }
    }
  }

  //按序输出
  printf("ZIP         LETTERS     BUNDLES\n");
  puts("");
  for (int i = 10000; i <= 99999; ++i) {
    if (buns[i].letter_cnt != 0) {
      printf("%d%12d%12d\n", i, buns[i].letter_cnt, buns[i].bun_cnt);
    }
  }
  puts("");

  //清空三位数的桶
  for (int i = 100; i <= 999; ++i) {
    buns[i].letter_cnt = buns[i].bun_cnt = 0;
  }
}

void process2(void) {
  //同3位10份以上打包
  for (int i = 100; i <= 999; ++i) {
    int temp[100][2];
    int cnt = 0, letter_cnt = 0;
    for (int j = 0; j <= 99; ++j) {
      int num = i * 100 + j;
      if (zip_cnt[num] > 0) {
        temp[cnt][0] = num;
        temp[cnt][1] = zip_cnt[num];
        letter_cnt += zip_cnt[num];
        zip_cnt[num] = 0;
        ++cnt;
      }
    }
    while (letter_cnt >= 15) {
      ++buns[i].bun_cnt;
      ++total_buns;
      buns[i].letter_cnt += 15;
      total_letters += 15;
      letter_cnt -= 15;
    }
    if (letter_cnt >= 10) {
      ++buns[i].bun_cnt;
      ++total_buns;
      buns[i].letter_cnt += letter_cnt;
      total_letters += letter_cnt;
      letter_cnt = 0;
    }
    while (letter_cnt > 0) {
      if (temp[cnt - 1][1] >= letter_cnt) {
        zip_cnt[temp[cnt - 1][0]] += letter_cnt;
        break;
      } else {
        zip_cnt[temp[cnt - 1][0]] += temp[cnt - 1][1];
        letter_cnt -= temp[cnt - 1][1];
        --cnt;
      }
    }
    if (buns[i].letter_cnt > 0) {
      printf("%dxx%12d%12d\n", i, buns[i].letter_cnt, buns[i].bun_cnt);
    }
  }
  puts("");
}

void process3(void) {
  // first class 输出
  for (int i = 10000; i <= 99999; ++i) {
    if (zip_cnt[i] > 0) {
      printf("%d%12d%12d\n", i, zip_cnt[i], 0);
      total_letters += zip_cnt[i];
    }
  }
  puts("");
}

void output_invalid(void) {
  //非法zip-code输出
  printf("INVALID ZIP CODES\n\n");
  for (int i = 0; i < invalid_cnt; ++i) {
    bool flag = true;
    for (int j = 0; j < i; ++j) {
      if (strcmp(invalid_record[i], invalid_record[j]) == 0) {
        flag = false;
      }
    }
    if (flag) {
      printf("%s\n", invalid_record[i]);
    }
  }
}
int main(void) {
  invalid_cnt = 0;
  while (scanf("%s", buffer) != EOF) {
    if (validity_check(buffer)) {
      //桶排序
      int num = 0;
      for (int i = 0; i < 5; ++i) {
        num = num * 10 + buffer[i] - '0';
      }
      ++zip_cnt[num];
    } else {
      strcpy(invalid_record[invalid_cnt], buffer);
      ++invalid_cnt;
    }
  }

  process1();
  process2();
  process3();
  printf("TOTALS%11d%12d\n\n", total_letters, total_buns);
  output_invalid();

  return 0;
}
