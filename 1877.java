import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String args[]) throws Exception
	{
		Scanner cin=new Scanner(System.in);
		int m,n,i,water,tmp;
		double shen;
		int r=0;
		int[] lev;
		while(true)
		{
			m=cin.nextInt();
			n=cin.nextInt();
			if(m==0&&n==0) break;
			lev=new int[m*n];
			for(i=0;i<n*m;i++)
			{
				lev[i]=cin.nextInt();
			}
			water=cin.nextInt();
			Arrays.sort(lev);
			shen=lev[0];
			for(i=0;water>0&&i<m*n-1;)
			{
				tmp=(i+1)*100*(lev[i+1]-lev[i]);
				if(tmp>=water)
				{
					shen=lev[i]+(double)water/((i+1)*100);
					water=0;
					i++;
					break;
				}
				else
				{
					water-=tmp;
					shen=lev[i+1];
					i++;
				}
			}
			if(i==(m*n-1)&&water>0) 
			{
				shen=lev[m*n-1]+(double)water/(m*n*100);
				i=m*n;
			}
			System.out.printf("Region %d\nWater level is %.2f meters.\n%.2f percent of the region is under water.\n\n",++r,shen,100.0*i/m/n);
		}
	}
}
