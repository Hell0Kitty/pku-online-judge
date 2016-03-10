//* @author:alpc12
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {

BigInteger[][] Ank = new BigInteger[27][27];

void pre() {
 BigInteger i, j;
 for(i = BigInteger.ONE; i.compareTo(new BigInteger("27")) != 0; i = i.add(BigInteger.ONE)) {
  Ank[i.intValue()][0] = BigInteger.ONE;
  Ank[i.intValue()][1] = i;
  for(j = new BigInteger("2"); j.compareTo(i) <= 0; j = j.add(BigInteger.ONE)) {
   Ank[i.intValue()][j.intValue()] = Ank[i.intValue()][j.intValue()-1].multiply(i.subtract(j).add(BigInteger.ONE));
  }
 }
}

 BigInteger cal(String s, int n, int pos) {
   BigInteger ret = BigInteger.ZERO;
   boolean[] chk = new boolean[26];
   int i, ava = s.charAt(pos)-'A';
   for(i = 0; i < pos; ++i)
    chk[s.charAt(i)-'A'] = true;
   for(i = 0; i < s.charAt(pos)-'A'; ++i)
    if(chk[i])
   ava--;
   BigInteger a = new BigInteger(""+ava);
   if(pos == n-1)
    return a;
   ret = ret.add(a.multiply(Ank[26-pos-1][n-pos-1]));
   return ret.add( cal(s, n, pos+1) );
  }

  void run() {
   Scanner cin = new Scanner(System.in);
   pre();
   while(true) {
    int n = cin.nextInt();
    if(n == 0)
        break;
    String s = cin.next();
    System.out.println(cal(s, s.length(), 0));
   }
  }

 public static void main(String[] args) {
    new Main().run();

 }

}

