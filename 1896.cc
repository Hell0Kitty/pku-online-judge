#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

string data;
int level = 1, len;
bool flag;
int main()
{
	while (getchar() != '{') ;
	printf("{\n    ");
	flag = false;
	while (getline(cin, data))
	{
		len = data.length();
		for (int i = 0; i < len; ++ i)
		{
			if (data[i] == ' ' || data[i] == 9) ;
			else if (data[i] == '{')
			{
				printf(" {\n");
				level ++;
				for (int j = 0; j < level; ++ j)
					printf("    ");
			}
			else if (data[i] == ';')
			{
				printf(";\n");
				flag = true;
			}
			else if (data[i] == '}')
			{
				level --;
				for (int i = 0; i < level; ++ i)
					printf("    ");
				putchar('}');
				flag = false;
			}
			else if (data[i] == ',') printf(", ");
			else
			{
				if (flag)
				{
					for (int i = 0; i < level; ++ i)
						printf("    ");
					flag = false;
				}
				putchar(data[i]);
			}
		}
		if (level == 0) break;
	}
	printf("\n");
}



