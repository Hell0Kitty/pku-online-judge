#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <algorithm>  
#include <iostream>  
using namespace std;  
#define CLE(a,b) memset(a,b,sizeof(a))  
#define MEC(a,b) memcpy(a,b,sizeof(a))  
#define ll long long  
const int ll mod = 100007;  
ll Hash[mod],pos[mod],top[mod],x[mod];  
int n;  
int get_Hash(ll num)  
{  
    int tmp = (num%mod+mod)%mod;  
    while(Hash[tmp]!=-1&&Hash[tmp]!=num)tmp = (tmp+1)%mod;  
    return tmp;  
}  
int main()  
{  
    while(~scanf("%d",&n)&&n)  
    {  
        ll ans = 0;  
        CLE(top,0);CLE(Hash,-1);  
        for(int i=0; i<n; i++)  
        {  
            for(int j=0; j<5; j++)  
            {  
                scanf("%I64d",&x[j]);  
            }  
            sort(x,x+5);  
            ll tmp = 0;  
            for(int j=0; j<5; j++)  
            {  
                tmp = tmp*1000+x[j];  
            }  
            int in = get_Hash(tmp);  
            Hash[in] = tmp;  
            ans = max(ans,++top[pos[i]=in]);  
        }  
//        cout<<ans<<endl;  
        int sum = 0;  
        for(int j=0; j<n; j++)  
        {  
            if(top[pos[j]]==ans)sum++;  
        }  
        printf("%d\n",sum);  
    }  
    return 0;  
}  
