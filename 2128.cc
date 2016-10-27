#include  <stdio.h>

int main()
{
	int N;	//有N个村庄
	scanf("%d",&N);

	int pos;	//临时保存各个村庄现在的坐标点
	int pre=0;    //临时保存村庄过去的坐标点
	int sum=0;
	int i;
	int minRoad=0x7fffffff;
	int start;
	for(i=2;i<=N;i++)
	{
		//输入每个村庄pos坐标，村庄1的坐标为0
		scanf("%d",&pos);
		sum+=(pos-pre);

		if (i!=2 && i!=N && pos-pre<minRoad)
		{
			minRoad=pos-pre;
			start=i-1;
		}

		pre=pos;
	}

	if (N<4)
	{
		printf("0\n");
		return 0;
	}

	printf("%d\n",sum+minRoad);
	printf("%d %d %d %d\n",N,1,start,start+1);   

	return 0;
}



