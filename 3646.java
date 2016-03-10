//* @author:
import java.util.*;
public   class Main{

    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);

    int i,j,ans;
    end: while (sc.hasNext()) {
        int n=sc.nextInt();
        if(n==0) break;
        int m=sc.nextInt();
        int a[]=new int[n+1];
        int b[]=new int[m+1];

        for ( i=1;i<=n;i++)
           a[i]=sc.nextInt();
        for ( i=1;i<=m;i++)
           b[i]=sc.nextInt();
        Arrays.sort(a, 1,n+1);
        Arrays.sort(b,1,m+1);
        for (ans=0,j=i=1;i<=n;i++) {
        if (j>m) {
             System.out.println("Loowater is doomed!");
              continue end;
         }
            while (a[i]>b[j]) {
              j++;if (j>m) {
                System.out.println("Loowater is doomed!");
                continue end;
              }
            }
            ans+=b[j];j++;
        }
        System.out.printf("%d\n",ans);

    }
  }
}

