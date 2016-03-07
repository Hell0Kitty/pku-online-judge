import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sum=in.nextInt();
		int lefttop=in.nextInt();
		cnt=new int[11][11][11][11][11];
		for (int i = 0; i < cnt.length; i++) {
			for (int j = 0; j < cnt.length; j++) {
				for (int k = 0; k < cnt.length; k++) {
					for (int l = 0; l < cnt.length; l++) {
						Arrays.fill(cnt[i][j][k][l], 0);
					}
				}
			}
		}
		for (int i = 10000; i < 100000; i++) {
			if(isPrime(i)&&dsum(i)==sum)
			{
				int[]x=new int[]{i/10000,i%10000/1000,i%1000/100,i%100/10,i%10};
				for (int j = 0; j < 1<<5; j++) {
					int[]y=new int[]{10,10,10,10,10};
					for (int k = 0; k < 5; k++) {
						int mark=1<<k;
						mark&=j;
						if(mark==0)
						{
							y[k]=x[k];
						}
					}
					cnt[y[0]][y[1]][y[2]][y[3]][y[4]]++;
				}
			}
		}
		sq=new int[5][5];
		for (int[] is : sq) {
			Arrays.fill(is, 10);
		}
		sq[0][0]=lefttop;
		list=new int[][]{{2,2},{0,4},{1,1},{1,3},{3,1},{3,3},{4,0},{4,4},
	{0,1},{0,2},{0,3},{1,0},{1,2},{1,4},{2,0},{2,1},{2,3},{2,4},{3,0},{3,2},{3,4},{4,1},{4,2},{4,3}};
		res=new ArrayList<Res>();
		dfs(0,24);
		Collections.sort(res);
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < 5; j++) {
				System.out.println(res.get(i).r[j]);
			}
			System.out.println();
		}
	}
	static class Res implements Comparable<Res>
	{
		int r[];
		
		@Override
		public int compareTo(Res o) {
			if(r[0]==o.r[0])
			{
				if(r[1]==o.r[1])
				{
					if(r[2]==o.r[2])
					{
						if(r[3]==o.r[3])
						{
							return r[4]-o.r[4];
						}
						else return r[3]-o.r[3];
					}
					else return r[2]-o.r[2];
				}
				else return r[1]-o.r[1];
			}
			else return r[0]-o.r[0];
		}

		public Res(int[] r) {
			super();
			this.r = r;
		}
	}
	
	static int[][]sq;
	static int[][]list;
	static int[][][][][]cnt;
	static ArrayList<Res> res;
	
	static void dfs(int i,int n)
	{
		if(i==n)
		{
			int[]r=new int[]{0,0,0,0,0};
			for (int j = 0; j < 5; j++) {
				for (int k = 0,l=10000; k <5; k++,l/=10) {
					r[j]+=sq[j][k]*l;
				}
			}
			res.add(new Res(r));
		}
		else
		{
			int x=list[i][0],y=list[i][1];
			if(sq[x][y]!=10)dfs(i+1,n);
			else
			{
				for (int j = 0; j < 10; j++,sq[x][y]=10) {
					sq[x][y]=j;
					if(cnt[sq[x][0]][sq[x][1]][sq[x][2]][sq[x][3]][sq[x][4]]==0)continue;
					if(cnt[sq[0][y]][sq[1][y]][sq[2][y]][sq[3][y]][sq[4][y]]==0)continue;
					if(x==y&&cnt[sq[0][0]][sq[1][1]][sq[2][2]][sq[3][3]][sq[4][4]]==0)continue;
					if(x+y==4&&cnt[sq[4][0]][sq[3][1]][sq[2][2]][sq[1][3]][sq[0][4]]==0)continue;
					dfs(i+1,n);
				}
			}
		}
	}
	
	static int dsum(int i)
	{
		return i/10000+i%10000/1000+i%1000/100+i%100/10+i%10;
	}

	static boolean isPrime(int number)
    {
    	if (number < 2) return false;
    	if (number == 2) return true;
    	if (number % 2 == 0) return false;
    	for (int i = 3; i * i <= number; i += 2)
    		if (number % i == 0) return false;
    	return true;
    }
}
