//* @author:
import java.util.*;
import java.io.*;
import java.math.*;
class Main
{
 public static void main(String args[]) throws Exception
 {
  Scanner cin = new Scanner(System.in);
  String s;
  BigInteger bi;
  int T;
  boolean res;
  T = cin.nextInt();
  cin.nextLine();
  while (T-- > 0)
  {
    s = cin.nextLine();
    bi = new BigInteger(s);
    res = check(bi);
    if (res) System.out.println("Yes.");
    else System.out.println("No.");
   }
  }

 static boolean check(BigInteger bi)
 {
   bi = bi.add(bi);
   BigInteger min, max, mid, tmp;
   BigInteger Two = BigInteger.ONE.add(BigInteger.ONE);
   BigInteger One = BigInteger.ONE;
   BigInteger nOne = BigInteger.valueOf(-1);
   min = BigInteger.ZERO;
   max = bi;
   while (min.compareTo(max) <= 0)
   {
    mid = min.add(max).divide(Two);
    tmp = mid.add(One).multiply(mid);
    if (tmp.equals(bi)) return true;
    if (tmp.compareTo(bi) < 0) min = mid.add(One);
    else max = mid.add(nOne);
    }
	return false;
   }
}

