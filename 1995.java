import java.util.*;
public class Main{

//求a^b%n
  private static int modexp(int a,int b,int n)
{
    int ret=1;
    int tmp=a;
    while(b!=0)
    {
       if((b&0x1)==1) ret=ret*tmp%n;
       tmp=tmp*tmp%n;
       b>>=1;
    }
    return ret;
}

 public static void main(String[] args){
   Scanner sc=new Scanner(System.in);
   int t=sc.nextInt();
   while(t-->0){
     int m=0;
    int h=0;
    int a=0;
    int b=0;
    int sum=0;
    m=sc.nextInt();
    h=sc.nextInt();
    for(int i=0;i< h;i++){
       a=sc.nextInt();
       b=sc.nextInt();
       sum=(sum+modexp(a%m,b,m))%m;
    }
     System.out.println(sum);
   }
      }
}

