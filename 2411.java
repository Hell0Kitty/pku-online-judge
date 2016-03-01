/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 /* f[i][j]表示第i行，方格排布为二进制数j（第k位上为1表示凸出一个格子，为0表示不凸出）
   的方案数。用DFS进行状态转移。*/
 static  long  f[][]=new long[12][2048];
 static int  n, m;

 static void dfs(int i, int j, int jj, int s)//j是初始状态，jj是目标状态.s表示列数
{
    if (s == m)//把i行m列放好
        f[i + 1][jj] += f[i][j];//等于I+1行被占去的格子的2进制为JJ应该可以多放f[i][j]的方略
    else if ((jj & (1 << s)) == 0)//表示第J列能放1/0
    {
        dfs(i, j, jj | (1 << s), s + 1);//放1
        if (s < m - 1 && (jj & (1 << (s + 1))) == 0) dfs(i, j, jj, s + 2);//放0（横占2格）
    }
    else//表示此处只能放0
       dfs(i, j, jj & ~(1 << s), s + 1);//(jj & (1 << s)这个位置已经被占
}

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  while (sc.hasNext())
  {
      n=sc.nextInt();
      m=sc.nextInt();
      if(n+m==0) break;
      for(int i=0;i< f.length;i++)
        Arrays.fill(f[i],0);

      f[0][0] = 1;
      for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << m); j++)
          if (f[i][j]!=0) //剪枝（为0没有必要考虑）
            dfs(i, j, j, 0);
      System.out.printf("%d\n", f[n][0]);//不占n行也即0~n-1放满的方法数
   }
 }
}

