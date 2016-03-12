#include <stdio.h>  
#define N 101  
  
int main()  
{  
    int a[N] = {0}, ///最下面一种盘 反向  
        b[N] = {0}, ///最下面一种盘 正向  
        s[N],m,n;  
  
    while(scanf("%d%d",&n,&m) != EOF)  
    {  
        int i,j;  
        for(i = 1; i <= n; ++i)  
            scanf("%d",&s[i]);  
        a[1] = s[1] % m;  
        b[1] = (2 * s[1] - 1) % m;  
        for(i = 2; i <= n; ++i)  
        {  
            a[i] = ( (a[i-1] << 1) + s[i]) % m;  
            if(s[i] == 1)  
                b[i] = a[i];  
            else  
                b[i] = (b[i-1] + (a[i-1]<<1) + (s[i]<<1)) % m;///a方法移两次便正向了  
        }  
        printf("%d\n",b[n]);  
    }  
    return 0;  
}  

