import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
 static BigInteger digit100=new BigInteger("1");
 static int t,a,b;
 static void start(){
	for(int i=0;i< 100;++i)
		digit100 = digit100.multiply(BigInteger.valueOf(10));
 }

 public static void main(String[]args) throws Exception{

  BigInteger num1,num2,temp,ans;
  start();
  //Scanner cin = new Scanner(new FileInputStream("input.txt"));
  Scanner cin = new Scanner(System.in);

  while(cin.hasNext()){
	t = cin.nextInt();
	a = cin.nextInt();
	b = cin.nextInt();
	if((t==1||b==0||a< b)){
		output(BigInteger.valueOf(-1));
	}
	else if(a==0){
		output(BigInteger.valueOf(0));
	}
	else if(a==b){
		output(BigInteger.valueOf(1));
	}
	else if(a%b!=0||(a-b)*java.lang.Math.log10((double)t)>120){
		output(BigInteger.valueOf(-1));
	}
	else{
		temp = BigInteger.valueOf(t);
		num1 = temp.pow(a);
		num2 = temp.pow(b);
		num1 = num1.subtract(BigInteger.ONE);
		num2 = num2.subtract(BigInteger.ONE);
		ans = num1.divide(num2);
		if(ans.toString().length()< 100){
			output(ans);
		}else{
			output(BigInteger.valueOf(-1));
		}
	}
   }
 }

 static void output(BigInteger who){
  if(who.equals(BigInteger.valueOf(-1))){
   System.out.println("("+t+"^"+a+"-1)/("+t+"^"+b+"-1) is not an integer with less than 100 digits.");
  }
  else{
   System.out.println("("+t+"^"+a+"-1)/("+t+"^"+b+"-1) "+who);
  }
 }
}

