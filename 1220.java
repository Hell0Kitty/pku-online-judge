import java.util.*;
import java.math.*;
public class Main {
	static int c2i(char c){
		if(c>='0'&&c<='9')
			return c-'0';
		if(c>='A'&&c<='Z')
			return c-'A'+10;
		return c-'a'+36;
	}
	static char i2c(int c){
		if(c<10)
			return (char)(48+c);
		if(c>=10&&c<36)
			return (char)('A'+c-10);
		return (char)('a'+c-36);
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int t=in.nextInt();
		for(int k=0;k<t;k++){
			int a1=in.nextInt();
			int a2=in.nextInt();
			String s=in.next();
			System.out.println(a1+" "+s);
			System.out.print(a2+" ");
			BigInteger a=BigInteger.ZERO;
			for(int i=0;i<s.length();i++)
				a=a.multiply(BigInteger.valueOf(a1)).add(BigInteger.valueOf(c2i(s.charAt(i))));
			s="";
			while(!a.equals(BigInteger.ZERO)){
				s=i2c(a.mod(BigInteger.valueOf(a2)).intValue())+s;
				a=a.divide(BigInteger.valueOf(a2));
			}
			if(s.equals(""))
				s="0";
			System.out.println(s);
			System.out.println();
		}
	}

}