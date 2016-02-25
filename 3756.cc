#include<iostream>
#include<fstream>

using namespace std;

int num1,num2,num3;
int a[101];
int b[101],c[101];
double dp[300][101];
int n;

int ok(int s){

    while(1){
        if(s>n) s=2*n-s;
        else if(s<0) s=-s;
        else return s;
    }
}

void read(){
//    ifstream cin("in.txt");
    int i,j,k;
    cin>>n;
    cin>>num1;
    for(i=1;i<=num1;i++)
    {
        cin>>j>>k;
        a[j]=1;
        b[j]=k;
    }
    cin>>num2;
    for(i=1;i<=num2;i++)
    {
        cin>>j>>k;
        a[j]=2;
        c[j]=k;
    }
    cin>>num3;
    for(i=1;i<=num3;i++)
    {
        cin>>j;
        a[j]=3;
    }
    dp[0][0]=1;
    for(i=0;i<200;i++)
    {
        for(j=0;j<n;j++)
            if(dp[i][j]>0)
            {
                for(k=1;k<=6;k++)
                {
                    int s=ok(j+k);
                    if(a[s]==3)
                    {
                        dp[i+2][s]+=dp[i][j]*1/6;
                    }
                    else
                    {
                        if(a[s]==1) s=ok(b[s]+s);
                        else if(a[s]==2) s=ok(s-c[s]);
                        dp[i+1][s]+=dp[i][j]*1/6;
                    }
                }
            }
    }
    double ans=0;
    for(i=1;i<200;i++)
        ans+=i*dp[i][n];

    if(ans<0.005)
        printf("Impossible\n");
    else
        printf("%.2lf\n",ans);

}

int main(){
    read();
    return 0;
}


