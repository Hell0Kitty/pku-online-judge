import java.util.*;
import java.io.*;
import java.math.*;
public class Main{
    public static BigInteger[][] dp=new BigInteger[110][110];
    public static BigInteger[][] dp1=new BigInteger[110][110];
    public static BigInteger INF;
    public static BigInteger NEG;
    public static BigInteger[] array=new BigInteger[200];
    public static char[] ops=new char[100];
    public static BigInteger[] warray=new BigInteger[200];
    public static char[] wops=new char[100];
    public static int N; 

    static void DP(int s,int t){
        if(s==t){  
          dp1[s][t]=dp[s][t]=warray[s]; 
           return; 
        } 
       if(!dp[s][t].max(NEG).equals(NEG))        {
            return;
        } 

        BigInteger a,b,c,d;
        BigInteger tmp; 
        for(int i=s;i<t;i++){
            DP(s,i);
            DP(i+1,t);
            a=dp[s][i]; 
            b=dp1[s][i];
            c=dp[i+1][t];
            d=dp1[i+1][t]; 
            switch(wops[i]){
              case 't': 
              {                
               dp[s][t]=dp[s][t].max(a.add(c)); 
               dp1[s][t]=dp1[s][t].min(b.add(d)); 
               break; 
              }  

              case 'x': 
              { 
               tmp=a.multiply(c); 
               tmp=tmp.max(b.multiply(d));
               dp[s][t]=dp[s][t].max(tmp); 
               tmp=a.multiply(d);
               tmp=tmp.min(c.multiply(b));
               tmp=tmp.min(a.multiply(c)); 
               tmp=tmp.min(b.multiply(d)); 
               dp1[s][t]=dp1[s][t].min(tmp);
               break; 
              }  
            }
          }  
      } 

      static void work(){
        BigInteger res=NEG;
        BigInteger tmp;
        int cnt=0;
        int[] record=new int[100];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
               wops[j]=ops[(i+j+1)%N]; 
               warray[j]=array[(i+j)%N]; 
            }
            for(int j=0;j<100;j++) {
                for(int k=0;k<100;k++){ 
                   dp[j][k]=NEG;
                    dp1[j][k]=INF; 
                }
            } 
           DP(0,N-1);
          //System.out.println(dp[0][N-1]);
            if(!res.max(dp[0][N-1]).equals(res)) { 
               res=dp[0][N-1]; 
               cnt=0;
               record[cnt++]=i+1; 
             }else if(res.max(dp[0][N-1]).equals(dp[0][N-1])){  
              record[cnt++]=i+1; 
             }
        }   
             System.out.println(res); 
            for(int i=0;i<cnt;i++){
               if(i>0)
                System.out.print(" ");
               System.out.print(record[i]); 
            } 
           System.out.println(""); 
    } 

       public static void main(String[] args) throws FileNotFoundException    {
        Scanner cin=new Scanner(System.in);//Scanner cin=new Scanner(new File("input.txt")); 
       INF=BigInteger.valueOf(10).pow(301); 
       NEG=BigInteger.valueOf(-10).pow(301); 
       String[] buffer=new String[200]; 
       String str;
        str=cin.nextLine(); 
       N=Integer.parseInt(str); 
       str=cin.nextLine(); 
       buffer=str.split(" "); 
       for(int i=0;i<N;i++){
            ops[i]=buffer[i*2].charAt(0);  
          array[i]=new BigInteger(buffer[i*2+1]);  
      } 
       work(); 
   }
}