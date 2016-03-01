/* @author: */
import java.util.Scanner;
public class Main{

 int c[][]=new int[22][22];
  int result=0;
  int n;
 boolean sign[]=new boolean[22];
 int v[]=new int[22];

 int find(int k,int a,int r){
     int temp=0;
     if(a+r<=result) return result;
     if(k==n+1){
          if(a>result) result=a;
          return result;
     }
     sign[k]=false;
     for(int i=1;i< k;i++) if(sign[i]) temp+=c[k][i]; find(k+1,a+temp,r-v[k]);
     sign[k]=true; temp=0;
     for(int i=1;i< k;i++) if(!sign[i]) temp+=c[i][k]; find(k+1,a+temp,r-v[k]);
     return result;
}

 int init(){
     Scanner sc=new Scanner(System.in);
     int sum=0;
      n=sc.nextInt();
     for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
              c[i][j]=sc.nextInt();
              v[i]+=c[i][j];
         }
         sum+=v[i];
     }
    return sum;
 }

public static void main(String args[]){
   Main m=new Main();
     int sum=m.init();

     System.out.printf("%d\n", m.find(1,0,sum));
   }
}

