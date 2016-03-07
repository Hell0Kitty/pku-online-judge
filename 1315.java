import java.io.*;
import java.util.StringTokenizer;

/*回溯,每个非Wall的位置有两种情况,有rook或无,可以构造解子集空间树,回溯得到可以放的最大rook数
 *其解空间树为一棵二叉树,最大深度n为16,时间复杂度为O(2^n)<=65536,于是算法可行
 *这里的约束条件是rook不垂直或水平碰面且此位置不为墙..
 */

class cin
{
static int leave=0;
static StringTokenizer st;
static BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
static int nextInt() throws IOException
{
   while(leave==0)
   {
    st=new StringTokenizer(in.readLine());
    leave=st.countTokens();
   }
   int a=Integer.parseInt(st.nextToken());
   leave--;
   return a;
}
static String nextLine() throws IOException
{
   return in.readLine();
}
}
class Chess
{
char board[][];
int best,n,now,max;

void set(char b[][],int num)
{
   board=b;
   n=num;
   best=0;
   now=0;
   max=n*n;
}

boolean place(int x,int y)   //约束函数
{
   int i;
   if(board[x][y]=='X')return false;
   i=x-1;
   while(i>=0) //左面无rook
   {
    if(board[i][y]=='r')return false;
    if(board[i][y]=='X')break;
    i--;
   }
   i=x+1;
   while(i<n) //右面无rook
   {
    if(board[i][y]=='r')return false;
    if(board[i][y]=='X')break;
    i++;
   }
   i=y-1;
   while(i>=0) //上面无rook
   {
    if(board[x][i]=='r')return false;
    if(board[x][i]=='X')break;
    i--;
   }
   i=y+1;
   while(i<n) //下面无rook
   {
    if(board[i][y]=='r')return false;
    if(board[i][y]=='X')break;
    i++;
   }
   return true;
}

void backTrack(int t) //回溯
{
   if(t==max)
   {
    if(now>best)best=now;
   }
   else 
   {
    if(max-t+1<best-now)return;
    int i=t/n,j=t%n;
    if(place(i,j))
    {
     now++;
     board[i][j]='r';
     backTrack(t+1);
     board[i][j]='.';
     now--;
    }
    backTrack(t+1);
   }
}
int outSum()
{
   backTrack(0);
   return best;
}
}

public class Main {
    public static void main(String args[]) throws IOException
    {
    char board[][]=new char[4][4];
    String temp;
    Chess data=new Chess();
    int n,i,j;
    while(true)
    {
       n=cin.nextInt();
       if(n==0)break;
       for(i=0;i<n;i++)
       {
        temp=cin.nextLine();
        for(j=0;j<n;j++)
         board[i][j]=temp.charAt(j);
       }
       data.set(board,n);
       System.out.println(data.outSum());
    }
    }
}