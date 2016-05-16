#include <iostream>
#include <string.h>
#define MAXV(a, b) ((a) >= (b) ? (a) : (b))
#define MINV(a, b) ((a) <= (b) ? (a) : (b))
#define MAX_N 100

using namespace std;

 int high, low;

bool visited, found;
 bool used[MAX_N + 5];

bool getRes(int pos, int low, int high)
 {

    //如果能进这个IF语句，则说明当前所求数是可以分解为100以内不重复的因子的
    if(low == 1)
     {

        //如果小的数的因子分解已经完成，那么说明当前进行的是较大数的因子分解，则说明这两套因子是不相交的
        if(visited)
             return true;
         else
         {

            //进行标记, visited为true说明较小数的因子分解已经完成
            found = visited = true;

            //对较大数进行因子分解
            if(getRes(1, high, high)) return true;
             visited = false;
             return false;
         }
     }

    //因子超出了范围
    else if(pos > 100)
         return false;
     else
     {

        //DFS所有的分解方案
        for(int i = pos; i <= 100; i++)
         {
             if(low % i == 0 && !used[i])
             {

                //对已经使用过的因子进行分解
                used[i] = true;

                //DFS下一步
                if(getRes(pos + 1, low / i, high))
                     return true;
                 used[i] = false;
             }
         }
         return false;
     }
 }

int main()
 {
     int temp1, temp2;
     while(cin>>temp1>>temp2)
     {
         high = MAXV(temp1, temp2);
         low = MINV(temp1, temp2);

        visited = found = false;

         memset(used, 0, sizeof(used));

         bool res = getRes(1, low, high);
         if(res) cout<<high<<endl;
         else
         {
             if(found)
                 cout<<low<<endl;
             else
                 cout<<high<<endl;
         }
      }
      return 0;
 }


