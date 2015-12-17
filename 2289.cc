

#include <string.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;
/*ifstream fin("jamie.in");*/

int m, n, w, v;
int a[1010][510];
int l[1010];
int r2l[510][1010];
int r[1010];
int l2r[1010];
bool usedr[510];
// http://acm.pku.edu.cn/JudgeOnline/showproblem?problem_id=2289
//题目大意：二分图完备匹配，每个右节点可以用k次，要求k最小
bool Input() {
  cin >> n >> m;
  if (cin.fail())
    return false;
  if (!n && !m)
    return false;
  char tmp[10000];
  char *tok;
  memset(l, 0, sizeof(l));
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    //处理一个空行不定多个数据的一种方法：
    cin.getline(tmp, 10000);
    tok = strtok(tmp, " \t");
    //拆出第一个空格前的数据
    while (tok) {
      int j = atoi(tok); //字符串转换为整型数
      a[i][l[i]++] = j;
      tok = strtok(NULL, "\t ");
      //继续拆第二个
    }
  }
  return true;
}

bool Search(int p) {
  int i, j, q, pp;
  for (i = 0; i < l[p]; i++) {
    q = a[p][i];
    if (r[q] < w) { //相当于普通匈牙利算法中的t==-1,一步能找到可增广结点
      l2r[p] = q; //相当于match数组
      r2l[q][r[q]++] =
          p; //因为每个右节点用了多次，该矩阵每次使用分别对应哪个左节点
      // r数组记录右节点被用过多少次
      return true;
    }
    if (usedr[q])
      continue;
    usedr[q] = true;             //表明右节点q是最后一次被使用
    for (j = 0; j < r[q]; j++) { //相当于search(t)；
      pp = r2l[q][j];
      if (Search(pp)) {
        r2l[q][j] = p;
        l2r[p] = q;
        return true;
      }
    }
  }
  return false;
}

bool Doing() {
  memset(r, 0, sizeof(r));
  for (v = 0; v < n; v++) {
    memset(usedr, 0, sizeof(usedr));
    if (!Search(v))
      return false;
  }
  return true;
}

int main()
{
  int x,y;
  while (Input())
  {
    x=0;y=n;
    while (x<y-1)
    {//二分加匈牙利匹配，w表示每个右节点可以用w次
      //如果能匹配上，减少w值再进行匹配。
      w=(x+y)/2;
      if (Doing()) y=w;
      else x=w;
    }
    cout<<y<<endl;
  }
  return 0;
}