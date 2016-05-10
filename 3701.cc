#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <assert.h>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <time.h>
using namespace std;

const int maxn = 107;
const int List[9][12] = { {45, 46, 47, 39, 27, 15, 8, 7, 6, 11, 23, 35},
 {48, 49, 50, 40, 28, 16, 5, 4, 3, 10, 22, 34},
 {51, 52, 53, 41, 29, 17, 2, 1, 0, 9, 21, 33},
 {44, 32, 20, 0, 3, 6, 12, 24, 36, 45, 48, 51},
 {43, 31, 19, 1, 4, 7, 13, 25, 37, 46, 49, 52},
 {42, 30, 18, 2, 5, 8, 14, 26, 38, 47, 50, 53},
 {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
 {21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32},
 {33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44} };
const int Rota[6][8] = { {12, 24, 36, 37, 38, 26, 14, 13},
 {18, 19, 20, 32, 44, 43, 42, 30},
 {11, 23, 35, 34, 33, 21, 9, 10},
 {15, 27, 39, 40, 41, 29, 17, 16},
 {0, 3, 6, 7, 8, 5, 2, 1},
 {45, 46, 47, 50, 53, 52, 51, 48} };
const int center[6] = {4, 22, 25, 28, 31, 49};
const int edg[12][2] = {10, 3, 13, 7, 5, 16, 1, 19, 46, 37, 48, 34, 50, 40, 52, 43, 23, 24, 26, 27, 29, 30, 32, 21};
const int vertex[8][3] = {0, 9, 20, 11, 12, 6, 8, 14, 15, 2, 17, 18, 45, 35, 36, 38, 39, 47, 53, 41, 42, 51, 33, 44};

int a[maxn];
char s[maxn];
vector<int> ans;

void output()
{
 puts("=======================================");
 int num = 0;
 for (int i = 0; i < 9; i++)
 {
 int L = 0, R = 11;
 if (i < 3 || i > 5) L = 3, R = 5;
 for (int j = 0; j < L; j++) putchar(' ');
 for (int j = L; j <= R; j++) printf("%d", a[num++]);
 puts("");
 }
 puts("=======================================");
}

void turn(int order)
{
 ans.push_back(order);
 order--;
 int b[maxn];
 for (int i = 0; i < 54; i++) b[i] = a[i];
 int x = order/2, d = (order%2)?-3:3;
 for (int i = 0; i < 12; i++)
 a[List[x][i]] = b[List[x][(i+d+12)%12]];
 if (order%6 < 2 || order%6 > 3)
 {
 int x = (order/6)*2+(order%6)/4, d = (order%2)? -2:2;
 for (int i = 0; i < 8; i++)
 a[Rota[x][i]] = b[Rota[x][(i+d+8)%8]];
 }
}

bool BUG()
{
 int c = 0, e = 0, v = 0;
 for (int i = 0; i < 6; i++) c += a[center[i]];
 for (int i = 0; i < 12; i++) e += a[edg[i][0]] || a[edg[i][1]];
 for (int i = 0; i < 8; i++) v += a[vertex[i][0]] || a[vertex[i][1]] || a[vertex[i][2]];
 return c < 1 || e < 4 || v < 4;
}

void MoveCenter()
{
 if (a[49]) return;
 if (a[25]) turn(10);
 else
 if (a[4]) turn(10), turn(10);
 else
 if (a[31]) turn(9);
 else
 if (a[22]) turn(4);
 else turn(3);
}

void MoveEdge()
{
 for (int run = 0; run < 4; run++)
 {
 if (a[46] == 0)
 {
 if (a[43] && !a[52]) turn(6);
 if (a[29]) turn(15);
 if (a[21]) turn(16);
 if (a[3] || a[10]) turn(14);
 if (a[5] || a[16]) turn(13);
 if (a[1] || a[19]) turn(13), turn(13);
 if (a[26] || a[30]) turn(15);
 if (a[24] || a[32]) turn(16);
 if (a[13]) turn(11), turn(14), turn(12);
 if (a[23]) turn(2);
 if (a[27]) turn(1);
 if (a[7]) turn(1), turn(1); 
 if (a[40] && !a[50]) turn(11), turn(1), turn(12);
 if (a[34] && !a[48]) turn(7), turn(2), turn(8);
 }
 turn(17);
 }
}

void MoveVertex()
{
 for (int run = 0; run < 4; run++)
 {
 if (a[45] == 0)
 {
 if (a[35] || a[36]) turn(7), turn(13), turn(8);
 if ((a[38] || a[39]) && !a[47]) turn(11), turn(13), turn(12);
 if ((a[33] || a[44]) && !a[51]) turn(8), turn(14), turn(7);
 if ((a[44] || a[41]) && !a[53]) turn(12), turn(14), turn(11);
 if (a[8]) turn(13);
 if (a[0]) turn(14);
 if (a[2]) turn(13), turn(13);
 if (a[6]) turn(7), turn(13), turn(8); //6->17
 if (a[18] || a[11]) turn(13);
 if (a[12] || a[17]) turn(14);
 if (a[9] || a[14]) turn(13), turn(13);
 if (a[15]) turn(7), turn(13), turn(8);
 if (a[20]) turn(1), turn(14), turn(2);
 }
 turn(17);
 }
}

int main()
{
 int num = 0;
 for (int i = 0; i < 9; i++) 
 {
 scanf("%s", s);
 int m = strlen(s);
 for (int j = 0; j < m; j++) 
 if (s[j] == '0' || s[j] == '1') a[num++] = s[j]-'0';
 }
 if (BUG())
 {
 puts("no");
 return 0;
 }
 ans.clear();
 MoveCenter();
 MoveEdge();
 MoveVertex();
 puts("yes");
 printf("%d\n", ans.size());
 for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
 return 0;
}


