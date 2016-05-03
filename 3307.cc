#include <iostream>
#include <algorithm>

using namespace std;

__int64 b=1;
__int64 a[1146075];
__int64 f[4][60];
void init()
{

    int i,j,k,l,cnt=0;

    b=1;
    for(i=1;i<=18;i++) b*=10;
    f[0][0]=f[1][0]=f[2][0]=f[3][0]=1;
    for(i=1;i<=59;i++) f[0][i]=f[0][i-1]*2;
    for(i=1;i<=37;i++) f[1][i]=f[1][i-1]*3;
    for(i=1;i<=25;i++) f[2][i]=f[2][i-1]*5;
    for(i=1;i<=21;i++) f[3][i]=f[3][i-1]*7;

    __int64 tmp;
    for(i=0;i<=59;i++){
        tmp=f[0][i];
        for(j=0;j<=37;j++){
            if(tmp*f[1][j]>=b) break;
            else tmp*=f[1][j];
            for(k=0;k<=25;k++){
                if(tmp*f[2][k]>=b) break;
                else tmp*=f[2][k];
                for(l=0;l<=21;l++){
                    if(tmp*f[3][l]>=b) break;
                    else a[cnt++]=tmp*f[3][l];
                }
                tmp/=f[2][k];
            }
            tmp/=f[1][j];
        }
        tmp/=f[0][i];
    }
    sort(a,a+cnt);
}

int main()
{
    init();
    int t,i;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&i);
        printf("%I64d\n",a[i-1]);
    }
    return 1;
}




