import java.util.Scanner;
public class Main{
	static short[] p,d;
	static short[][][] arr,path;
	static int add,a,b,st,ed;
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int cnt=0;
		while(true)
		{
			cnt++;
			a=in.nextInt();
			b=in.nextInt();
			if(a==0&&b==0)break;
			System.out.println("Jury #"+cnt);
			p=new short[a+1];
			d=new short[a+1];
			for(int i=1;i<=a;i++)
			{
				p[i]=in.nextShort();
				d[i]=in.nextShort();
			}
			dp();
			for(int k=0;k<=add;k++)
			{
				if(arr[a][b][add+k]>arr[a][b][add-k])
				{
					System.out.println("Best jury has value "+((arr[a][b][add+k]+k)/2)+
							" for prosecution and value "+((arr[a][b][add+k]-k)/2)+" for defence:");
					print(a,b,k);
					break;
				}
				else if(arr[a][b][add-k]!=-1)
				{
					System.out.println("Best jury has value "+((arr[a][b][add-k]-k)/2)+
							" for prosecution and value "+((arr[a][b][add-k]+k)/2)+" for defence:");
					print(a,b,-k);
					break;
				}
			}
			System.out.println();
			System.out.println();
		}
	}
	static void dp()
	{
		arr=new short[a+1][b+1][40*b+30];
		path=new short[a+1][b+1][40*b+30];
		add=20*b;
		st=-b*20;ed=-st;
		for(int i=0;i<=a;i++)
			for(int j=0;j<=b;j++)
				for(int k=st;k<=ed;k++)
					arr[i][j][k+add]=-1;
		arr[0][0][add]=0;
		for(int i=1;i<=a;i++)
			for(int j=0;j<=b;j++)
				for(int k=st;k<=ed;k++)
				{
					arr[i][j][k+add] = arr[i-1][j][k+add];
					path[i][j][k+add]=1;
					if(j>0&&k-p[i]+d[i]>=-add&&k-p[i]+d[i]<=add&&arr[i-1][j-1][k-p[i]+d[i]+add]!=-1
							&&arr[i-1][j-1][k-p[i]+d[i]+add]+p[i]+d[i]>arr[i][j][k+add])
					{
						arr[i][j][k+add]=(short) (arr[i-1][j-1][k-p[i]+d[i]+add]+p[i]+d[i]);
						path[i][j][k+add]=2;
					}
				}
	}
	static void print(int i,int j,int k)
	{
		if(i == 0 && j == 0 && k == 0) return ;
		if(path[i][j][k+add] == 1)
		   print(i-1, j, k);
		else{
		   print(i-1, j-1, k-p[i]+d[i]);
		   System.out.print(" "+i);
		}
	}
}