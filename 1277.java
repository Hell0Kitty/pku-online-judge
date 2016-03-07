import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main{
	static Scanner cin;
	public static void main(String args[]){
		cin = new Scanner(System.in);
		int num = cin.nextInt();
		for(int i=0;i<num;i++)
			run();
	}

	static void run(){
		int p = cin.nextInt();
		//BigInteger n = new BigInteger(new Integer(p));
		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		BigInteger three = new BigInteger("3");
		BigInteger six = new BigInteger("24");


		if(p<=3)
			System.out.println(0);
		else if(p%2==1)
			System.out.println(p*(p-3)/2);
		else
			System.out.println(p*(p-4)/2+1);
	}

}
