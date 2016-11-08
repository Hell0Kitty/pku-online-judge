#include <iostream>
#include <ctype.h>
using namespace std;
int main() {
  char S[30000];
  char S1[10000], S2[10000];
  int N, t, len, s1, e1, s2, e2, s3, e3, i, g, h;
  int flag1, flag2, flag3;
  float a, b;
  scanf("%d", &N);
  getchar();
  for (t = 1; t <= N; t++) {
    flag1 = flag2 = flag3 = 0;
    a = b = 0;
    gets(S);
    len = strlen(S);
    for (i = 0; i < len; i++) {
      if (S[i] == 'U' && S[i + 1] == '=') {
        s1 = i;
        flag1 = 1;
      } else if (S[i] == 'V' &&
                 ((S[i - 1] >= '0' && S[i - 1] <= '9') ||
                  (S[i - 1] == 'm' || S[i - 1] == 'k' || S[i - 1] == 'M'))) {
        e1 = i;
      } else if (S[i] == 'I' && S[i + 1] == '=') {
        s2 = i;
        flag2 = 1;
      } else if (S[i] == 'A' &&
                 ((S[i - 1] >= '0' && S[i - 1] <= '9') ||
                  (S[i - 1] == 'm' || S[i - 1] == 'k' || S[i - 1] == 'M')))
        e2 = i;
      else if (S[i] == 'P' && S[i + 1] == '=') {
        s3 = i;
        flag3 = 1;
      } else if (S[i] == 'W' &&
                 ((S[i - 1] >= '0' && S[i - 1] <= '9') ||
                  (S[i - 1] == 'm' || S[i - 1] == 'k' || S[i - 1] == 'M')))
        e3 = i;
    }
    if (flag1 && flag2) {
      for (g = 0, h = s1 + 2; h <= e1; h++) S1[g++] = S[h];
      S1[g] = '\0';
      a = atof(S1);

      if (S[e1 - 1] == 'm')
        a = a * 0.001;
      else if (S[e1 - 1] == 'k')
        a = a * 1000.0;
      else if (S[e1 - 1] == 'M')
        a = a * 1000000.0;
      for (g = 0, h = s2 + 2; h <= e2; h++) S2[g++] = S[h];
      S2[g] = '\0';

      b = atof(S2);
      if (S[e2 - 1] == 'm')
        b = b * 0.001;
      else if (S[e2 - 1] == 'k')
        b = b * 1000.0;
      else if (S[e2 - 1] == 'M')
        b = b * 1000000.0;
      printf("Problem #%d\n", t);
      printf("P=%.2fW\n\n", a * b);
    }
    if (flag1 && flag3) {
      for (g = 0, h = s3 + 2; h <= e3; h++) S1[g++] = S[h];
      S1[g] = '\0';

      a = atof(S1);
      if (S[e3 - 1] == 'm')
        a = a * 0.001;
      else if (S[e3 - 1] == 'k')
        a = a * 1000.0;
      else if (S[e3 - 1] == 'M')
        a = a * 1000000.0;

      for (g = 0, h = s1 + 2; h < e1; h++) S2[g++] = S[h];
      S2[g] = '\0';

      b = atof(S2);
      if (S[e1 - 1] == 'm')
        b = b * 0.001;
      else if (S[e1 - 1] == 'k')
        b = b * 1000.0;
      else if (S[e1 - 1] == 'M')
        b = b * 1000000.0;
      printf("Problem #%d\n", t);
      printf("I=%.2fA\n\n", a / b);
    }
    if (flag2 && flag3) {
      for (g = 0, h = s3 + 2; h <= e3; h++) S1[g++] = S[h];
      S1[g] = '\0';

      a = atof(S1);
      if (S[e3 - 1] == 'm') {
        a = a * 0.001;
      } else if (S[e3 - 1] == 'k') {
        a = a * 1000.0;
      } else if (S[e3 - 1] == 'M') {
        a = a * 1000000.0;
      }
      for (g = 0, h = s2 + 2; h <= e2; h++) S2[g++] = S[h];
      S2[g] = '\0';

      b = atof(S2);

      if (S[e2 - 1] == 'm') {
        b = b * 0.001;
      } else if (S[e2 - 1] == 'k') {
        b = b * 1000.0;
      } else if (S[e2 - 1] == 'M') {
        b = b * 1000000.0;
      }

      printf("Problem #%d\n", t);
      printf("U=%.2fV\n\n", a / b);
    }
  }
}
