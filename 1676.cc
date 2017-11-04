#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int const num[15]={119,36,93,109,46,107,123,37,127,111};
int a[5],b[5],now[5][15],bef[5][15],t1[2][100],t2[2][100];
int nowcnt[5],befcnt[5],t1cnt[2],t2cnt[2];
char str[4][30];
void add(char a,char b,char c,int &o,int x,int y,int z)//计算该行所表示的o的权 
{
	if (a!=' ')
		o+=(1<<x);
	if (b!=' ')
		o+=(1<<y);
	if (c!=' ')
		o+=(1<<z); 
}
int PossiNum(int a,int A[])//将残缺的LED所可能的数字找出来 
{
	int cnt=0,i;
	for (int i=0;i<10;i++)
		if (((a&num[i])|(a^num[i]))==num[i])
			A[cnt++]=i;
	return cnt;
}
void PossiTime(int x[5][15],int y[2][100],int xlen[],int ylen[])//将所有的小时，分钟存入数组y 
{
	int i,j,h,m;
	for (i=0;i<xlen[0];i++)
		for (j=0;j<xlen[1];j++){
			h=x[0][i]*10+x[1][j];
			if (h<24)
				y[0][ylen[0]++]=h;
		}
	for (i=0;i<xlen[2];i++)
		for (j=0;j<xlen[3];j++){
			m=x[2][i]*10+x[3][j];
			if (m<59)
				y[1][ylen[1]++]=m;
		}
}
bool Accurate(int &h,int &m)//计算是否存在唯一可能 
{
	int i,j,p,q,cnt=0,h1,m1,h2,m2;
	memset(t1cnt,0,sizeof(t1cnt));
	memset(t2cnt,0,sizeof(t2cnt));
	PossiTime(now,t1,nowcnt,t1cnt);
	PossiTime(bef,t2,befcnt,t2cnt);
	for (i=0;i<t2cnt[0]&&cnt<2;i++)//第二个钟 
		for (j=0;j<t2cnt[1]&&cnt<2;j++){
			m2=t2[1][j]+15;
			h2=t2[0][i];
			if (m2>59){//处理进位 
				h2++;
				m2%=60;
			}
			if (h2>23)//最开始写成24了，wa一次 
				h2=0;
			for (p=0;p<t1cnt[0]&&cnt<2;p++)
				for (q=0;q<t1cnt[1]&&cnt<2;q++){
					m1=t1[1][q];
					h1=t1[0][p];
					if (h1==h2&&m1==m2){//比较是否相等 
						cnt++;
						h=h1,m=m1;
						if (cnt>=2)
							return 0;
					}
				}
		}
	if (cnt==1)
		return 1;
	return 0;
}
void slove()
{
	int i,j,h,m;
	for (i=0;i<5;i++)
		a[i]=b[i]=0;
	for (i=1;i<12;i+=3)//计算出两个钟，八个数字的权值 
		if (str[0][i]!=' ')
			a[i/3]+=1;
	for (++i;i<25;i+=3)
		if (str[0][i]!=' ')
			b[(i/3)%4]+=1;	
	for (i=0;i<12;i+=3)
		add(str[1][i],str[1][i+1],str[1][i+2],a[i/3],1,3,2); 
	for (++i;i<25;i+=3)
		add(str[1][i],str[1][i+1],str[1][i+2],b[(i/3)%4],1,3,2); 
	for (i=0;i<12;i+=3)
		add(str[2][i],str[2][i+1],str[2][i+2],a[i/3],4,6,5); 
	for (++i;i<25;i+=3)
		add(str[2][i],str[2][i+1],str[2][i+2],b[(i/3)%4],4,6,5); 
	for (i=0;i<4;i++){
		nowcnt[i]=PossiNum(a[i],now[i]);
		befcnt[i]=PossiNum(b[i],bef[i]);
	}
	if (!Accurate(h,m))
		printf("Not Sure\n");
	else {
		if (h/10==0)
			printf("0");
		printf("%d",h);
		if (m/10==0)
			printf("0");
		printf("%d\n",m); 
	}
}

int main()
{
	int t,i;
	scanf("%d",&t);
	getchar();
	while (t--){
		for (i=0;i<3;i++)
			gets(str[i]);
		slove();
	}
	return 0;
}


