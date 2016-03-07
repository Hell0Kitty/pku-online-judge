import java.util.*;
import java.math.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		int n=scanner.nextInt();
		int m=scanner.nextInt();
		int[] yue=getYue(m);
		for (int i=0;i< yue.length ;i++ ){
			if (yue[i]==0){
				break;
			}
			m=m/yue[i];
		}
		BigInteger ok=(new BigInteger(""+m)).pow(n);
		BigInteger tmp=BigInteger.ONE;
		for (int i=0;i< yue.length ;i++ ){
			if (yue[i]==0){
				break;
			}
	         tmp=tmp.multiply(((new BigInteger(""+yue[i])).pow(n)).subtract(BigInteger.ONE));
		}
		ok=ok.multiply(tmp);
		System.out.println(ok.toString());
	}

	public static int[] getYue(int n){
		int l=0;
		int[] yue=new int[16];
		if (n%2==0){
			yue[l]=2;
			l++;
		}
		for (int i=3;i<=n/2 ;i=i+2 ){
			if (n%i==0&&isZh(i)){
				yue[l]=i;
				l++;
			}
		}
		if (isZh(n)){
			yue[l]=n;
		}
		return yue;
	}

	public static boolean isZh(int n){
		for (int i=2;i<=(int)Math.pow(n,0.5) ;i++ ){
			if (n%i==0){
				return false;
			}
		}
		return true;
	}
}
