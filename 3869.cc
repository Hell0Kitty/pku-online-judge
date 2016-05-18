#include <iostream>
using namespace std;
char s[128];
int main() {
  scanf("%s", s);
  int l = strlen(s);
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < l; ++i)
    if (s[i] == '1') ++c;
  d = l;
  for (int i = 0; i < l; ++i)
    if (s[i] == '0' && s[(i + 1) % l] == '1') ++a;
  b = l - c;
  if (a * d < b * c)
    puts("SHOOT");
  else if (a * d > b * c)
    puts("ROTATE");
  else
    puts("EQUAL");
  return 0;
}
