//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

public class Main {
    static final int N = 20;
    static int n,m;
    static double front[] = new double[N],rear[] = new double[N],cnt[]=new double[N*N];

    static double Get_Num(StreamTokenizer cin)throws Exception{
        cin.nextToken();
        return cin.nval;
    }

public static void main(String[]args) throws Exception{
 int i;
 StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

 while(true){
    n = (int) Get_Num(cin);
    if(n<=0) break;
    m = (int) Get_Num(cin);
    for(i=0;i< n;++i)
        front[i] = Get_Num(cin);
    for(i=0;i< m;++i)
        rear[i] = Get_Num(cin);
    System.out.printf("%.2f\n",solve());
  }
 }

static double solve(){
  double ans=0.0;
  int i,j,top=0;
  for(i=0;i< n;++i){
    for(j=0;j< m;++j){
        cnt[top++] = rear[j]/front[i];
    }
   }
  Arrays.sort(cnt,0,top);
  for(i=1;i< top;++i){
    ans = ans>(cnt[i]/cnt[i-1])?ans:(cnt[i]/cnt[i-1]);
  }
    return ans;
 }
}

