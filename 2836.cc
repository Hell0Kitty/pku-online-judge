#include<iostream>
#include<sstream>
#include<map>
#include<cmath>
#include<fstream>
#include<queue>
#include<vector>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<bitset>
#include<ctime>
#include<string>
#include<cctype>
#include<iomanip>
#include<algorithm>
using namespace std  ;
//#define INT __int64
#define L(x)  (x * 2)
#define R(x)  (x * 2 + 1)
const int INF = 0x3f3f3f3f ;
const double esp = 0.0000000001 ;
const double PI = acos(-1.0) ;
const int mod = 1000000007 ;
const int MY = 25 ;
const int MX = (1<<15) + 5 ;
int n ,num ;
int dp[MX] ;
struct node
{
    int x ,y ;
}T[MY] ;
struct NODE
{
    int v ,c ;
}B[MY*MY] ;
void change(int a ,int b) // 澶勭悊鐭╁舰
{
    int S = (1<<a) + (1<<b) ;
    for(int i = 0 ;i < n ; ++i)
      if(i != a && i != b && (T[a].x - T[i].x)*(T[i].x - T[b].x) >= 0 && (T[a].y - T[i].y)*(T[i].y - T[b].y) >= 0)
          S |= (1<<i) ;
    int sum = 0 ;
    if(T[a].x == T[b].x)
        sum = abs(T[a].y - T[b].y) ;
    else if(T[a].y == T[b].y)
        sum = abs(T[a].x - T[b].x) ;
    else
        sum = abs(T[a].x - T[b].x)*abs(T[a].y - T[b].y) ;
    B[num].v = S ;
    B[num++].c = sum ;
}
void DP_SC()
{
    num = 0 ;
    memset(dp ,-1 ,sizeof(dp)) ;
    for(int i = 0 ;i < n ; ++i)
      for(int j = i + 1 ;j < n ; ++j)
          change(i ,j) ;
    dp[0] = 0 ;
    for(int S = 0 ;S < (1<<n) ; ++S)
      if(dp[S] != -1)
      {
          for(int i = 0 ;i < num ; ++i)
          {
              int S1 = B[i].v ;
              int cost = B[i].c ;
              if(dp[S|S1] == -1)
                      dp[S|S1] = dp[S] + cost ;
              else    dp[S|S1] = min(dp[S|S1] ,dp[S] + cost) ;
          }
      }
    cout<<dp[(1<<n)-1]<<endl ;
}
int main()
{
    while(scanf("%d" ,&n) ,n)
    {
        for(int i = 0 ;i < n ; ++i)
          scanf("%d%d" ,&T[i].x ,&T[i].y) ;
        DP_SC() ;
    }
    return 0 ;
}



