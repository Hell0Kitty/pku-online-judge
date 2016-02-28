import java.io.*;
import java.util.*;

public class Main{
	static Scanner cin;
	public static void main(String args[]){
		cin  = new Scanner(System.in);
		int M = cin.nextInt();
		for(int i=0;i<M;i++)
			run();
	}
	
	static void run(){
		int N = cin.nextInt();
		int[][] d = new int[N+1][N+1];
		for(int i=1;i<N;i++)
			for(int j=i+1;j<=N;j++)
				d[i][j] = cin.nextInt();
		
		int[][][] f = new int[N+1][N+1][N+1];
		 for(int i=1;i<=N;i++)//初始化
            for(int j=1;j<=N;j++)
                for(int k=1;k<=N;k++)
                    f[i][j][k]=10000;
		f[1][1][1] = 0;
		for(int k=2;k<=N;k++)
			for(int i=1;i<k;i++)
				for(int j=1;j<k;j++){
					if(f[i][j][k-1]+d[i][k]<f[j][k-1][k]){
						f[j][k-1][k]=f[i][j][k-1]+d[i][k];
						f[k-1][j][k]=f[i][j][k-1]+d[i][k];
					}
					if(f[i][j][k-1]+d[j][k]<f[i][k-1][k]){
						f[i][k-1][k]=f[i][j][k-1]+d[j][k];
						f[k-1][i][k]=f[i][j][k-1]+d[j][k];
					}
					if(f[i][j][k-1]+d[k-1][k]<f[i][j][k]){
						f[i][j][k]=f[i][j][k-1]+d[k-1][k]; 
						f[j][i][k]=f[i][j][k-1]+d[k-1][k];
					}
				} 
		
		 int opt=f[1][1][N];
         for(int i=1;i<N;i++)
             for(int j=1;j<N;j++)
                 if(f[i][j][N]<opt)
                 	opt=f[i][j][N];
		System.out.println(opt);
	}
}