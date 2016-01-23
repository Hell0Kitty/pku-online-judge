#include <iostream>
#include <cstring>
#include &lt;cstdio&gt;
#include &lt;cstdlib&gt;
#include &lt;cmath&gt;
#include &lt;climits&gt;
#include &lt;queue&gt;
#include &lt;stack&gt;
#include &lt;map&gt;
#include &lt;vector&gt;
#include &lt;algorithm&gt;
using namespace std;

int main()
{

    int n;
    while(scanf("%d",&amp;n)!=EOF&amp;&amp;n){
        int a,b,maxSum=0,pos=0;
        for(int i=1;i&lt;=n;i++){
            scanf("%d%d",&amp;a,&amp;b);
            if(maxSum&lt;a+b){
                maxSum=a+b;
                pos=i;
            }else if(maxSum==a+b&amp;&amp;i&lt;pos){
                pos=i;
            }
        }
        if(maxSum&lt;=8)    printf("0\n");
        else    printf("%d\n",pos);
    }
    return 0;

