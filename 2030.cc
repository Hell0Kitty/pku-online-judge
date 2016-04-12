#include <iostream>
#include <string>
#define MAX_N 75
using namespace std;
char graph[MAX_N + 1][MAX_N + 1];
string num[MAX_N + 1][MAX_N + 1];
int W, H;
string maxNum;

bool strcmp(const string &s1, const string &s2)
{
    int len1 = s1.length(), len2 = s2.length();
    if(len1 < len2) return false;
    else if(len1 > len2) return true;
    else return s1 >= s2;
}

void trim(string &val)
{
    while(val.length() > 0 && val[0] == '0')
        val = val.substr(1, val.length() - 1);
}
int main()
{
    int i, j;
    while(scanf("%d%d", &W, &H) && (W + H) != 0)
    {
        maxNum = "0";
        for(i = 1; i <= H; i++)
        {
            scanf("%s", &graph[i][1]);
            for(j = 1; j <= W; j++)
            {
                if(graph[i][j] >= '0' && graph[i][j] <= '9')
                {
                    num[i][j] = graph[i][j];
                    trim(num[i][j]);

                    if(j >= 2 && (i == 1 || strcmp(num[i][j - 1], num[i - 1][j])))
                        num[i][j] = num[i][j - 1] + graph[i][j];

                    if(i >= 2 && (j == 1 || strcmp(num[i - 1][j], num[i][j - 1])))
                        num[i][j] = num[i - 1][j] + graph[i][j];
                }
                else num[i][j] = "0";

                trim(num[i][j]);

                if(strcmp(num[i][j], maxNum))
                    maxNum = num[i][j];
            }
        }
        cout<<maxNum<<endl;
    }
    return 0;
}



