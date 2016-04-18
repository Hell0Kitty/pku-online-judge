# include <iostream>
# include <string>
# include <cstring>
# include <cstdio>
using namespace std;
struct piece
{
    char type[4][5],id[5];
    int start;
    void TurnRight()
    {
        start=(start+1)%4;
    }
    char *get(int pos)
    {
        return type[(start+pos)%4];
    }
    void print(char *first,char *second,char *third)
    {
        strcat(first,"   ");
        strcat(first,get(0));
        strcat(first,"   ");
        strcat(second,get(3));
        strcat(second," ");
        strcat(second,id);
        strcat(second," ");
        strcat(second,get(1));
        strcat(second," ");
        strcat(third,"   ");
        strcat(third,get(2));
        strcat(third,"   ");
    }
}data[9];
piece ans[9];
bool used[9];
inline bool match(char *a,char *b)
{
    return a[0]==b[0]&&(a[1]=='L'&&b[1]=='R'||a[1]=='R'&&b[1]=='L');
}
bool search(int pos)
{
    if(pos==9) return true;
    else
    {
        switch(pos)
        {
        case 0:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                     ans[pos]=data[i];
                     used[i]=true;
                     if(search(pos+1)) return true;
                     used[i]=false;
                }
            break;
        case 1:
            for(int i=0;i<9;i++)
               if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(2),ans[0].get(0))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 2:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(3),ans[0].get(1))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 3:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(0),ans[0].get(2))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 4:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(1),ans[0].get(3))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 5:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(1),ans[1].get(3))&&match(ans[pos].get(2),ans[4].get(0))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 6:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(3),ans[1].get(1))&&match(ans[pos].get(2),ans[2].get(0))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 7:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(0),ans[2].get(2))&&match(ans[pos].get(3),ans[3].get(1))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        case 8:
            for(int i=0;i<9;i++)
                if(!used[i])
                {
                    ans[pos]=data[i];
                    used[i]=true;
                    for(int j=0;j<4;j++)
                    {
                        if(match(ans[pos].get(0),ans[4].get(2))&&match(ans[pos].get(1),ans[3].get(3))&&search(pos+1)) return true;
                        ans[pos].TurnRight();
                    }
                    used[i]=false;
                }
            break;
        };
        return false;
    }
}
int main()
{
    int id;
    while(true)
    {
        scanf("%d",&id);
        if(!id) break;
        for(int i=0;i<9;i++)
        {
            scanf("%s",data[i].id);
            data[i].start=0;
            for(int j=0;j<4;j++)
                scanf("%s",data[i].type[j]);
        }
        printf("%d:\n",id);
        memset(used,false,sizeof(used));
        switch(search(0))
        {
        case true:
            {
                char first[100],second[100],third[100];
                first[0]=second[0]=third[0]='\0';
                ans[5].print(first,second,third);
                ans[1].print(first,second,third);
                ans[6].print(first,second,third);
                printf("%s\n%s\n%s\n\n",first,second,third);
                first[0]=second[0]=third[0]='\0';
                ans[4].print(first,second,third);
                ans[0].print(first,second,third);
                ans[2].print(first,second,third);
                printf("%s\n%s\n%s\n\n",first,second,third);
                first[0]=second[0]=third[0]='\0';
                ans[8].print(first,second,third);
                ans[3].print(first,second,third);
                ans[7].print(first,second,third);
                printf("%s\n%s\n%s\n\n",first,second,third);
            }
            break;
        case false:
            printf("No Solution\n\n");
            break;
        };
    }
    return 0;
}


