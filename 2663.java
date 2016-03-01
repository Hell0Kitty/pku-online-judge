import java.util.Scanner;
import java.util.Arrays;
public class Main{

  static long S(int n) //S(n)=3*S(n-2)+2*(S(n-4)+S(n-6)+...+S(2)+S(0))
{
    long s;
    int i;
    if(n==0)return 1;
     else
    {
        s=3*S(n-2);
        for(i=n-4;i>=0;i-=2)
        {
            s+=2*S(i);
        }
        return s;
    }
}

 public static void main(String args[]){
  Scanner sc=new Scanner(System.in);
    int n;
    n=sc.nextInt();
    while(n>=0)
    {
        if(n%2!=0) System.out.printf("0\n");
        else if(n==0) System.out.printf("1\n");
        else System.out.printf("%d\n",S(n));
        n=sc.nextInt();
    }
  }
}

