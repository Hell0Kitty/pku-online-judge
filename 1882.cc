#include<iostream>

using namespace std;

bool dp[11][1001];

int a[11][1001];

void read(){

    int i,j,k,s,t,ans,ans1,num,n,f,right,s1;

    while(1){

        cin>>num;

        if(num==0) return;

        cin>>k;

        ans=0;ans1=0;

        for(i=1;i<=k;i++)

        {

            cin>>n;

            a[i][0]=n;

            right=0;

            memset(dp,0,sizeof(dp));

            dp[0][0]=1;

            for(f=1;f<=n;f++)

            {

                cin>>s;a[i][f]=s;

                int end=right;

            for(s1=0;s1<num;s1++)

            for(j=0;j<=end;j++)

                if(dp[s1][j])

                {

                    for(t=1;t+s1<=num;t++)

                    {

                        dp[t+s1][j+s*t]=1;

                        if(right<j+s*t) right=j+s*t;

                    }

                }

            }

            for(j=1;;j++)

            {

                for(s=1;s<=num;s++)

                    if(dp[s][j])

                        break;

                if(s>num) break;

            }

            if(ans<j) {

                ans=j;

                ans1=i;

            }

            else

                if(ans==j)

                {

                    if(a[ans1][0]>a[i][0])

                    {

                        ans1=i;

                    }

                    else

                    {

                        if(a[ans1][a[ans1][0]]>a[i][a[i][0]])

                            ans1=i;

                    }

                }

        }

        printf("max coverage = %d : ",ans-1);

        for(i=1;i<=a[ans1][0];i++)

            cout<<a[ans1][i]<<' ';

        cout<<endl;

    }

}

int main(){

    read();

    return 0;

}


