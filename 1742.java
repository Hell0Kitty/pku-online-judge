import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[])
{
      int N, M;
      Scanner sc=new Scanner(System.in);
      while(sc.hasNext())
      {
            N=sc.nextInt();//硬币的种数
            M=sc.nextInt();//
            if(N==0&&M==0) break;
            int a[]=new int[100];//a[i]表示第i种硬币的面值
            int c[]=new int [100];//c[i]表示第i种硬币的个数

            for (int i=0; i<N; i++) a[i]=sc.nextInt();
            for (int i=0; i<N; i++) c[i]=sc.nextInt();

            int nRes=0;
            boolean s[]=new boolean[100001];
             s[0]=true;

            for (int i=0; i<N; i++)
            {
                  int u[]=new int[100001];

                  for (int j=a[i]; j<=M; j++)
                  {
                        if (!s[j] && s[j-a[i]] && u[j-a[i]]<c[i])
                        {
                              s[j]=true;
                              u[j]=u[j-a[i]]+1;
                              nRes++;
                        }
                  }
            }
            System.out.printf("%d\n", nRes);
      }
    } 
}