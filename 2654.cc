#include<cstdio>
#include<map>
using namespace std;
typedef map<int,int> M;
char m1[20],m2[20];
int p1,p2,n,k;
int main(){
    while(scanf("%d",&n)&&n){
        scanf("%d",&k);
        M mw,ml;
        for(int i=0;i<k*n*(n-1)/2;++i){
            scanf("%d%s%d%s",&p1,m1,&p2,m2);
            if((m1[0]=='p'&&m2[0]=='r')||(m1[0]=='s'&&m2[0]=='p')||(m1[0]=='r'&&m2[0]=='s')) mw[p1]++,ml[p2]++;
            else if((m1[0]=='r'&&m2[0]=='p')||(m1[0]=='p'&&m2[0]=='s')||(m1[0]=='s'&&m2[0]=='r')) mw[p2]++,ml[p1]++;
        }
        int mid=0,num=0;
        for(int i=1;i<=n;++i) {ml[i]+=mw[i];if(ml[i]) num++;}
        for(int i=1;i<=n;++i){
            if(ml[i]&&num) mw[i]=(int)(((double)mw[i]/ml[i]+0.0005)*1000),mid+=mw[i],--num;
            else if(ml[i]&&!num) mw[i]=10000-mid;
        }
        for(int i=1;i<=n;++i) if(!ml[i]) puts("-");else printf("%.3lf\n",(double)mw[i]/1000);
        puts("");
    }
    return 0;
}


