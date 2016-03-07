import java.util.Scanner;
public class Main
{
	static final int Inf=9999999;
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int cnt=0;
		while(true)
		{
			cnt++;
			int n=in.nextInt();
			int m=in.nextInt();
			if(n==0&&m==0)break;
			int[][] p=new int[n][n];
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					p[i][j]=Inf;
			for(int i=0;i<m;i++)
			{
				int x=in.nextInt()-1;
				int y=in.nextInt()-1;
				int len=in.nextInt();
				p[x][y]=p[y][x]=len;
			}
			boolean[] bb=new boolean[n];
			bb[0]=true;
			int[] time=new int[n];
			for(int i=0;i<n;i++)
				time[i]=p[0][i];
			time[0]=0;
			for(int i=0;i<n-1;i++)
			{
				int min=Inf,tag=0;
				for(int j=0;j<n;j++)
				{
					if(!bb[j]&&time[j]<min)
					{
						min=time[j];
						tag=j;
					}
				}
				bb[tag]=true;
				for(int j=0;j<n;j++)
					if(!bb[j]&&p[tag][j]<Inf&&time[tag]+p[tag][j]<time[j])
						time[j]=time[tag]+p[tag][j];
			}
			double maxtime=-Inf;
			int pos=-1;
			for(int i=0;i<n;i++)
			{
				if(time[i]>maxtime)
				{
					maxtime=time[i];
					pos=i;
				}
			}
			double max=-Inf,t;
			int pos1=-1,pos2=-1;
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					t=(time[i]+time[j]+p[i][j])/2.0;
					if(p[i][j]<Inf&&t>max)
					{
						max=t;
						pos1=i;pos2=j;
					}
				}
			}
			System.out.println("System #"+cnt);
			System.out.print("The last domino falls after ");
			if(maxtime>=max)
				System.out.printf("%.1f seconds, at key domino %d.\n\n",maxtime,pos+1);
			else System.out.printf("%.1f seconds, between key dominoes %d and %d.\n\n",max,pos1+1,pos2+1);
		}
	}
}
