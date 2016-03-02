//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int[] prime=new int[]
   {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
	53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,
	127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,
	199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,
	283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,
	383,389,397,401,409,419,421,431
   };
   int[] arr=new int[84];
   while(in.hasNext())
   {
	int c=in.nextInt();
	int n=in.nextInt();
	int k=c-n;
	for(int i=0;i< 83;i++)
         arr[i]= cal(c,prime[i])-cal(n,prime[i])-cal(k,prime[i]);
	long ans=1;
	for(int i=0;i< 84;i++)
	  if(arr[i]!=0) ans*=(arr[i]+1);
	System.out.println(ans);
    }
  }

public static int cal(int n, int p) {
     if(n < p) return 0;
     else return n / p + cal(n / p, p);
 }
}

