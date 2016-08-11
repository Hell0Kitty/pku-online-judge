#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
#include <algorithm>

#define MAXINT 99999999

using namespace std;

int data[100+4][100+4];

int dis[100*100+4];

int main(int argc, char *argv[])
{

        int t;
        int n,m;

        int i,j,k;

        scanf("%d",&t);

        int p;

        int z;
        for(z=1;z<=t;z++)
        {
                         scanf("%d",&p);
                         scanf("%d",&n);

                         for(i=1;i<=n;i++)
                         {
                                          for(j=1;j<=n;j++)
                                          {
                                                           scanf("%d",&data[i][j]);
                                                           if(data[i][j]<=0)
                                                           data[i][j]=MAXINT;
                                          }
                         }

                         for(k=1;k<=n;k++)
                         for(i=1;i<=n;i++)
                         for(j=1;j<=n;j++)
                         {if(data[i][j]>data[i][k]+data[k][j])
                          data[i][j]=data[i][k]+data[k][j];
                         }

                         k=0;
                         for(i=1;i<=n;i++)
                         for(j=1;j<=n;j++)
                         {

                                          if(i==j)
                                          continue;
                                          if(data[i][j]>=MAXINT)
                                          continue;
                                          dis[k]=data[i][j];
                         k++;
                         }

                             sort(dis,dis+k);

                             k=n*(n-1)*p;

                             if(k%100==0)
                             k=k/100;
                             else
                             k=k/100+1;

                             printf("Scenario #%d:\n%d\n\n",z,dis[k-1]);

        }

    return EXIT_SUCCESS;
}



