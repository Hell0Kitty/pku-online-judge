import java.math.BigInteger;
import java.util.Scanner;

public class Main {
 public static void main(String[] args){
 Scanner stdin=new Scanner(System.in);
 int n=stdin.nextInt();
 int[] a=new int[n],b=new int[n];
 for(int i=0;i< n;i++)a[i]=stdin.nextInt();
  b[0]=a[n-1];
  for(int i=1;i< n;i++){
    b[i]=b[i-1]^a[n-1-i];
  }
  BigInteger ans=new BigInteger("0"),two=new BigInteger("2");
 for(int i=0;i< n;i++){
   ans=ans.multiply(two);
   if(b[i]==1)
	ans=ans.add(BigInteger.ONE);
 }
  System.out.println(ans);
  }
}

