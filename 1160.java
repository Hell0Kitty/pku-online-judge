import java.util.Scanner;
import java.util.Arrays;
public class Main{
 static int num[]=new int[302];
 static int s[][]=new int[302][302];

 static void cost(int n){
     int i,j,k;
     for(i=1;i<n;i++){
         for(k=i+1; k <= n; k ++){
            int mid=(i+k)/2;
            for(j=i;j<mid;j++) s[i][k]+=num[mid]-num[j];
            for(j=mid+1;j<=k;j++) s[i][k]+=num[j]-num[mid];
         }
      }
 }

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
     int f[][]=new int[302][32];
     int n,k;

     int i,j,m;
     for(i=0;i<s.length;i++)
          Arrays.fill(s[i],0);
     for(i=0;i<f.length;i++)
          Arrays.fill(f[i],1000000);
     n=sc.nextInt();
     m=sc.nextInt();
    
     for(i=1;i<=n;i++)
        num[i]=sc.nextInt();
     cost(n);
     for(i=1;i<=n;i++) f[i][1]=s[1][i];
     for(k=2;k<=m;k++){
         for(i=1;i<=n;i++){
            for(j=1;j<i;j++)
                 if(f[j][k-1]+s[j+1][i]<f[i][k]) f[i][k]=f[j][k-1]+s[j+1][i];        
         }                  
     }
     System.out.printf("%d\n",f[n][m]);
    }
}