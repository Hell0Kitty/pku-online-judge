#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int main()
{
    double tn,td,ti,k,ans=INF,tj;
    int i,j,n,d,rn,rd;
    cin>>n>>d;
    tn=n,td=d;
    k=tn/td;
    for(i=1;i<=32767;i++)
    {
        if(i%n==0)
        {
            j=i/n*d;
            if(j-1<=32767)
            {
                if(fabs(double(i)/double(j-1)-k)<ans)
                {
                    ans=fabs(double(i)/double(j-1)-k);
                    rn=i,rd=j-1;
                }
            }
            if(j+1<=32767)
            {
                if(fabs(double(i)/double(j+1)-k)<ans)
                {
                    ans=fabs(double(i)/double(j+1)-k);
                    rn=i,rd=j+1;
                }
            }
        }
        else
        {
            ti=(double)i;
            tj=i/k;
            tj=floor(tj);
            //if(i==21845) cout<<tj<<endl;
            if(int(tj+0.5)>32767) break;
            if(fabs(ti/tj-k)<ans)
            {
                ans=fabs(ti/tj-k);
                rn=i,rd=int(tj+0.5);
            }
            tj+=1;
            if(int(tj+0.5)>32767) continue;
            if(fabs(ti/tj-k)<ans)
            {
                ans=fabs(ti/tj-k);
                rn=i,rd=int(tj+0.5);
            }
        }
    }
    //cout<<ans<<endl;
    cout<<rn<<' '<<rd<<endl;
    return 0;
}


