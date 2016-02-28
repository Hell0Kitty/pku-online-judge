import java.util.Scanner;
public class Main {
 public static void main(String[] args){
  Scanner scan=new Scanner(System.in);
   int[][] N=new int[1001][1001];
   int[][] M=new int[1001][1001];
   int k=scan.nextInt();
   int n=0,m=0,d,maxA;
   for(int z=0;z< k;z++){
	maxA=0;
	m=scan.nextInt();
	n=scan.nextInt();
    for(int i=0;i< m;i++)
	  for(int j=0;j< n;j++)
	   if(scan.next().equals("F"))
	    M[i][j]=N[i][j]=1; else M[i][j]=N[i][j]=0;
	for(int i=0;i< m;i++) for(int j=n-2;j>=0;j--) if(N[i][j]!=0)N[i][j]+=N[i][j+1];
	for(int i=0;i< n;i++) for(int j=m-2;j>=0;j--) if(M[j][i]!=0)M[j][i]+=M[j+1][i];
	for(int i=0;i< m;i++)
		for(int j=0;j< n;j++){
			d=N[i][j];
			for(int l=0;l< M[i][j];l++){
				if(N[i+l][j]< d)d=N[i+l][j];
				if(d*(l+1)>maxA)maxA=d*(l+1);
			}
		}
	System.out.println(maxA*3);
  }
 }
}

