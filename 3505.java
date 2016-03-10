import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int nn,n,m,ans;
     nn=sc.nextInt();
     while((nn--)!=0) {
      n=sc.nextInt();
      m=sc.nextInt();
      int a[][]=new int[n+1][m+1];
       ans=0;
    for (int i=1;i<=n;i++) {
      for (int j=1;j<=m;j++)
           a[i][j]=sc.nextInt();
        int tp=0,now=1,t1,t2;
        for (int j=1;j<=m;j++) if (a[i][j]!=-1) tp++;
         while ((tp--)!=0) {
          int pos=1,tmp=1000000;
         for (int j=1;j<=m;j++) if (a[i][j]!=-1&&a[i][j]< tmp) {pos=j;tmp=a[i][j];}
          ans+=(i-1)*20;
        t1=now-pos;
        t2=pos-now;
        if (t1< 1) t1+=m;
        if (t2< 1) t2+=m;
        if (t1>t2) t1=t2;
        ans+=t1*5;now=pos;
        a[i][pos]=-1;
    }
     }
     System.out.printf("%d\n",ans);
    }
  }
}

