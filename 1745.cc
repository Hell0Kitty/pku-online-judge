#include <iostream>
using namespace std;
int dp[10001][101]={0};//dp表示的为dp[i][j]前i个数是否能够组成余数为j，是则为1
int num[10000];
int main()
{
  int i,j;
  int n , k;
  scanf("%d%d",&n,&k);

  for(i = 0; i < n ; i++)
  {
    scanf("%d",&num[i]);
    if(num[i]<0)
      num[i]= -num[i];
    num[i] = num[i]%k;
  }
  dp[0][num[0]] = 1;
  for(i = 1 ; i <n ; i++ )
  {
    for(j = 0 ; j <=k ; j++)
      if(dp[i-1][j])
      {
        dp[i][(j+num[i])%k] = 1;
        dp[i][(k+j-num[i])%k] = 1;//注意这里

      }

  }
  if(dp[n-1][0])
     printf("Divisible\n");
    else
        printf("Not divisible\n");
    return 0;

}