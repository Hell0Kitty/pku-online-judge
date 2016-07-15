#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<deque>
#include<cmath>
#include<vector>
#include<string>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#define REP(i,s,t) for(int i=(s);i<=(t);i++)
#define REP2(i,t,s) for(int i=(t);i>=s;i--)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;

const int N=150000;
int n;
struct song
{
  int id;
  double len,fre;

}s[N];
bool cmp(song a,song b)
{
  return a.len*b.fre<a.fre*b.len;
}
int main()
{
  #ifdef ONLINE_JUDGE
  #else
    freopen("test.in","r",stdin);
  #endif
  while(~scanf("%d",&n))
  {
    REP(i,1,n)
    {
      scanf("%d%lf%lf",&s[i].id,&s[i].len,&s[i].fre);
    }
    int Q;
    scanf("%d",&Q);
    sort(s+1,s+1+n,cmp);
    printf("%d\n",s[Q].id);
  }
  return 0;
}



