#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  char s[100005], t[100005];
  while (scanf("%s%s", s, t) == 2) {
    int lena = strlen(s);
    int lenb = strlen(t);
    if (lena > lenb) {
      puts("No");
      continue;
    }

    int curb = 0;
    int cura = 0;
    for (; cura < lena;) {
      char flag = s[cura];
      for (; curb < lenb;) {
        if (t[curb] != flag)
          curb++;
        else {
          curb++;
          cura++;
          break;
        }
      }
      if (curb >= lenb) break;
    }
    if (curb >= lenb) {
      if (cura >= lena)
        puts("Yes");
      else
        puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}