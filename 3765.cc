#include<stdio.h>
#include<math.h>

char map[21][10];
int main(){
	int i,a,n,j;
	while(scanf("%d",&n),n)
	{
		for(i=0;i<21;i++)
			for(j=0;j<10;j++)
				map[i][j]=' ';
		while(n--){
			char c,ch;		
			c=getchar();	while(c==' ' || c=='\n')c=getchar();
			scanf("%d %c",&a,&ch);
			map[21-abs('E'-c)-a*2-1] [c-'A'+1]=ch;
		}
		printf("         _\n");
		printf("       _/%c\\_\n",map[0][5]);
		printf("     _/%c\\_/%c\\_\n",map[1][4],map[1][6]);
		printf("   _/%c\\_/%c\\_/%c\\_\n",map[2][3],map[2][5],map[2][7]);
		printf(" _/%c\\_/%c\\_/%c\\_/%c\\_\n",map[3][2],map[3][4],map[3][6],map[3][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[4][1],map[4][3],map[4][5],map[4][7],map[4][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[5][2],map[5][4],map[5][6],map[5][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[6][1],map[6][3],map[6][5],map[6][7],map[6][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[7][2],map[7][4],map[7][6],map[7][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[8][1],map[8][3],map[8][5],map[8][7],map[8][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[9][2],map[9][4],map[9][6],map[9][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[10][1],map[10][3],map[10][5],map[10][7],map[10][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[11][2],map[11][4],map[11][6],map[11][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[12][1],map[12][3],map[12][5],map[12][7],map[12][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[13][2],map[13][4],map[13][6],map[13][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[14][1],map[14][3],map[14][5],map[14][7],map[14][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[15][2],map[15][4],map[15][6],map[15][8]);
		printf("/%c\\_/%c\\_/%c\\_/%c\\_/%c\\\n",map[16][1],map[16][3],map[16][5],map[16][7],map[16][9]);
		printf("\\_/%c\\_/%c\\_/%c\\_/%c\\_/\n",map[17][2],map[17][4],map[17][6],map[17][8]);
		printf("  \\_/%c\\_/%c\\_/%c\\_/\n",map[18][3],map[18][5],map[18][7]);
		printf("    \\_/%c\\_/%c\\_/\n",map[19][4],map[19][6]);
		printf("      \\_/%c\\_/\n",map[20][5]);
		printf("        \\_/\n");
	}
	return 0;
}



