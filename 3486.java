import java.util.Scanner;
import java.util.Arrays;
public class Main {


 public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n,c;
    int m[][]=new int[1003][1003];
    int f[]=new int[1003];
    while(sc.hasNext()){
          c=sc.nextInt();
          n=sc.nextInt();
          for(int i=0;i< m.length;i++)
             Arrays.fill( m[i],0);
          for(int i=1;i<=n;i++){
               for(int j=i;j<=n;j++)
                 m[i][j]=sc.nextInt();

          }
          for(int i=1;i<=n;i++){
               f[i]=c+m[1][i];
          }
          for(int i=2;i<=n;i++){
               for(int j=i;j<=n;j++){
                    if(f[j]>f[i-1]+c+m[i][j])
                         f[j]=f[i-1]+c+m[i][j];
               }
          }
          System.out.printf("%d\n",f[n]);
    }
    }
}

