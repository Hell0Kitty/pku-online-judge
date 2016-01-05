#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;

struct Info
{
     int x;
     int y;
}pos[2600];

int move[60]; 

int main()
{
    int tc, i, j, h, l, tmp, cards, ans, dis;
    cin >> tc;
    while (tc--)
    {
          cin >> h >> l;
          cards = ans = 0;

          for (i = 0; i < h; i++)
            for (j = 0; j < l; j++)
            {
                cin >> tmp;
                if (tmp != -1)
                {
                    pos[tmp].x = i;
                    pos[tmp].y = j;
                    cards++;
                }
            }
          memset(move, 0, sizeof(move));

          for (i = 1; i <= cards; i++)
          {
              ans += pos[i].x * 20;

              dis = min(abs(pos[i].y-move[pos[i].x]), l - abs(pos[i].y-move[pos[i].x]));
              ans += dis * 5;
              move[pos[i].x] = pos[i].y;
          }
          cout << ans << endl;
    }

}



