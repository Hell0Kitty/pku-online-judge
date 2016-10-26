#include<stdio.h>
#include<string.h>
char str[100];
int main()
{
    while(gets(str))
    {
        int f=0;
        int len=strlen(str);
        for(int i=0; i<len;)
        {

            if(str[i]=='E'&&str[i+1]=='O'&&str[i+2]=='F')
            {
                f=1;
                break;
            }
            if((str[i]<'a'||str[i]>'z')&&str[i]!=' ')
            {
                i++;
                continue;
            }

            if(str[i]=='d'&&str[i+1]=='d')
            {
                printf("p");
                i+=2;
                continue;
            }
            else if(str[i]=='e'&&str[i+1]=='i')
            {
                if(str[i-1]=='c')
                {
                    printf("ei");
                }
                else
                {
                    printf("ie");
                }
                i+=2;
                continue;
            }
            else if(str[i]=='p')
            {
                if(str[i+1]=='i'&&str[i+2]=='n'&&str[i+3]=='k')
                {
                    printf("floyd");
                    i+=4;
                    continue;
                }
            }
            printf("%c",str[i]);
            i++;
        }
        if(f==1)
            break;
        printf("\n");

    }
    return 0;
}



