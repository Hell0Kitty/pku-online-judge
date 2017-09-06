#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long LL;
const int N = 25;

int B1[N],B2[N];
LL a[N], b[N], C[N][N];

void init(){//预处理伯努利系数
    B1[0] = 1; B2[0] = 1;
    B1[1] = -1;B2[1] = 2;
    B1[2] = 1; B2[2] = 6;
    B1[3] = 0; B2[3] = 0;
    B1[4] = -1; B2[4] = 30;
    B1[5] = 0; B2[5] = 0;
    B1[6] = 1; B2[6] = 42;
    B1[7] = 0; B2[7] = 0;
    B1[8] = -1; B2[8] = 30;
    B1[9] = 0; B2[9] = 0;
    B1[10] = 5,B2[10] = 66;
    B1[11] = 0; B2[11] = 0;
    B1[12] = -691; B2[12] = 2730;
    B1[13] = 0; B2[13] = 0;
    B1[14] = 7; B2[14] = 6;
    B1[15] = 0; B2[15] = 0;
    B1[16] = -3617; B2[16] = 510;
    B1[17] = 0; B2[17] = 0;
    B1[18] = 43867; B2[18] = 798;
    B1[19] = 0; B2[19] = 0;
    B1[20] = -174611; B2[20] = 330;

    // 组合数
    for(int i = 0; i <= 21; i++)
        C[i][0] = C[i][i] = 1;
    for(int i = 1; i <= 21; i++)
    {
        for(int j = 1; j < i; j++)
            C[i][j] = C[i-1][j]+C[i-1][j-1];
    }
}
LL gcd( LL a, LL b ){ return b==0?a:gcd(b,a%b);}
LL lcm( LL a, LL b ){ return (a/gcd(a,b))*b; }

int main(){
    init();
    int k;
    while( scanf("%d", &k) != EOF)
    {
        memset( a, 0, sizeof(a));
        memset( b, 0, sizeof(b));

        LL t1[N], t2[N];
        for(int r = 1; r <= k+1; r++)
        {
            memset( t1, 0, sizeof(t1));
            memset( t2, 0, sizeof(t2));    
            for(int i = 0; i <= r; i++)
            {
                t1[i] = B1[k+1-r]*C[k+1][r]*C[r][i];
                t2[i] = B2[k+1-r]; 
            }    
            for(int i = 0; i <= r; i++)
            {
                if( t2[i] ){ 
                    if( b[i] == 0 ){
                        a[i] = t1[i]; b[i] = t2[i];    
                    }    
                    else{//通分
                        LL z = lcm( b[i], t2[i] );
                        LL x = z/b[i], y = z/t2[i];
                        a[i] = a[i]*x + t1[i]*y;
                        b[i] = z;
                    }
                }    
            }
        }
        //获取所有分母最小公倍数 z    
        LL z = 1, p = 1;
        for(int i = 0; i <= k+1; i++)
            if( b[i] )    z = lcm( z, b[i] );
        for(int i = 0; i <= k+1; i++)
            if( b[i] ){ //统一分母z
                a[i] *= (z/b[i]);
                p = a[i]; b[i] = z;    
            }        
        z *= (k+1);    
        //获取分子分母最大公约数 p    
        for(int i = 0; i <= k+1; i++)
            if( b[i] ) p = gcd( p, a[i] );    
        p = gcd( p, z );        
        //简化形式    
        for(int i = 0; i <= k+1; i++)
            if( b[i] ) a[i] /= p;

        z /= p;    
        int f = ( z < 0 ) ? -1 : 1;

        printf("%lld", f*z);
        for(int i = k+1; i >= 0; i-- )
            printf(" %lld",f*a[i]);
        puts("");
    }
    return 0;
}


