import java.util.Scanner;
public class Main{
   public static int gcd(int a,int b){
      return (b!=0) ? gcd(b,a%b):a;
   }

   public static void main(String args[]){
      Scanner in=new Scanner(System.in);
      
      while(true){
          int c=3;
          int s=in.nextInt();
          if(s==-1) break;
          if(s==0){
	    System.out.printf("0\n");
	    continue;
	   }
	   long p[]=new long[64];
            p[0] = 1; // power of c
	   for (int k=0 ; k<s ; k++) 
             p[k+1] = p[k] * c;
	   long  count = ((s&1)!=0) ? s * p[s/2 + 1] : (s/2) * (p[s/2] + p[s/2 + 1]);
		// rotation part
	   for (int k=1 ; k<=s ; k++) 
             count += p[gcd(k, s)];
	   count /= 2 * s;
	   System.out.printf("%d\n",count);
	}
     }
}