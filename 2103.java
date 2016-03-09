//* @author:
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
 static int oneNum[] = new int[65536];
 static BigInteger arr[] = new BigInteger[20];
 static int n;
 static BigInteger list[] = new BigInteger[65536];

public static void main(String[] args) {
  for(int i = 0; i < 16; i ++) {
   for(int j = 1<< i; j < 1<< i+1; j ++) {
    oneNum[j] = oneNum[j ^ (1<< i)] + 1;
   }
  }
   ///init over!
   Scanner scan = new Scanner(System.in);
   n = scan.nextInt();
  BigInteger ans1 = BigInteger.ZERO, ans2 = BigInteger.ONE;
  for(int i = 0; i < n; i ++) {
   arr[i] = scan.nextBigInteger();
   ans2 = ans2.multiply(arr[i]).divide(ans2.gcd(arr[i]));
  }

  list[0] = BigInteger.ONE;
  for(int i = 0; i < n; i ++) {
   for(int j = 1<< i; j < 1<< i+1; j ++) {
     list[j] = list[j^(1<< i)].multiply(arr[i]).divide(list[j^(1<< i)].gcd(arr[i]));
     if((oneNum[j] & 1) == 1) {
    ans1 = ans1.add(ans2.divide(list[j]));
     } else {
    ans1 = ans1.subtract(ans2.divide(list[j]));
     }
    }
   }

   BigInteger g = ans1.gcd(ans2);
   ans1 = ans1.divide(g);
   ans2 = ans2.divide(g);

   System.out.println(ans1);
   System.out.println(ans2);
 }
}

