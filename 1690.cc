#include <cstdio>

#include <cstring>

using namespace std;

int main()

{
  int T;

  for (scanf("%d ", &T); T; T--)

  {
    char s[1000];

    char ans[1000];

    int st[1000];

    gets(s);

    int len, i, j, num = 0;

    for (i = j = 0; s[i]; i++)

    {
      if (s[i] == ' ')

        continue;

      else if (s[i] == '(')

      {
        if (j > 0 && ans[j - 1] != '+' && ans[j - 1] != '(')

          ans[j++] = '(', st[num++] = 1;

        else

          st[num++] = -1;

      }

      else if (s[i] == ')')

      {
        if (st[num - 1] == -1)

          num--;

        else if (ans[j - 1] == '(' || (j - 2 >= 0 && ans[j - 2] == '('))

        {
          if (ans[j - 1] == '(')

            j--;

          else

            ans[j - 2] = ans[j - 1], j--;

          num--;

        }

        else

          ans[j++] = ')', num--;

      }

      else

        ans[j++] = s[i];
    }

    ans[j] = '\0';

    puts(ans);
  }

  return 0;
}
