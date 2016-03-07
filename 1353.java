import java.util.*;
public class Main{
 

public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int a[]=new int[200],b[]=new int[200];
    int n,m,k;
    while(sc.hasNext()) {
        String s=sc.nextLine();
        Scanner scan=new Scanner(s);
        scan.useDelimiter(",");
        n=scan.nextInt();
        if(n==-1) break;
        m=scan.nextInt();

        k=scan.nextInt();
        for (int i=1;i<=n;i++) {
            if (i<=m) a[i]=-1;
            else a[i]=1;
        }
        for (int j=1;j<=k;j++) {
            a[n+1]=a[1];
            for (int i=1;i<=n;i++) b[i]=a[i]*a[i+1];
            for (int i=1;i<=n;i++) a[i]=b[i];
        }
        int ans=0;
        for (int i=1;i<=n;i++) if (a[i]==-1) ans++;
        System.out.printf("%d,%d,%d: %d\n",n,m,k,ans);
    }
  }
}