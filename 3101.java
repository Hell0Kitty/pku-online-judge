import java.util.*;
import java.math.*;
public class Main {
	public static int[] p=new int[3000];
	public static int pc;
	public static int[] a=new int[3000];
	public static boolean[] che=new boolean[10001];
	public static void init(){
		int t1=2;
		while(t1*t1<=10000){
			int t2=t1*t1;
			while(t2<=10000){
				che[t2]=true;
				t2+=t1;
			}
			t1++;
			while(t1*t1<=10000&&che[t1])
				t1++;
		}
		for(int i=2;i< 10000;i++)
			if(!che[i])
				p[pc++]=i;
	}
	public static void solve(int k){
		for(int i=0;i< pc&&p[i]<=k;i++){
			int temp=0;
			while(k%p[i]==0){
				temp++;
				k/=p[i];
			}
			if(temp>a[i])
				a[i]=temp;
		}
	}
	public static int gcd(int x1,int x2){
		if(x2==0)
			return x1;
		return gcd(x2,x1%x2);
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		init();
		int n=in.nextInt();
		int[] q=new int[1000];
		for(int i=0;i< n;i++){
			q[i]=in.nextInt();
			solve(q[i]);
		}
		BigInteger ans1=BigInteger.ONE;
		for(int i=0;i< pc;i++)
			for(int j=0;j< a[i];j++)
				ans1=ans1.multiply(BigInteger.valueOf(p[i]));
		int ans2=0;
		for(int i=1;i< n;i++)
			if(q[0]!=q[i])
				ans2=gcd(ans2,Math.abs(q[i]-q[0]));
		if(a[0]>0)
			ans1=ans1.divide(BigInteger.valueOf(2));
		else ans2*=2;
		if(ans2==0)
			ans1=BigInteger.ZERO;
		System.out.println(ans1+" "+ans2);
	}
}


