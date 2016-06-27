#include<stdio.h>
#include<string.h>
#include<iostream>

#define M 22

using namespace std;
char name[M][M];
int m,n;

int acount[M];

int getNum(char* a)
{
    int i=0;
    for (i=0;i<m;i++)
    {
        if (!strcmp(name[i],a))
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int i,j,k;
    int num=0;
    while (true)
    {
        cin>>m>>n;
        if (m+n==0)
            break;

        num++;
        for (i=0;i<m;i++)
        {
            scanf("%s",name[i]);
        }

        for(i=0;i<=m;i++){
            acount[i]=0;
        }

        char a1[20];
        char a2[20];
        int x;
        int b1,b2;
        for (i=0;i<n;i++)
        {
            scanf("%s%s%d",a1,a2,&x);
            b1=getNum(a1);
            b2=getNum(a2);
            acount[b1]-=x;
            acount[b2]+=x;
        }

        cout<<"Case #"<<num<<endl;
        for (i=1;i<m;i++)
        {
            if (!acount[i])continue;
            if (acount[i]>0)
            {
                printf("%s %s %d\n",name[i],name[0],acount[i]);

            }
            else
            {
                printf("%s %s %d\n",name[0],name[i],-acount[i]);
            }
        }
        printf("\n");
    }
}



