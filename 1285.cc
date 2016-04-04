#include<iostream>

#include<string.h>

using namespace std;

int n,m;

long long dp[51][51];

int num[51];

void read(){

    int i,j,k;

    int K;

    int ans=0;

    while(1)

    {

        cin>>n>>m;

        if(n==0&&m==0) return;

        memset(num,0,sizeof(num));

        memset(dp,0,sizeof(dp));

        ans++;

        cout<<"Case "<<ans<<':'<<endl;

        for(i=1;i<=n;i++)

        {

            cin>>j;

            num[j]++;

        }

        for(i=1;i<=n;i++)

            dp[i][0]=1;

        for(i=1;i<=num[1];i++)

            dp[1][i]=1;

        for(i=2;i<=n;i++)

            for(j=1;j<=n;j++)

                for(k=0;k<=j&&k<=num[i];k++)

                    dp[i][j]+=dp[i-1][j-k];

        for(i=1;i<=m;i++)

        {

            cin>>j;

            cout<<dp[n][j]<<endl;

        }

    }

}

int main(){

    read();

    return 0;

}


