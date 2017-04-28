#include<iostream>
#include<algorithm>
using namespace std;
#define N1 201
int tree[N1][N1];
bool cmp( const int a , const int b )
{
    return a>b;
}
int DFS( int node)
{
      int  num[N1], _max, i;
      if(!tree[node][0])
          return  1;
      else
      {
          for(i=1;i<=tree[node][0];++i)
              num[i-1] = DFS( tree[node][i] );
          sort( num , num + tree[node][0] , cmp );
          for( i = 0 , _max = -1 ; i < tree[node][0] ; ++i )
          {
              if( _max < num[i] + i )
              { _max = num[i] + i; }
          }
          return _max;
      }

}
int main()
{
    int i,j, M,N,p;
    scanf("%d",&M);
    while(M--)
    {
        scanf("%d",&N);
        for(i=1;i<=N;i++)
        {
            scanf(" %d %d",&p,&tree[i][0]);
                for(j=1;j<=tree[i][0];j++)
                    scanf("%d",&tree[i][j]);
        }
            printf("%d\n",DFS(1));

            memset(tree,0, sizeof(tree));
    }
    return 0;

}



