import java.util.*;
import java.util.Scanner;
public class Main
{

       static  int[][] dp;
static int[] offspring;
static int[] vert;
static int[] parent;
static int[] leaf;
static int n,k;
public static void main(String[] args)
{
Scanner cin=new Scanner(System.in);
n=cin.nextInt();
leaf=new int[n+1];
offspring=new int[n+1];
vert=new int[n+1];
parent=new int[n+1];
dp=new int[n+1][n+1];
boolean[] flag=new boolean[n+1];
int[] left=new int[n+1];
int[] right=new int[n+1];
for(int i=0;i<=n;i++)
for(int j=0;j<=n;j++)
{
if(j==0)
dp[i][j]=0;
else
dp[i][j]=-99999999;
}
k=cin.nextInt();
for(int i=0;i<n-k;i++)
{
int c=cin.nextInt();
if(c==0)
continue;
int temp=i+1;
int m=cin.nextInt();
vert[m]=cin.nextInt();
left[temp]=m;
parent[m]=temp;
offspring[temp]+=1;
temp=m;
for(int j=1;j<c;j++)
{
m=cin.nextInt();
right[temp]=m;
parent[m]=temp;
offspring[temp]+=2;
vert[m]=cin.nextInt();
temp=m;
}
}
for(int i=0;i<k;i++)
{
int m=i+n-k+1;
while(m!=0)
{
leaf[m]++;
m=parent[m];
}
}
for(int i=0;i<k;i++)
{
dp[i+n-k+1][1]=cin.nextInt()-vert[i+n-k+1];
if(offspring[i+n-k+1]==0)
flag[i+n-k+1]=true;
}
        while(!flag[1])
        {
for(int i=1;i<=n;i++)
{
if(!flag[i])
{
int l=left[i];
int r=right[i];
if(l==0&&flag[r])   //只有右孩子
{
for(int o=leaf[i];o>=0;o--)
for(int p=leaf[r];p>=0;p--)
{
if(o+p<=leaf[i]&&dp[r][p]+dp[i][o]>dp[i][o+p])
dp[i][o+p]=dp[r][p]+dp[i][o];
}
int o=0;
while(o<=leaf[r])
{
if(dp[r][o]>dp[i][o])
dp[i][o]=dp[r][o];
o++;
}
flag[i]=true;
}
if(r==0&&flag[l])   //只有左孩子
{
for(int o=leaf[i];o>=0;o--)
for(int p=leaf[l];p>=0;p--)
{
if(o+p<=leaf[i]&&dp[l][p]+dp[i][o]-vert[i]>dp[i][o+p])
dp[i][o+p]=dp[l][p]+dp[i][o]-vert[i];
}
int o=0;
while(o<=leaf[l])
{
if(dp[l][o]-vert[i]>dp[i][o])
dp[i][o]=dp[l][o]-vert[i];
o++;
}
flag[i]=true;
}
if(flag[r]&&flag[l])   //左右孩子
{
for(int o=leaf[r];o>=0;o--)
for(int p=leaf[l];p>=0;p--)
{
  if(p!=0)
  {
  if(o+p<=leaf[i]&&dp[l][p]+dp[r][o]-vert[i]>dp[i][o+p])
  dp[i][o+p]=dp[l][p]+dp[r][o]-vert[i];
  }
  if(p==0)
  {
  if(dp[r][o]>dp[i][o])
  dp[i][o]=dp[r][o];
  }

}
flag[i]=true;
}
}
}
}
        int i;
        for(i=k;i>=1;i--)
        {
         if(dp[1][i]>=0)
         break;
        }
        System.out.println(i);


}

}