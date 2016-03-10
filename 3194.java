/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{
 static int p[][]=new int[105][105];
 static int q[][]=new int[101][101];
 static int n,cnt;


static void dfs(int i,int j)
{
  if(i>n||j>n||i< 1||j< 1) return;
  q[i][j]=cnt;
  if(q[i][j+1]==0&&p[i][j]==p[i][j+1]) dfs(i,j+1);
  if(q[i][j-1]==0&&p[i][j]==p[i][j-1]) dfs(i,j-1);
  if(q[i+1][j]==0&&p[i][j]==p[i+1][j]) dfs(i+1,j);
  if(q[i-1][j]==0&&p[i][j]==p[i-1][j]) dfs(i-1,j);
}

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

 int i,j,u,v;

 while(sc.hasNext())
 {
   n=sc.nextInt();
  if(n==0) break;
  for(i=0;i< p.length;i++){
  Arrays.fill(p[i],0);
 }
 for(i=0;i< q.length;i++){
     Arrays.fill(q[i],0);
 }

for(i=0;i< n-1;i++)
{
  for(j=0;j< n;j++)
  {
    u=sc.nextInt();
      v=sc.nextInt();
      p[u][v]=i+1;
   }
 }
 cnt=1;
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
   {
    if(q[i][j]!=0) continue;
    dfs(i,j);
    cnt++;
   }
  }
  cnt--;
  if(cnt>n) System.out.println("wrong");
  else System.out.println("good");
  }
 }
}

