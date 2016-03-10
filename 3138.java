//* @author:
import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);

   int p[]=new int[101];
    int i,j,n,s,t,m,id,t1,t2,sum,sid,tot,cas=0;;
    while (true) {
       s=sc.nextInt();t=sc.nextInt();m=sc.nextInt();
        if (s==0&&t==0&&m==0) break;
        for (i=1;i<=100;i++) p[i]=0;sum=0;cas++;
        for (i=1;i<=s;i++) {
          id=sc.nextInt();
          t1=sc.nextInt();
          t2=sc.nextInt();
          if (p[id]==0) { sum+=t1+t2;p[id]=1;}
         }
        for (i=1;i<=100;i++) p[i]=0;
        for (i=1;i<=t;i++) {
         sid=sc.nextInt();
         tot=sc.nextInt();
         if (p[sid]==0&&tot>=m) { sum++;p[sid]=1;}
        }
        System.out.printf("Case %d: %d\n",cas,sum);
    }
  }
}

