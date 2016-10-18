#include <stdio.h>  

#define MAX_N 100000  

int n;  
int h[MAX_N];  
int L[MAX_N], R[MAX_N];  
int stack[MAX_N];  

long long max(long long a, long long b){  
    return (a > b) ? a : b;  
}  

void solve(){  

    long long ans = 0;  
    int t = 0;  
    int i;  
    for (i = 0; i < n; ++i){  
        while (t > 0 && h[stack[t-1]] >= h[i]) t--;  
        L[i] = (t == 0) ? 0 : (stack[t-1] + 1);  
        stack[t++] = i;  
    }  

    t = 0;  
    for (i = n - 1; i >= 0; --i){  
        while (t > 0 && h[stack[t-1]] >= h[i]) t--;  
        R[i] = (t == 0) ? n : stack[t-1];  
        stack[t++] = i;  
    }  

    for (i = 0; i < n; ++i){  
        ans = max(ans, (long long)h[i] * (R[i] - L[i]));  
    }  
    printf("%lld\n", ans);  
}  

int main(void){  
    int i;  
    while (scanf("%d", &n) != EOF && n != 0){  
        for (i = 0; i < n; ++i)  
            scanf("%d", &h[i]);  
        solve();  
    }  

    return 0;  
}



