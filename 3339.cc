#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct player{
    int num;
    char name[25];
    char role;
    int year;
}p[30],ans[20],G[20],S[20],D[20],M[20];
int cmp(player a,player b){
    if(a.num==b.num) return a.year<b.year;
    return a.num<b.num;
}
int  main()
{
    int num,i,j,a,b,c;
    char name[25],role[5],ch;
    while(scanf("%d",&num),num)
    {
        i=0;
        scanf("%s%s",name,role);
        strcpy(p[i].name,name);
        p[i].num=num;
        p[i].role=role[0];
        p[i].year=0;
        while((ch=getchar())!='\n')
        {
            scanf("%d-%d",&a,&b);
            p[i].year+=(b-a+1);
        }
        i++;
        for(j=1;j<=21;j++)
        {
            scanf("%d%s%s",&num,name,role);
            strcpy(p[i].name,name);
            p[i].num=num;
            p[i].role=role[0];
            p[i].year=0;
            while((ch=getchar())!='\n')
            {
                scanf("%d-%d",&a,&b);
                p[i].year+=(b-a+1);
            }
            i++;
        }
        scanf("%d-%d-%d",&a,&b,&c);
        int tot=i,num=0,cnt=0,dnum=0,mnum=0,snum=0;
        for(i=0;i<tot;i++)
        {
             if(p[i].role=='G')       G[num++]=p[i];
             else if(p[i].role=='D')  D[dnum++]=p[i];
             else if(p[i].role=='M')  M[mnum++]=p[i];
             else                     S[snum++]=p[i];
        }
        if(num==0||dnum<a||mnum<b||snum<c) 
        {
            printf("IMPOSSIBLE TO ARRANGE\n\n");
            continue;
        }

        if(num==1) ans[cnt++]=G[0];
        else 
        {
            sort(G,G+num,cmp);
            ans[cnt++]=G[0];
        }

        sort(D,D+dnum,cmp);
        for(i=0;i<a;i++) ans[cnt++]=D[i];

        sort(M,M+mnum,cmp);
        for(i=0;i<b;i++) ans[cnt++]=M[i];

        sort(S,S+snum,cmp);
        for(i=0;i<c;i++)   ans[cnt++]=S[i];

        int max=0,id;
        for(i=0;i<cnt;i++)
        {
            if(ans[i].year>max||ans[i].year==max&&ans[i].num>ans[id].num)
            {
                max=ans[i].year;
                id=i;
            }
        }
        printf("%d %s %c\n",ans[id].num,ans[id].name,ans[id].role);
        for(i=0;i<cnt;i++)
        {
            if(i!=id)
            {
                printf("%d %s %c\n",ans[i].num,ans[i].name,ans[i].role);
            }
        }
        puts("");
    }
}


