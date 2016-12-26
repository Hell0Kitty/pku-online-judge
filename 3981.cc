#include <stdio.h>

char str[1002];

int main()

{
  int i;

  while (gets(str) != NULL)

  {
    i = 0;

    for (i = 0; str[i] != '\0'; i++)

      if (str[i] == 'y' && str[i + 1] == 'o' && str[i + 2] == 'u')

      {
        printf("we");

        i += 2;

      }

      else

      {
        printf("%c", str[i]);
      }

    printf("\0");

    printf("\n");
  }

  return 0;
}
