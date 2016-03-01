//* @author
import java.util.*;
import java.math.*;
public class Main {
 static BigInteger p1,p2,p3,q1,q2,q3,a1,a2,a0,h1,h2,g1,g2,p,q;
 static int nn;
 static void solve(){
  p2=BigInteger.ONE; p1=BigInteger.ZERO;
  q2=BigInteger.ZERO; q1=BigInteger.ONE;
  a1=BigInteger.valueOf((long)Math.sqrt(nn));
  a0=BigInteger.valueOf((long)Math.sqrt(nn));
  g1=BigInteger.ZERO;h1=BigInteger.ONE;
  BigInteger n0=BigInteger.valueOf(nn);
  while(true){
   g2=a1.multiply(h1).subtract(g1);
   h2=(n0.subtract(g2.multiply(g2))).divide(h1);
   a2=g2.add(a0).divide(h2);
   p=p2.multiply(a1).add(p1);
   q=q2.multiply(a1).add(q1);
   if(p.multiply(p).subtract(n0.multiply(q.multiply(q))).compareTo(BigInteger.ONE)==0)
     return ;
   a1=a2;
   g1=g2;
   h1=h2;
   p1=p2;p2=p;
   q1=q2;q2=q;
   }
 }

 public static void main(String[] args) {
   Scanner in=new Scanner(System.in);
   while(in.hasNext()){
    nn=in.nextInt();
    int t=(int)Math.sqrt(nn);
    if(t*t==nn)
      System.out.println("No solution!");
    else{
      solve();
      System.out.println(p+" "+q);
     }
  }
 }


}

