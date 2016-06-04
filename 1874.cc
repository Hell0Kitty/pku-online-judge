#include <iostream>
#include <algorithm>
#define MAX_B 20
#define MAX_W 50
using namespace std;
struct pile
{
    int num;
    int choice[MAX_B + 5]; 
}piles[MAX_W + 5];
int pNum, maxProFit;
int res[MAX_B * MAX_W + 5], resNum;
int temp[MAX_B * MAX_W + 5];
bool v[MAX_W * MAX_B + 5];
bool compare(const int &v1, const int &v2)
{
    return v1 <= v2;
}
int main()
{
    int p, i, j, seq = 0;
    while(scanf("%d", &pNum) && pNum != 0)
    {
        seq++;
        maxProFit = 0;
        memset(piles, 0, sizeof(piles));
        resNum = 1; res[resNum] = 0;
        v[0] = true;
        int pPos = 0;
        for(p = 1; p <= pNum; p++)
        {
            pPos++;
            int bNum, price, maxPro = 0, curPro = 0;
            piles[p].num = 1; piles[p].choice[1] = 0;
            scanf("%d", &bNum);
            for(i = 1; i <= bNum; i++)
            {
                scanf("%d", &price);
                curPro += 10 - price;
                if(curPro > maxPro)
                {
                    piles[pPos].num = 1;
                    piles[pPos].choice[piles[pPos].num] = i;
                    maxPro = curPro;
                }
                else if(curPro == maxPro)
                {
                    piles[pPos].num++;
                    piles[pPos].choice[piles[pPos].num] = i;
                }
            }
            maxProFit += maxPro;
            int newSize = 0;
            memset(v, 0, sizeof(v));
            for(i = 1; i <= piles[p].num; i++)
            {
                for(j = 1; j <= resNum; j++)
                {
                    int newVal = piles[p].choice[i] + res[j];
                    if(!v[newVal])
                    {
                        v[newVal] = true;
                        temp[++newSize] = newVal;
                    }

                }
            }
            resNum = newSize;
            for(i = 1; i <= newSize; i++) res[i] = temp[i];
        }
        sort(&res[1], &res[1] + resNum, compare);
        if(resNum > 10) resNum = 10;
        printf("Workyards %d\n", seq);
        printf("Maximum profit is %d.\n", maxProFit);
        printf("Number of pruls to buy:");
        for(i = 1; i <= resNum; i++) printf(" %d", res[i]);
        printf("\n\n");
    }
    return 0;
}



