#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 50

int n;
char st[maxn];
char match[1000];
bool p, m;

bool isp() {
  for (int i = 0; i < n / 2; i++)
    if (st[i] != st[n - i - 1]) return false;
  return true;
}

bool ism() {
  for (int i = 0; i < n / 2 + 1; i++)
    if (st[i] != match[st[n - i - 1]]) return false;
  return true;
}

int main() {
  // freopen("t.txt", "r", stdin);
  memset(match, -1, sizeof(match));
  match['A'] = 'A';
  match['E'] = '3';
  match['H'] = 'H';
  match['I'] = 'I';
  match['J'] = 'L';
  match['L'] = 'J';
  match['M'] = 'M';
  match['O'] = 'O';
  match['S'] = '2';
  match['T'] = 'T';
  match['U'] = 'U';
  match['V'] = 'V';
  match['W'] = 'W';
  match['X'] = 'X';
  match['Y'] = 'Y';
  match['Z'] = '5';
  match['1'] = '1';
  match['2'] = 'S';
  match['3'] = 'E';
  match['5'] = 'Z';
  match['8'] = '8';
  while (scanf("%s", st) != EOF) {
    n = strlen(st);
    p = isp();
    m = ism();
    printf("%s", st);
    if (!p && !m)
      printf(" -- is not a palindrome.\n");
    else if (p && !m)
      printf(" -- is a regular palindrome.\n");
    else if (!p && m)
      printf(" -- is a mirrored string.\n");
    else
      printf(" -- is a mirrored palindrome.\n");
    putchar('\n');
  }
  return 0;
}
