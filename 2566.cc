#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define maxn 100005
#define INF 2000000000

typedef pair<int,int> pii;

int n,k;
pii a[maxn];

int Abs(int x) {
        return x > 0 ? x : -x;
}

void solve(int x) {
        int sum = 0,s = 0,pos = 1,v,ans = INF,l,r;
        //printf("ans = %d\n",ans);
        for(; s <= n && pos <= n;) {
                int tem = a[pos].first - a[s].first;
                //printf("tem = %d\n",tem);
                if( Abs(tem - x) < ans) {
                        ans = Abs(tem - x);
                        l = a[s].second;
                        r = a[pos].second;
                        v = tem;
                }

                if(tem > x) {
                        ++s;
                } else if(tem < x) {
                        ++pos;
                } else {
                        break;
                }
                if(s == pos) ++pos;

        }
        if(l > r) swap(l,r);

        printf("%d %d %d\n",v,l + 1,r);
}

int main() {

        while(~scanf("%d%d",&n,&k) ) {
                if(!n && !k) break;
                int sum = 0;
                a[0] = pii(0,0);
                for(int i = 1; i <= n; ++i) {
                        int ch;
                        scanf("%d",&ch);
                        sum += ch;
                        a[i] = make_pair(sum,i);

                }

                sort(a,a + n + 1);

                for(int i = 1; i <= k; ++i) {
                        int t;
                        scanf("%d",&t);
                        solve(t);
                }

        }
        return 0;
}



