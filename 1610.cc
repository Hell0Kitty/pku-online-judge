#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAXN = 600;

 class CNODE
 {
 public:
     int X, Y, E;
     int flag, num;
 public:
     CNODE() {}
     CNODE(int _x, int _y, int _e, int _f, int _n)
         : X(_x), Y(_y), E(_e), flag(_f), num(_n) {}
 }node[MAXN * MAXN * 2];

 int bin_map[MAXN][MAXN];

 class CQUADTREE
 {
 public:
 public:
     CQUADTREE() {}
     void Build(int r, int x, int y, int e)
     {
         if(e > 1)
         {
             Build(4 * r - 2, x, y, e / 2);
             Build(4 * r - 1, x, y + e / 2, e / 2);
             Build(4 * r, x + e / 2, y, e / 2);
             Build(4 * r + 1, x + e / 2, y + e / 2, e / 2);
             int i, judge = 0;
             for(i = 4 * r - 2; i < 4 * r + 2; i++)
             {
                 if(node[i].flag)  break;
                 judge |= (1 << node[i].num);
                 if(judge == 3)  break;
             }
             if(i < 4 * r + 2)  node[r] = CNODE(x, y, e, 1, -1);
             else  node[r] = CNODE(x, y, e, 0, bin_map[x][y]);
         }
         else    //叶子
         {
             node[r] = CNODE(x, y, e, 0, bin_map[x][y]);
         }
     }
 };

 void go(int n)
 {
     CQUADTREE tree;
     tree.Build(1, 0, 0, n);
     vector<int> Q;
     string ans = "";
     Q.push_back(1);
     for(int i = 0; i < Q.size(); i++)
     {
         if(node[Q[i]].flag)
         {
             ans += "1";
             for(int j = 4 * Q[i] - 2; j < 4 * Q[i] + 2; j++)
                 Q.push_back(j);
         }
         else
         {
             ans += "0";
             if(node[Q[i]].num)  ans += "1";
             else  ans += "0";
         }
     }
     //cout << ans << endl;
     while(ans.length() % 4)  ans = "0" + ans;
     for(int i = 0; i < ans.length(); i += 4)
     {
         int tmp = 8 * (ans[i] - '0') +
             4 * (ans[i + 1] - '0') +
             2 * (ans[i + 2] - '0') +
             1 * (ans[i + 3] - '0');
         printf("%X", tmp);
     }
     printf("\n");
 }

 int main()
 {
     int T;
     scanf("%d", &T);
     while(T--)
     {
         int n;
         scanf("%d", &n);
         for(int i = 0; i < n; i++)
             for(int j = 0; j < n; j++)
                 scanf("%d", &bin_map[i][j]);
         go(n);
     }
 }



