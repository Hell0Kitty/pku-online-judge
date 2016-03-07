import java.util.*;
import java.io.*;

public class Main{
 public static int[][] chart;
 public static void main(String[] args){
  init();
  Scanner in=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
  int p=in.nextInt();
  for (int k=0;k< p ;k++ ){
   int m=in.nextInt();
   String a=in.next();
   int n=in.nextInt();
   String b=in.next();
   int[][] c=new int[m+1][n+1];
   for (int i=0;i<=m ;i++ ){
    for (int j=0;j<=n ;j++ ){
     if (i==0&&j==0){
      c[i][j]=0;
     }
     else if(i==0){
      c[i][j]=c[i][j-1]+getValue(b.charAt(j-1),'-');
     }
     else if (j==0){
      c[i][j]=c[i-1][j]+getValue(a.charAt(i-1),'-');
     }
     else{
      int x=getValue(a.charAt(i-1),'-');
      int y=getValue(b.charAt(j-1),'-');
      int z=getValue(a.charAt(i-1),b.charAt(j-1));
      c[i][j]=max(c[i-1][j]+x,c[i][j-1]+y,c[i-1][j-1]+z);
     }
    }
  }
   System.out.println(c[m][n]);
  }
}

	public static void init(){
		chart=new int[5][5];
		chart[0][0]=5;
		chart[0][1]=-1;
		chart[0][2]=-2;
		chart[0][3]=-1;
		chart[0][4]=-3;
		chart[1][0]=-1;
		chart[1][1]=5;
		chart[1][2]=-3;
		chart[1][3]=-2;
		chart[1][4]=-4;
		chart[2][0]=-2;
		chart[2][1]=-3;
		chart[2][2]=5;
		chart[2][3]=-2;
		chart[2][4]=-2;
		chart[3][0]=-1;
		chart[3][1]=-2;
		chart[3][2]=-2;
		chart[3][3]=5;
		chart[3][4]=-1;
		chart[4][0]=-3;
		chart[4][1]=-4;
		chart[4][2]=-2;
		chart[4][3]=-1;
	}

	public static int getValue(char a,char b){
		int ai=getIndex(a);
		int bi=getIndex(b);
		return chart[ai][bi];
	}

	public static int getIndex(char a){
		switch (a){
			case 'A':
				return 0;
			case 'C':
				return 1;
			case 'G':
				return 2;
			case 'T':
				return 3;
			case '-':
				return 4;
			default :
				return -1;
		}
	}

	public static int max(int a,int b,int c){
		int m=0;
		if (a>=b){
			if (a>=c){
				m=a;
			}
			else{
				m=c;
			}
		}
		else{
			if (b>=c){
				m=b;
			}
			else{
				m=c;
			}
		}
		return m;
	}
}

