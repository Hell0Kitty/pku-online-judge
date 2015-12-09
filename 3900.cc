#include <stdio.h>
#include <iostream>
using namespace std; 



int weight[10000  ];
int cost[10000 ];
int res[10000 ][80];            



void knap(int m,int n){
	printf("LINE%d\n", __LINE__);
	cout<< m << " " << n << endl;
    for(int j=0;j < m + 1;j++)
      for(int i = 0; i < n + 1;i++)
    {
        if(j < weight[i])
        {
            res[i][j]=res[i-1][j];
            continue;

        }else if(res[i-1][j-weight[i]]+cost[i]>res[i-1][j])
            res[i][j]=res[i-1][j-weight [i]]+cost[i];
        

        else
            res[i][j]=res[i-1][j];
    }

    cout<< "Final result: " << res[m][n] << endl;

    
}      



int main(int argc, char const *argv[])
{
	int ncase; 
	scanf("%d", &ncase);
	while(ncase --){
	  int n, m; 
	  scanf("%d%d", &n, &m);
	  for (int i = 1; i < n + 1; ++i)
	  {
	  	scanf("%d",&weight[i] );
	  }


	  	  for (int i = 1; i < n + 1; ++i)
	  {
	  	scanf("%d",&weight[i] );
	  }


	  for (int i = 1; i < n + 1; ++i)
	  {
	  	scanf("%d",&cost[i] );
	  }
	  printf("LINE%d\n", __LINE__);
	  knap(m, n);


	}

	return 0;
}