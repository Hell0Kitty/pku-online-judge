#include <iostream>
#include<cstdio>
using namespace std;
int a[10001];
int main()
{
    int n,j=1,i=1,temp=1,sum=0;

    for(int i = 1;i<=10000;)
    {
        int k = j;
        while(k>0)
        {
            sum += temp;
            a[i++] = sum;
            k--;
        }
        temp++;
        j++;
    }
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        printf("%d %d\n",n,a[n]);
    }
    return 0;
}



