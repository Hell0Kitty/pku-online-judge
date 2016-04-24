#include<cstdio>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;

const int MAXN=110000;
int a[MAXN],b[MAXN],p[MAXN];
long long c[MAXN],d[MAXN];
vector<int> hash;

long long findp(int x) {
    if(p[x]==-1) {
        return x;
    }
    int ret=findp(p[x]);
    d[x]+=d[p[x]];
    return p[x]=ret;
}

int main() {
    int m;
    while(scanf("%d",&m)==1) {
        hash.clear();
        memset(p,-1,sizeof(p));
        memset(d,0,sizeof(d));
        for(int i=0; i<m; i++) {
            scanf("%d%d%lld",&a[i],&b[i],&c[i]);
            if(a[i]>b[i]) {
                swap(a[i],b[i]);
            }
            hash.push_back(a[i]-1);
            hash.push_back(b[i]);
        }
        sort(hash.begin(),hash.end());
        hash.erase(unique(hash.begin(),hash.end()),hash.end());
        for(int i=0; i<m; i++) {
            a[i]=lower_bound(hash.begin(),hash.end(),a[i]-1)-hash.begin();
            b[i]=lower_bound(hash.begin(),hash.end(),b[i])-hash.begin();
            int px=findp(a[i]);
            int py=findp(b[i]);
            if(px==py) {
                if(d[b[i]]-d[a[i]]==c[i]) {
                    puts("Accept");
                } else {
                    printf("Bug Detected %lld\n",d[b[i]]-d[a[i]]);
                }
            } else {
                if(px>py) {
                    swap(a[i],b[i]);
                    swap(px,py);
                    c[i]=-c[i];
                }
                d[py]=d[a[i]]+c[i]-d[b[i]];
                p[py]=px;
                puts("Accept");
            }
        }
    }
    return 0;
}
