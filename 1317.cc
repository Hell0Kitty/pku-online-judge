#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxl 75

int key;
char cipher_text[maxl];
char plain_text[maxl];

bool is_letter(char ch) { return ch <= 'z' && ch >= 'a'; }

int get_code(char ch) {
  if (is_letter(ch)) return ch - 'a' + 1;
  if (ch == '_') return 0;
  if (ch == '.') return 27;
  return -1;
}

char get_text(int a) {
  if (a <= 26 && a >= 1) return a + 'a' - 1;
  if (a == 0) return '_';
  if (a == 27) return '.';
  return -1;
}

int unify(int a, int w) { return (a % w + w) % w; }

int main() {
  while (scanf("%d", &key), key) {
    scanf("%s", cipher_text);
    int len = strlen(cipher_text);
    for (int i = 0; i < len; i++)
      plain_text[unify(key * i, len)] =
          get_text(unify(get_code(cipher_text[i]) + i, 28));
    plain_text[len] = 0;
    puts(plain_text);
  }
  return 0;
}
