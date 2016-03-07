import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int n,dtf,m,mn,cp,cpl;
		int[][] dt;
		while (true){
			n=scanner.nextInt();
			if (n==0){
				break;
			}
			System.out.println(n);
			dt=new int[2][10000];
			dtf=0;
			while (true){
				dt[0][dtf]=scanner.nextInt();
				dt[1][dtf]=scanner.nextInt();
				if (dt[0][dtf]==0&&dt[1][dtf]==0){
					break;
				}
				dtf++;
			}
			mn=0;
			for (int i=0;i<10000 ;i++ ){
				if (dt[1][i]==0){
					break;
				}
				mn=mn+dt[1][i];
			}
			m=mn/n;
			cp=getM(dt,0,0,m,n);
			cpl=0;
			int flag=0;
			for (int i=0;i<m ;i++ ){
				if (dt[1][getV(dt,i,0,n)]-flag>4*n&&flag>=n){
					int t=dt[1][getV(dt,i,0,n)]-flag-(dt[1][getV(dt,i,0,n)]-flag)%n-n;
					if (cp==0){
						cpl=cpl+t;
					}
					else{
						System.out.println(cp+" "+cpl);
						cp=0;
						cpl=t;
					}
					flag=flag+t;
					i=i+t/n;
				}
				for (int j=0;j<n ;j++ ){
					if (getM(dt,i,j,m,n)==cp){
						cpl++;
					}
					else{
						System.out.println(cp+" "+cpl);
						cp=getM(dt,i,j,m,n);
						cpl=1;
					}
					flag++;
					if (flag>=dt[1][getV(dt,i,j,n)]){
						flag=0;
					}
					if (getE(dt,i,j,n,m)>=3&&j+getE(dt,i,j,n,m)-2<n){
						if (cp==getM(dt,i,j+1,m,n)){
							cpl=cpl+getE(dt,i,j,n,m)-2;
						}
						else{
							System.out.println(cp+" "+cpl);
							cp=getM(dt,i,j+1,m,n);
							cpl=getE(dt,i,j,n,m)-2;
						}
						flag=flag+getE(dt,i,j,n,m)-2;
						j=j+getE(dt,i,j,n,m)-2;
					}
				}
			}
			System.out.println(cp+" "+cpl);
			System.out.println("0 0");
		}
		System.out.println(0);
	}

	public static int getE(int[][] dt,int ii,int jj,int n,int m){
		if (m==1){
			return getVA(dt,ii,jj,n);
		}
		else if (m==2||ii==0){
			return getMin(getVA(dt,0,jj,n),getVA(dt,1,jj,n));
		}
		else if (ii==m-1){
			return getMin(getVA(dt,m-1,jj,n),getVA(dt,m-2,jj,n));
		}
		else{
			return getMin(getMin(getVA(dt,ii,jj,n),getVA(dt,ii+1,jj,n)),getMin(getVA(dt,ii,jj,n),getVA(dt,ii-1,jj,n)));
		}
	}

	public static int getMin(int a,int b){
		if (a<b){
			return a;
		}
		return b;
	}

	public static int getM(int[][] dt,int ii,int jj,int m,int n){
		int max=0;
		for (int i=-1;i<2 ;i++ ){
			for (int j=-1;j<2 ;j++ ){
				if (i==0&&j==0){
					continue;
				}
				else if (jj==0&&j==-1){
					continue;
				}
				else if (jj==(n-1)&&j==1){
					continue;
				}
				else if (ii==0&&i==-1){
					continue;
				}
				else if (ii==(m-1)&&i==1){
					continue;
				}
				else{
					if (Math.abs(dt[0][getV(dt,ii,jj,n)]-dt[0][getV(dt,ii+i,jj+j,n)])>max){
						max=Math.abs(dt[0][getV(dt,ii,jj,n)]-dt[0][getV(dt,ii+i,jj+j,n)]);
					}
				}
			}
		}
		return max;
	}

	public static int getV(int[][] dt,int ii,int jj,int n){
		int t=ii*n+jj+1;
		int total=0;
		int flag=0;
		while (t>total){
			total=total+dt[1][flag];
			flag++;
		}
		return flag-1;
	}

	public static int getVA(int[][] dt,int ii,int jj,int n){
		int t=ii*n+jj+1;
		int total=0;
		int flag=0;
		while (t>total){
			total=total+dt[1][flag];
			flag++;
		}
		return total-t;
	}
}