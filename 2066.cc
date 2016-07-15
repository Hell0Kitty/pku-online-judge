#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 55
const int INF = (1<<30);

struct node
{
 int x, y;
}p[MAX];

int n;
int dp[MAX][MAX];

inline int max(int a, int b)
{
 return a > b ? a : b;
}

inline int min(int a, int b)
{
 return a < b ? a : b;
}

inline int multiply(node A, node B)
{
 return A.x*B.y - A.y*B.x;
}

inline int area(node A, node B, node C)
{
 int size = multiply(A, B)+multiply(B, C)+multiply(C, A);
 return size > 0 ? size : (-size);
}

inline bool judge(int i, int j, int k)
{
 int size = area(p[i], p[j], p[k]);
 for(int t = 1; t <= n; ++t)
 {
  if(t == i || t == j || t == k) continue;
  int temp = area(p[i], p[j], p[t])+area(p[i], p[k], p[t])+area(p[j], p[k], p[t]);
  if(size == temp) return false;
 }
 return true;
}

int main()
{
 int i, j, k;
// freopen("input.txt", "r", stdin);
 int caseNum;
 scanf("%d", &caseNum);
 while(caseNum--)
 {
  scanf("%d", &n);
  for(i = 1; i <= n; ++i)
   scanf("%d %d", &p[i].x, &p[i].y);

  memset(dp, 0, sizeof(dp));
  for(i = 1; i <= n-2; ++i)
   dp[i][i+2] = area(p[i], p[i+1], p[i+2]);

  int temp1, temp2, temp3;
  for(int q = 3; q < n; ++q)
  {
   for(i = 1; i+q <= n; ++i)
   {
    j = i+q;
    temp1 = INF;
    if( judge(i, i+1, j) )
     temp1 = max(area(p[i], p[i+1], p[j]), dp[i+1][j]);
    if( judge(i, j-1, j) )
    {
     temp2 = max(area(p[i], p[j-1], p[j]), dp[i][j-1]);
     temp1 = min(temp1, temp2);
    }
    for(k = i+2; k <= j-2; ++k)
    {
     if( !judge(i, j, k) ) continue;
     temp2 = area(p[i], p[j], p[k]);
     temp3 = dp[i][k];
     temp2 = max(temp2, temp3);
     temp3 = dp[k][j];
     temp2 = max(temp2, temp3);

     temp1 = min(temp1, temp2);
    }
    dp[i][j] = temp1;
   }
  }

  printf("%d", dp[1][n]/2);
  if(dp[1][n] % 2 == 1) printf(".5\n");
  else printf(".0\n");
 }

 return 0;
}



