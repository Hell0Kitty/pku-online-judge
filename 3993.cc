#include<cstdio>  
#include<cmath>  
#include<cstring>  
using namespace std;  
typedef long long ll;  
const int N = 1000001;  
int p[N], ans[N], vis[N], a, b;  
void initPrime()  
{  
    int num = 0, m = sqrt (N + 0.5);  
    for (int i = 2; i <= m; ++i)  
        if (vis[i] == 0)  
            for (int j = i * i; j <= N; j += i) vis[j] = 1;  
    for (int i = 2; i <= N; ++i)  
        if (vis[i] == 0) p[++num] = i;  
}  

int main()  
{  
    initPrime();  
    int cas=0;  
    while (scanf ("%d%d", &a, &b),a)  
    {  
        int cnt = 0, ans = 0, ca, cb;  
        for (int i = 1; a > 1 || b > 1; ++i)  
            if (a % p[i] == 0 || b % p[i] == 0)  
            {  
                ++cnt, ca = cb = 0;  
                while (a % p[i] == 0) a /= p[i], ++ca;  
                while (b % p[i] == 0) b /= p[i], ++cb;  
                ans += (ca > cb ? ca - cb : cb - ca);  
            }  
        printf ("%d. %d:%d\n", ++cas,cnt, ans);  
    }  
    return 0;  
}


