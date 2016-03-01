//* @author: ccQ.SuperSupper
import java.util.*;
import java.math.*;
public class Main {
 public static void main(String []args) throws Exception{

 int t,cs=1,left,right,i,j;
 BigInteger a,b,seven;
 String str1,str2;

 seven = BigInteger.valueOf(1);
 for(i=0;i< 10000;++i)
	seven = seven.multiply(BigInteger.valueOf(7));

 Scanner cin = new Scanner(System.in);

 t = cin.nextInt();
 while(t--!=0){
	str1 = cin.next();
	str2 = cin.next();
	left = cin.nextInt();
	right = cin.nextInt();

	a = new BigInteger(str1);
	a = a.multiply(seven);
	a = a.divide(new BigInteger(str2));

	b = new BigInteger(str1);
	b = b.divide(new BigInteger(str2));
	b = b.multiply(seven);

	a = a.subtract(b);
	a = a.add(seven);
System.out.print("Problem set "+cs+": "+str1+" / "+str2+", base 7 digits "+left+" through "+right+": ");
	System.out.println(a.toString(7).substring(left+1, right+2));
	++cs;
  }
 }
}

