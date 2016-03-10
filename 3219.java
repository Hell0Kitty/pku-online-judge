//* @author:
import java.util.*;
 public class Main{
   public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
     int n=0;
     int k=0;
     int m=0;

     while(sc.hasNext()){
       int a=0;
       int b=0;
       int c=0;
       n=sc.nextInt();
       k=sc.nextInt();
       m=n-k;

       while((n=n>>1)!=0) //将n的各二进制位右移一位，即相当于除以2
             a+=n;

       while((m=m>>1)!=0)
             b+=m;

       while((k=k>>1)!=0)
             c+=k;

       if(a-b>c)  //判断分子分母含2的个数的多少
            System.out.printf("0\n");
       else
            System.out.printf("1\n");
     }
   }
}

