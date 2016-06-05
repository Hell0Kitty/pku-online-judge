#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    int total = 0;
    string a1,a2;
    scanf("%d",&N);
    while(N--)
    {
        char tem[300];
        scanf("%s",tem);
        if(total)
        {
            a2 = tem;
            int k = 0;
            for(unsigned i = 0;i < a1.length() && i < a2.length();++i)
            {
                if(a1[i] == a2[i])k++;
                else break;
            }
            total = total + a2.length() - k + 1;
            a1 = a2;
        }
        else
        {
            a1 = tem;
            total = a1.length();
        }
    }
    printf("%d\n",total);
    return 0;
}



