#include<stdio.h>
bool leap(int y)
{
	if(y%4==0&&y%100!=0||y%4==0)return 1;
	return 0;
}
int day(int y,int m)
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)return 31;
	else if(m==4||m==6||m==9||m==11)return 30;
	else if(leap(y))return 29;
	return 28;
}
int main()
{
	int y,m,d,ans,i;
	scanf("%d%d%d",&y,&m,&d);d=d-1;
	for(i=1;i<m;i++)d+=day(y,i);
	ans=((y+(y-1)/400-(y-1)/100+(y-1)/4)%7+d)%7;
	char dd[7][11]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
	printf("%s\n",dd[ans]);
	return 0;
}



