#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 50001;

int  heap[MAXN];

int main()
{
    int n;
    int len,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        heap[1]=1;
        len=1;
        for(i=2;i<=n;i++)
        {
            j=len;
            while(j>1)
            {
                heap[j]=heap[j/2];
                j/=2;
            }
            heap[1]=i;
            heap[++len]=1;
        }
        for(i=1;i<=n;i++)
        {
            if(i!=1) printf(" ");
            printf("%d",heap[i]);
        }
        printf("\n");
    }
    return 0;
}



