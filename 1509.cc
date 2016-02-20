#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    for(scanf("%d",&T),getchar();T;T--)
    {
        char ss[10005];
        gets(ss);
        string st=ss,ans=ss,tp;
        int len=st.size(),id=1;
        for(int i=1;i<len;i++)
        {
            tp=st.substr(i,len-i)+st.substr(0,i);
            if(tp<ans)
            {
                ans=tp;
                id=i+1;
            }
        }
        printf("%d\n",id);
    }
    return 0;
}



