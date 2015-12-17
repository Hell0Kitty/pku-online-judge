
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

namespace {
using namespace std;

const int INFINITY = 0x7fffffff;

const int N_MAX = 10000;
const int W_MAX = 80;

int length[N_MAX + 1];

char words[N_MAX + 1][W_MAX];

int L;
int n = 0;

int f[N_MAX + 1];
int count[N_MAX + 1];
int space[N_MAX + 1];

void print(int no) {
  if (count[no] == 1)  // 只有一个单词的情况，直接输出
  {
    printf("%s\n", words[no]);
  } else {
    // 计算各单词间的空格数
    int spacenum, num;
    char space_format[16];  // 空格输出格式字符串

    spacenum = space[no] / (count[no] - 1) + 1;
    num = (count[no] - 1) - space[no] % (count[no] - 1);

    sprintf(space_format, "%%s%%%ds", spacenum);
    int i = 0;
    for (; i < num; i++) {
      printf(space_format, words[no + i], " ");
    }

    sprintf(space_format, "%%s%%%ds", spacenum + 1);
    for (; i < (count[no] - 1); i++) {
      printf(space_format, words[no + i], " ");
    }
    printf("%s\n", words[no + count[no] - 1]);
  }

  if (no + count[no] != n) {
    print(no + count[no]);
  }

  return;
}

#define square(x) ((x) * (x))

void format_text() {
  f[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    int curlen = length[i];
    f[i] = f[i + 1] + 500;
    count[i] = 1;
    space[i] = 0;

    for (int k = 2; k <= (n - i) && (curlen + length[i + k - 1] + 1) <= L;
         k++)  // 枚举所有可能与word[i]在同一行的单词
    {
      curlen += (length[i + k - 1] + 1);

      int space_num = L - curlen;

      // 剩余空格的最优分配方式
      int bestbad = square(space_num / (k - 1)) * (k - 1) +
                    (2 * (space_num / (k - 1)) + 1) * (space_num % (k - 1));

      if (f[i + k] + bestbad <= f[i]) {
        f[i] = f[i + k] + bestbad;
        count[i] = k;
        space[i] = space_num;
      }
    }
  }

  print(0);
}
}

int main() {
  char line[N_MAX];
  while (NULL != gets(line) && EOF != sscanf(line, "%d", &L)) {
    if (L == 0) break;

    n = 0;

    while (gets(line))  // 读入一行
    {
      if (line[0] < 33 ||
          126 <
              line[0])  // 判断空行，这里采用并未line[0]=='\0'判断空行，因为windows下的回车是两个字符
        break;

      int pos = 0;
      int t = 0;
      while (EOF != sscanf(&line[pos], "%s%n", words[n],
                           &t))  // 格式符\n表示本次读过的字节数
      {
        length[n] = strlen(words[n]);  // 记录各单词的长度
                ++n;

                pos += t; // 当前处理都得字符位置
                t = 0;
            }
        }

        format_text(); // 格式化文本，并输出

        printf("\n"); // 打印空行
    }

    return 0;
}