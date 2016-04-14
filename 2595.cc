#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#define pb push_back
using namespace std;
const int N=2009;
const double eps=1e-7;
vector<int>p[N];
int c,n,q[50009];
int main(){
    int i,j,k,x,y,T,t;
    while(cin>>n>>c){
        for(i=0;i<=2000;i++)
            p[i].clear();
        for(i=1;i<=n;i++)
            scanf("%d",&x),p[x+1000].pb(i);
        for(i=1;i<=n;i++)
            scanf("%d",q+i);
        double L=1e9,R=-1e9;
        for(i=0;i<p[c+1000].size();i++){
            t=p[c+1000][i];
            L=min(L,0.0+q[t]);
            R=max(R,0.0+q[t]);
        }
        for(i=0;i<c+1000;i++)
            for(j=c+1000+1;j<=2000;j++){
                if(p[i].size()==0||p[j].size()==0)
                    continue;
                x=i-1000;y=j-1000;
                double px=double(c-y)/(x-y),py=1-px;
                double Lmax=-1e9,Rmax=-1e9,Lmin=1e9,Rmin=1e9;
                for(k=0;k<p[i].size();k++){
                    t=p[i][k];
                    Lmax=max(Lmax,q[t]*px);
                    Lmin=min(Lmin,q[t]*px);
                }
                for(k=0;k<p[j].size();k++){
                    t=p[j][k];
                    Rmax=max(Rmax,q[t]*py);
                    Rmin=min(Rmin,q[t]*py);
                }
                L=min(L,Lmin+Rmin);
                R=max(R,Lmax+Rmax);
            }
        printf("%.3lf %.3lf\n",L+eps,R+eps);
    }
    return 0;
}



