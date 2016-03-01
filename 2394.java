//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;
public class Main
{
	public static int mat[][]=new int[505][505];
	public static int d[]=new int[505];
	public static void main(String args[]) throws Exception {
		Scanner cin=new Scanner(System.in);
		int F,P,C,M;
		int i,j,k;
		int a,b,c;
		F=cin.nextInt();
		P=cin.nextInt();
		C=cin.nextInt();
		M=cin.nextInt();
		for(i=0;i< F;++i)
		  for(j=0;j< F;++j)
		    mat[i][j]=i==j?0:1000000000;
		while(P>0)
		{
			--P;
			a=cin.nextInt();
			b=cin.nextInt();
			c=cin.nextInt();
			--a;
			--b;
			if(c< mat[a][b])
				mat[a][b]=mat[b][a]=c;
		}
		for(i=0;i< F;++i)d[i]=1000000000;
		d[0]=0;
		boolean v[]=new boolean[505];
		Arrays.fill(v, false);
		for(i=0;i< F;++i)
		{
			k=-1;
			for(j=0;j< F;++j)
		           if(!v[j]&&(k==-1||d[j]< d[k]))k=j;
			for(v[k]=true,j=0;j< F;++j)
			   if(!v[j]&&d[k]+mat[k][j]< d[j])
				d[j]=d[k]+mat[k][j];
		}
		int hash[]=new int[505];
		Arrays.fill(hash, -1);
		for(i=0;i< C;++i)
		{
			c=cin.nextInt();
			--c;
			hash[i]=c;
		}
		int ans=0;
		for(i=0;i< C;++i)
			if(hash[i]!=-1&&d[hash[i]]<=M)
				++ans;
		System.out.println(ans);
		for(i=0;i < C;++i)
			if(hash[i]!=-1&&d[hash[i]]<=M)
				System.out.println(i+1);
	}
}

