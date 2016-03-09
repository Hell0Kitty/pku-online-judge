//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {

  static int n,k;
  static final int N = 100000+100,que[] = new int[N];
  static double DP[] = new double[N] , sum[] = new double[N];

  public static int Get_Num(StreamTokenizer cin) throws Exception{
    cin.nextToken();
    return (int)cin.nval;
  }

  public static void main(String []args) throws Exception{

   int i,j;
   double temp;

   StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

    //n = cin.nextInt();
    //k = cin.nextInt();
    n = Get_Num(in);
    k = Get_Num(in);
    sum[0] = 0.0;
    for(i=1;i<=n;++i){
        temp = (double) Get_Num(in);
        temp*=1000.0;
        sum[i] = sum[i-1]+temp;
    }
    i = (int) solve();
    System.out.println(i);
    }

   public static boolean G(int a,int b,int c){
    if((sum[c]-sum[a])*(b-a)<=(sum[b]-sum[a])*(c-a))
        return true;
    return false;
   }

  public static int solve(){

   double Max;
   int left=0,right=0,i,j;
   for(i=k;i<=n;++i){
    while(right-left>=2 && G(que[right-2],que[right-1],i-k))
        --right;
    que[right++] = i-k;

    DP[i] = (sum[i] - sum[que[left]])/(i-que[left]);
    while(left< right-1 && (DP[i]<=((sum[i]-sum[que[left+1]])/(i-que[left+1])))){
        left++;
        DP[i] = (sum[i] - sum[que[left]])/(i-que[left]);
    }
    }
    for(Max=0.0,i=1;i<=n;++i)
        Max = Max>DP[i]?Max:DP[i];
    return (int)Max;
  }
}

