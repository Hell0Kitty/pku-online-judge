#include<cstdio>
#include<algorithm>
#include<cstring>

short w,i,j,k;
char the[]="0A23456789XJQK";
short aa[20];
short flag;

struct node
{
    char st[5];
    short cd;
    inline void scan()
    {
        scanf("%s",st);
        cd=strchr(the,st[1])-the;
        st[1]=0;
    }
    inline void print()
    {
        printf("%s:%hd\n",st,cd);
    }
}hd[6];

bool operator < (const node &a,const node &b)
{
    return a.cd<b.cd;
}

int main()
{
    scanf("%hd",&w);
    while(w--)
    {
        for(i=0;i<5;++i)
            hd[i].scan();
        std::sort(hd,hd+5);
        for(i=1;i<5;++i)
            if(hd[i].st[0]!=hd[0].st[0])
                break;
        if(i==5)
        {
            for(i=1;i<5;++i)
                if(hd[i].cd-hd[i-1].cd!=1)
                    break;
            if(i==5)
            {
                puts("1000");
                continue;
            }
            else
                if(hd[0].cd==1 && hd[1].cd==10)
                {
                    for(i=2;i<5;++i)
                        if(hd[i].cd-hd[i-1].cd!=1)
                            break;
                    if(i==5)
                    {
                        puts("1000");
                        continue;
                    }
                }
        }
        memset(aa,0,sizeof(aa));
        for(i=0;i<5;++i)
            ++aa[hd[i].cd];
        flag=0;
        for(i=1;i<20;++i)
        {
            if(aa[i]==2)
                flag|=1;
            if(aa[i]==3)
                flag|=2;
            if(aa[i]==4)
                flag|=4;
        }
        if(flag==4)
        {
            puts("750");
            continue;
        }
        else
            if(flag==3)
            {
                puts("500");
                continue;
            }
        for(i=1;i<5;++i)
            if(hd[i].st[0]!=hd[0].st[0])
                break;
        if(i==5)
        {
            puts("350");
            continue;
        }
        for(i=1;i<5;++i)
            if(hd[i].cd-hd[i-1].cd!=1)
                break;
        if(i==5)
        {
            puts("250");
            continue;
        }
        else
            if(hd[0].cd==1 && hd[1].cd==10)
            {
                for(i=2;i<5;++i)
                    if(hd[i].cd-hd[i-1].cd!=1)
                        break;
                if(i==5)
                {
                    puts("250");
                    continue;
                }
            }
        if(flag==2)
        {
            puts("200");
            continue;
        }
        flag=0;
        for(i=1;i<20;++i)
            if(aa[i]==2)
                ++flag;
        if(flag==2)
        {
            puts("100");
            continue;
        }
        else
            if(flag==1)
            {
                puts("50");
                continue;
            }
        puts("0");
    }
    return 0;
}


