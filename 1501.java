
import java.util.Arrays;
import java.util.Scanner;
public class Main{
 private char c[][];
 private int n;
 private String s;
 private boolean flag;
 private boolean vis[][];
 private int sx,sy,ex,ey;//匹配成功后，输出的首字母和末字母匹配成功的位置
 private int dir[][]={{0,-1},{0,1},{-1,0},{1,0},{-1,-1},{-1,1},{1,-1},{1,1}};

 public Main(int n,String s,char[][] c){
    this.n=n;
    this.s=s;
    this.c=c;
    flag=false;
    vis=new boolean[n][n];
 }

private void dfs(int i,int j,int m,int k) {
  int x,y;
  if(flag) return;
   //深搜结束条件
 if((c[i][j]==s.charAt(s.length()-1))&&m==s.length())//必须加个m==s.length()因为给出的字符串可能有重复字母
 {
    ex=i;ey=j;  //记录匹配成功末字符位置
    flag=true;
    return;
   }
  x=i+dir[k][0];
  y=j+dir[k][1];
  if(x>=0&&x< n&&y>=0&&y< n&&c[x][y]==s.charAt(m)&&!vis[x][y])
  {
    vis[x][y]=true;
    dfs(x,y,m+1,k);  //同一方向，搜索下一个字符
    vis[x][y]=false;
  }
}

 public static void main(String args[]){
   Scanner in=new Scanner(System.in);
   String s="";
   int n=in.nextInt();
   char[][] c=new char[n][n];

   for(int i=0;i< n;i++){
    s=in.next();
     for(int j=0;j< n;j++)
        c[i][j]=s.charAt(j);
    }


   while(true)  {
    s=in.next();
    if(s.equals("0")) break;
     Main main=new Main(n,s,c);
     main.go();
   }
 }


 private void go(){
   for(int i=0;i< n;i++)
     for(int j=0;j< n;j++)
       if(c[i][j]==s.charAt(0)){//找到第一个字母后，按同一个方向搜索
         for(int k=0;k< 8;k++){
           dfs(i,j,1,k);
           if(flag)
           {
             sx=i;sy=j;
             System.out.printf("%d,%d %d,%d\n",sx+1,sy+1,ex+1,ey+1);
             return;
           }

         }

       }

     if(!flag) System.out.printf("Not found\n");

 }


}