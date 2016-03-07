import java.util.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		BigInteger B=new BigInteger("10");
		while(in.hasNext()){
			double R=in.nextDouble();
			int n=in.nextInt(),r=0,w;
			if(R==0){System.out.println("0");continue;}
			else{
				w=位数((int)R);
				switch(w){
				case 1:r=(int)(R*10000);break;
				case 2:r=(int)(R*1000);break;
				case 3:r=(int)(R*100);break;
				case 4:r=(int)(R*10);break;
				}
			}
			w=5-w;
			BigInteger b=new BigInteger(""+r).pow(n);//b就是此题结果（没小数点）
			int[] ar=new int[125];
			for(int i=0;i<125;i++){
				ar[i]=b.remainder(B).intValue();
				b=b.divide(B);
			}
			int a=0,c=0;
			for(int i=0;ar[i]==0&&i<n*w;i++)c++;
			for(int i=124;ar[i]==0&&i>=n*w;i--)a++;
			for(int i=124-a;i>=n*w;i--)System.out.print(ar[i]);
			if(c!=n*w)System.out.print(".");
			for(int i=n*w-1;i>=c;i--)System.out.print(ar[i]);
			System.out.println();
		}
	}
    static int 位数(int x){
    	int i=1;
    	for(int j=1;x/10!=0;j++){
    		i++;
    		x/=10;
    	}
    	return i;
    }
}
