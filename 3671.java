import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
  int n;
  int v[]=new int[30002];
  int f[]=new int[30002];
  int g[]=new int[30002];
  n=sc.nextInt();
  for(int i=1;i<=n;i++)
    v[i]=sc.nextInt();

 f[0]=0; g[n+1]=0;
 for(int i=1;i<=n;i++){
     if(v[i]==2) f[i]=f[i-1]+1;
      else f[i]=f[i-1];
  }
  for(int i=n;i>=1;i--){
      if(v[i]==1) g[i]=g[i+1]+1;
       else g[i]=g[i+1];
  }
  int mins=100000000;
  for(int i=0;i<=n;i++)
      if(f[i]+g[i+1]< mins)
  mins=f[i]+g[i+1];
 System.out.printf("%d\n",mins);
 }
}


