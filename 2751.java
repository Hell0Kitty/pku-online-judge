/* @author: */
import java.util.Scanner;
public class Main {
   static int a[][]=new int[10001][2];
   static int b[][]=new int[10001][2];
   static int an,bn;

   static void sort(){
    int i,j,t1,t2;
    for(i=0;i< an;i++)
        for(j=0;j< an;j++)
        {
            if(a[i][0]< a[j][0])
            {
                t1=a[i][0];t2=a[i][1];
                a[i][0]=a[j][0];a[i][1]=a[j][1];
                a[j][0]=t1;a[j][1]=t2;
            }
        }
    for(i=0;i< bn;i++)
        for(j=0;j< bn;j++)
        {
            if(b[i][1]>b[j][1])
            {
                t1=b[i][0];t2=b[i][1];
                b[i][0]=b[j][0];b[i][1]=b[j][1];
                b[j][0]=t1;b[j][1]=t2;
            }
        }
    }

 public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i,j,cn,t1,t2,l1,l2,sum1,sum2;
    while(sc.hasNext()){
        cn=sc.nextInt();
        if(cn==0) break;
        an=0;bn=0;
        for(i=0;i< cn;i++)
        {
            t1=sc.nextInt();
            t2=sc.nextInt();
            if(t1<=t2)
            {
                a[an][0]=t1;a[an][1]=t2;
                an++;
            }
            else
            {
                b[bn][0]=t1;b[bn][1]=t2;
                bn++;
            }
        }
        sort();
        for(i=0;i< bn;i++)
        {
            a[an][0]=b[i][0];a[an][1]=b[i][1];
            an++;
        }
        l1=l2=0;sum1=sum2=0;

        for(i=0;i< an;i++)
        {
            sum1+=a[i][0];
            if(sum1>sum2)sum2=sum1;
            sum2+=a[i][1];
        }
        System.out.printf("%d\n",sum2);
    }
  }
}

