#include <stdio.h>
#include <string.h>

int n;
char string[21];

int searching(int pos)
{
    if (string[pos] == '0' || pos == n) 
	{
        return 0;
    }
    if (string[pos] >= 'A' && string[pos] <= 'Z') 
	{
        int x = searching(pos+1);
        if (x > 9) 
            string[pos] = (x % 10) + '0';
        else
            string[pos] = x + '0';

        return 1 + x;
    }
    if (string[pos] >= '1' && string[pos] <= '9') 
	{
        if (pos + string[pos] - '0' < n) 
		{
            int x = searching(pos+string[pos]-'0');
            string[pos] -= 1;
            return 1 + x;
        }
        else 
		{
            int x = searching(pos+1);
            string[pos] -= 1;
            return 1 + x;
        }
    }
}

int main()
{
    char str[10];
    while (1) 
	{
        scanf("%s", str);
        if (strcmp(str, "ENDOFINPUT") == 0)
            break;
        scanf("%d\n",&n);
        scanf("%s", string);
        scanf("%s", str);

        searching(0);
        printf("%s\n", string);
    }

    return 0;
}


