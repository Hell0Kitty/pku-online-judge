import java.util.*;
public class Main {
 public static void main(String[] args){
  Scanner in = new Scanner(System.in);

int K,L;
char key[]=new char[100];
char letter[]=new char[100];
int F[]=new int[100];
int p[]=new int[100];
int best;
int map[][][]=new int[100][100][100];
int father[][]=new int[100][100];
int q[]=new int[100];

	int t,c;
	int i,j,m,n;
	int limitA,limitB;
	char str[]=new char[100];
       t=in.nextInt();
	c=0;
	while(c<t)
	{
		c++;
		K=in.nextInt();
              L=in.nextInt();
		str=in.next().toCharArray();
		for(i=1;i<=K;i++) key[i]=str[i-1];
		str=in.next().toCharArray();

		for(i=1;i<=L;i++) letter[i]=str[i-1];
		for(i=1;i<=L;i++) F[i]=in.nextInt();
		for(i=1;i<=K;i++)
		{
			for(j=1;j<=L;j++)
			{
				for(m=1;m<=j;m++)
				{
					map[i][j][m]=-1;
				}
			}
		}
		limitA=L-K+1;
		map[1][1][1]=F[1];
		for(i=2;i<=L;i++)
		{
			for(j=2;j<=i && j<=K;j++)
			{
				limitB=i-j+1;
				for(m=1;m<=limitA && m<=limitB;m++)
				{
					if(map[j-1][i-1][m]>=0)
					{
						if(map[j][i][1]<0 || map[j][i][1]>=map[j-1][i-1][m]+F[i])
						{
							map[j][i][1]=map[j-1][i-1][m]+F[i];
							father[j][i]=m;
						}
					}
				}
			}
			for(j=1;j<=i && j<=K;j++)
			{
				limitB=i-j+1;
				for(m=2;m<=limitA && m<=limitB;m++)
				{
					if(map[j][i-1][m-1]>=0)
					{
						map[j][i][m]=m*F[i]+map[j][i-1][m-1];
					}

				}
			}
		}
		best=1000000000;
		for(i=1;i<=L;i++)
		{
			if(map[K][L][i]>=0 && map[K][L][i]<=best)
			{
				j=K;m=L;n=i;
				while(m>=1)
				{
					q[j]=1;
					while(n>1)
					{
						n--;m--;
						q[j]++;
					}
					n=father[j][m];
					m--;
					j--;
				}
				best=map[K][L][i];
				for(j=1;j<=K;j++)p[j]=q[j];
			}
		}
		m=0;
		System.out.printf("Keypad #%d:\n",c);
		for(i=1;i<=K;i++)
		{
			System.out.printf("%c: ",key[i]);
			n=p[i];
			while(n-->0)
			{
				m++;
				System.out.printf("%c",letter[m]);
			}
			System.out.printf("\n");
		}
		System.out.printf("\n");
	}
  }
}
