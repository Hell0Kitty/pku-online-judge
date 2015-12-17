#include <stdio.h>
#include <memory.h>
//该函数求一维数组的最大子段和
inline int getMax(int buf[100],int n)
{
    int temp[101],max=n*(-127);
    memset(temp,0,4*(n+1));

    for(int i=1;i<=n;i++)
    {
        temp[i] = (temp[i-1]>0?temp[i-1]:0)+buf[i];
        if(max<temp[i])
            max=temp[i];
    }
    return max;
}

int main(void)
{
    int n,num[101][101],i,j,k,max,temp[101];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&num[i][j]);
    max = -127*n*n;
    for(i=1;i<=n;i++)
    {
        memset(temp,0,4*(n+1));
        for(j=i;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                temp[k] += num[j][k];

            }
            //二维转化为一维
            int this_max = getMax(temp,n);
            if(this_max>max)
                max = this_max;
        }
    }

    printf("%d\n",max);
    return 1;

}
