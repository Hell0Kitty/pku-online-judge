import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args) throws Exception{
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n,flag;
		String line,r;
		char c;
		int[] idx;
		while (true){
			n=scanner.nextInt();
			if (n==0){
				break;
			}
			line=scanner.next();
			r="";
			for (int i=0;i<26 ;i++ ){
				c=(char) ('a'+i);
				idx=new int[n];
				flag=0;
				while (line.indexOf(c)!=-1){
					idx[flag]=line.indexOf(c);
					flag++;
					line=line.replaceFirst(""+c,"#");
				}
				if (flag>=3){
					if (isD(idx,flag)){
						r=r+c;
					}
				}
			}
			if (r.equals("")){
				System.out.println("LOOOOOOOOSER!");
			}
			else{
				System.out.println(r);
			}
		}
	}

	public static boolean isD(int[] idx,int flag){
		int a,b,c;
		int aa,bb,cc;
		int[] iidx=new int[3];
		boolean f,ff1,ff2;
		for (int i=0;i<flag-2 ;i++ ){
			for (int j=i+1;j<flag-1 ;j++ ){
				for (int k=j+1;k<flag ;k++ ){
					a=getP(idx[i])-1;
					b=getP(idx[j])-1;
					c=getP(idx[k])-1;
					aa=getL(idx[i]);
					bb=getL(idx[j]);
					cc=getL(idx[k]);
					if (3*(a-b)*(a-b)+(aa-bb)*(aa-bb)==3*(a-c)*(a-c)+(aa-cc)*(aa-cc)&&3*(c-b)*(c-b)+(cc-bb)*(cc-bb)==3*(a-c)*(a-c)+(aa-cc)*(aa-cc)){
						return true;
					}
				}
			}
		}
		return false;
	}

	public static int getP(int n){
		int flag=1;
		while (true){
			if (n<=(flag)*(flag+1)/2-1){
				return flag;
			}
			flag++;
		}
	}

	public static int getL(int n){
		int p=getP(n);
		int a=n-p*(p-1)/2;
		if (p%2==0){
			return 2*a-p+1;
		}
		else{
			return 2*(a-p/2);
		}
	}
}