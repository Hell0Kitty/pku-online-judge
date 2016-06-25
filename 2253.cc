#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
pair<int ,int> a[200];            
double lowcost[200],closet[200];
double map[200][200];            
int main()
{
    int n;
    int k=1;
    while(cin>>n,n)
    {
        int i,j;
        for (i = 0 ;i < n ; i++ )
            cin>>a[i].first>>a[i].second;    
        memset(lowcost,0,sizeof(lowcost));    
        for ( i = 0 ; i < n ; i ++ )
        {
            for ( j = 0 ; j < n ; j ++ )
            {
                map[i][j]=1.0*sqrt(pow(1.0*abs(a[i].first-a[j].first),2)+pow(1.0*abs(a[i].second-a[j].second),2));
            }
        }
        double ans=0.0;
        for ( i = 0 ; i< n ; i++ )
        {
            lowcost[i]=map[0][i];
            closet[i]=0;
        }

        for ( i = 0 ; i < n - 1 ; i ++ )
        {
            double mindis=1.0*(1<<20);        
            int minone;                        
            for ( j = 0 ; j < n ; j ++ )
            {
                if(lowcost[j]&&mindis>lowcost[j])
                {
                    mindis=lowcost[j];
                    minone=j;
                }
            }
            if(ans<mindis)        
                ans=mindis;        
            lowcost[minone]=0.0;
            if(minone==1)        
                break;
            for ( j = 0 ; j < n ; j ++ )
            {
                if(map[j][minone]<lowcost[j])
                {
                    lowcost[j]=map[j][minone];
                    closet[j]=minone;
                }
            }
        }
        cout<<"Scenario #"<<k<<endl;
        printf("Frog Distance = %.3f\n\n",ans);
        k++;
    }
    return 0;
}



