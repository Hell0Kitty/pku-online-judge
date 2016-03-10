//* @author
import java.util.*;
public class Main{
  public static void main(String args[]){

    int k,n;
    Scanner in=new Scanner(System.in);
    k=in.nextInt();
    init();
    while(k-->0){
        n=in.nextInt();
       System.out.printf("%d\n",s[n]);
    }

   }

  static int MAX=80000;
  static long s[]=new long[MAX];       //用于存储结果，升序
  static long d2[]=new long[MAX];     //存储所有含有质因子2且符合条件的数
  static long d3[]=new long[MAX];     //存储所有含有质因子3且符合条件的数
  static long d5[]=new long[MAX];
  static long d7[]=new long[MAX];

  public static void init(){
    int i;
    int pos2,pos3,pos5,pos7;
    long a,b;
    s[1]=1;
    pos2=pos3=pos5=pos7=1;
    for(i=1;i< MAX-1;i++){
        d2[i]=s[i]*2;
        d3[i]=s[i]*3;
        d5[i]=s[i]*5;
        d7[i]=s[i]*7;
        while(d2[pos2]<=s[i])pos2++;     //如果这个数小于s[i]，那么它一定已经在s[i]中，可以去掉。
        while(d3[pos3]<=s[i])pos3++;     //显然s[i]是从四个数组中从小到大选出来的，
        while(d5[pos5]<=s[i])pos5++;     //所以上面的做法一定是正确的
        while(d7[pos7]<=s[i])pos7++;
        a=d2[pos2]< d3[pos3]?d2[pos2]:d3[pos3];
        b=d5[pos5]< d7[pos7]?d5[pos5]:d7[pos7];
        s[i+1]=a< b?a:b;
    }
  }
}

