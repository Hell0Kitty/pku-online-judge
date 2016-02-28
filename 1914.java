//* @author popop0p0popo
import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
   int n=scanner.nextInt();
	BigInteger[][] a;
	BigInteger[] b;
	BigInteger aa,aa1,aa2,aa3;
	for (int i=0;i< n ;i++ ){
         a=new BigInteger[3][3];
	 b=new BigInteger[3];
	 for (int j=0;j< 3 ;j++ ){
	   for (int k=0;k< 3 ;k++ ){
	    a[j][k]=scanner.nextBigInteger();
	   }
	  b[j]=scanner.nextBigInteger();
	}
	aa=a[0][0].multiply(a[1][1].multiply(a[2][2]).add(a[1][2].multiply(a[2][1]).negate())).
          add((a[0][1].multiply(a[1][0].multiply(a[2][2]).
          add(a[1][2].multiply(a[2][0]).negate()))).negate()).
          add(a[0][2].multiply(a[1][0].multiply(a[2][1]).
          add(a[1][1].multiply(a[2][0]).negate())));

       aa1=b[0].multiply(a[1][1].multiply(a[2][2]).add(a[1][2].multiply(a[2][1]).negate())).
         add((a[0][1].multiply(b[1].multiply(a[2][2]).
         add(a[1][2].multiply(b[2]).negate()))).negate()).
         add(a[0][2].multiply(b[1].multiply(a[2][1]).
         add(a[1][1].multiply(b[2]).negate())));

      aa2=a[0][0].multiply(b[1].multiply(a[2][2]).add(a[1][2].multiply(b[2]).negate())).
         add((b[0].multiply(a[1][0].multiply(a[2][2]).
         add(a[1][2].multiply(a[2][0]).negate()))).negate()).
         add(a[0][2].multiply(a[1][0].multiply(b[2]).
         add(b[1].multiply(a[2][0]).negate())));

      aa3=a[0][0].multiply(a[1][1].multiply(b[2]).add(b[1].multiply(a[2][1]).negate())).
         add((a[0][1].multiply(a[1][0].multiply(b[2]).
         add(b[1].multiply(a[2][0]).negate()))).negate()).
         add(b[0].multiply(a[1][0].multiply(a[2][1]).
         add(a[1][1].multiply(a[2][0]).negate())));

	System.out.println(aa1+" "+aa2+" "+aa3+" "+aa);
	if (aa.equals(BigInteger.ZERO)){
		System.out.println("No unique solution");
	}
       else{
	DecimalFormat df=new DecimalFormat("0.000");
	BigDecimal x1=new BigDecimal(aa1.toString());
	BigDecimal x2=new BigDecimal(aa2.toString());
	BigDecimal x3=new BigDecimal(aa3.toString());
	BigDecimal x=new BigDecimal(aa.toString());
	BigDecimal xx1=x1.divide(x,6,BigDecimal.ROUND_HALF_UP);
	BigDecimal xx2=x2.divide(x,6,BigDecimal.ROUND_HALF_UP);
	BigDecimal xx3=x3.divide(x,6,BigDecimal.ROUND_HALF_UP);
   System.out.println("Unique solution: "+df.format(xx1)+" "+df.format(xx2)+" "+df.format(xx3));
	}
	System.out.println();
  }
}
}

