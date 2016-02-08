#include<cstdio>
#include<stack>
using namespace std;

int main()
{
    stack<int> s;
    __int64 sum;
    int n,h,t;
    while(~scanf("%d",&n))
    {
        sum=0;
        scanf("%d",&h);
        s.push(h);
        for(int i=1;i<n;++i)
        {
            scanf("%d",&t);
            while(!s.empty()&&t>=s.top())
                s.pop();
            sum+=s.size();
            s.push(t);          
        }
        printf("%lld\n",sum);
        while(!s.empty())       
            s.pop();
    }
    return 0;
}



