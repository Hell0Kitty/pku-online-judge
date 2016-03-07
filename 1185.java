/*题目描述：在一张n*m的方格中放置炮兵，要求相邻２格没有炮兵，求最多能放多少
 *开始因为没有想到好的方法，于是搜了一次．tle...
 *知道有关于状态压缩的算法，可不太清楚，一直放着没做，今天看了一个状态压缩ＤＰ算法
 *，于是写了下来．．．终于Ａc..
 *状态压缩：用位来表示状态，利用位运算节省时间（不是很能体会）
 *枚举状态，进行状态转移从而得到最优解，称为状态压缩DP...
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class cin
{
 static BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
 static StringTokenizer st;
 static int leave=0;
 static int nextInt()throws IOException
 {
  return Integer.parseInt(next());
 }
 static String next() throws IOException
 {
  while(leave==0)
  {
   st=new StringTokenizer(in.readLine());
   leave=st.countTokens();
  }
  leave--;
  return st.nextToken();
 }
 static boolean hasNext() throws IOException
 {
  while(leave==0)
  {
   String temp=in.readLine();
   if(temp==null)return false;
   st=new StringTokenizer(temp);
   leave=st.countTokens();
  }
  return true;
 }
}

class Dp
{
 int s[],r[][],c[][],f[][][],n,m;
 int x[],top=0;
 String board[];
 static int v[]={1,2,4,8,16,32,64,128,256,512};
 Dp(String b[],int n,int m)
 {
  board=b;
  this.n=n;
  this.m=m;
  s=new int[61];
  x=new int[m];
 }
 
 void dfs(int t)//计算s[]
 {
  int i;
  if(t>=m)
  {
   s[top]=0;
   for(i=0;i<m;i++)
   {
    s[top]+=v[i]*x[i];
   }
   top++;
  }
  else
  {
   if(place(t))
   {
    x[t]=1;
    dfs(t+1);
   }
   x[t]=0;
   dfs(t+1);
  }
 }
 
 boolean place(int t)
 {
  if(t-2>=0&&x[t-2]==1||t-1>=0&&x[t-1]==1)return false;
  return true;
 }
 
 int getC(int x)//x中含1的个数
 {
  int sum=0;
  while(x>0)
  {
   sum+=(x%2);
   x>>=1;
  }
  return sum;
 }
 
 void init() //初始化各状态
 {
  dfs(0);
  int i,j,temp;
  r=new int[n][top];
  c=new int[n][top];
  for(i=0;i<n;i++)
  {
   temp=0;
   for(j=0;j<m;j++)
   {
    if(board[i].charAt(j)=='P')temp+=v[j];
   }
   for(j=0;j<top;j++)
   {
    r[i][j]=temp&s[j];
    c[i][j]=getC(r[i][j]);
//    System.out.println(r[i][j]+" "+c[i][j]);
   }
  }
  f=new int[n][top][top];
 }
 
 int findMax()//构造最优解
 {
  int i,j,k,max,h;
  for(i=0;i<top;i++)
  {
   for(j=0;j<top;j++)
   {
       f[0][i][j]=c[0][i];
   }
  }
  if(n>1)
  {
   for(i=0;i<top;i++)
   {
    
    for(j=0;j<top;j++)
    {
     max=0;
     for(k=0;k<top;k++)
     {
      if((r[1][i]&r[0][j])==0&&max<f[0][j][k])
      {
       max=f[0][j][k];
      }
     }
     f[1][i][j]=max+c[1][i];
    }
   }
  }
  for(k=2;k<n;k++)
  {
   for(h=0;h<top;h++)
   {
    for(i=0;i<top;i++)
    {
     max=0;
     for(j=0;j<top;j++)
     {
      if((r[k][h]&r[k-1][i])==0&&(r[k-1][i]&r[k-2][j])==0&&(r[k][h]&r[k-2][j])==0&&max<f[k-1][i][j])
      {
       max=f[k-1][i][j];
      }
     }
     f[k][h][i]=max+c[k][h];
    }
    
   }
  }
  max=0;
  for(i=0;i<top;i++)
  {
   for(j=0;j<top;j++)
   {
    if(max<f[n-1][i][j])
     max=f[n-1][i][j];
   }
  }
  return max;
 }
 
 void out()
 {
  init();
  System.out.println(findMax());
 }
}

public class Main {
    public static void main(String args[]) throws IOException
    {
     int n,m,i;
     String str[];
     Dp data;
     n=cin.nextInt();
     m=cin.nextInt();
     str=new String[n];
     for(i=0;i<n;i++)
     {
      str[i]=cin.next();
     }
     data=new Dp(str,n,m);
     data.out();
    }
}