#include <iostream>

using namespace std;

struct POINT {
  int x;
  int y;
};

//记录弹板信息的结构体

struct BUMPER {
  int nValue;
  int nCost;
};

int main(void) {
  //用二维数组记录所有弹板的信息，不存在弹板的位置为空指针

  BUMPER *pTable[52][52] = {0}, *pBumper;

  //按照题目指定的方向编号，设定移动偏移量

  POINT ptSize, ptPos, aDir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  int nWCost, nTotal = 0, nValue, nLife, nDir;

  //输入桌面尺寸、墙的消耗、弹板数量

  for (cin >> ptSize.x >> ptSize.y >> nWCost >> nTotal; nTotal-- > 0;) {
    //循环读入每个弹板的坐标、分值以及消耗，并存入数组

    cin >> ptPos.x >> ptPos.y;

    pBumper = new BUMPER;

    cin >> pBumper->nValue >> pBumper->nCost;

    //弹板的坐标是以1起始的，需适配以0起始的数组地址

    pTable[ptPos.x - 1][ptPos.y - 1] = pBumper;
  }

  //桌面尺寸也需适配以0起始的数组地址

  ptSize.x -= 1, ptSize.y -= 1;

  //循环读入每个球的起始坐标，起始方向和生命值

  for (nTotal = 0; cin >> ptPos.x >> ptPos.y >> nDir >> nLife;) {
    //使坐标适配数组地址

    --ptPos.x, --ptPos.y;

    //循环移动小球，直到生命结束

    for (nValue = 0; --nLife > 0;) {
      //建立新坐标变量存储移动后的值，以便移动失败时回退

      POINT ptNew = {ptPos.x + aDir[nDir].x, ptPos.y + aDir[nDir].y};

      //撞墙

      if (ptNew.x == ptSize.x || ptNew.y == ptSize.y ||

          ptNew.x < 1 || ptNew.y < 1) {
        //生命值减去墙的消耗并转向

        nLife -= nWCost;

        nDir = (nDir + 3) % 4;

        continue;
      }

      //碰到弹板

      if ((pBumper = pTable[ptNew.x][ptNew.y]) != 0) {
        //分值加上弹板的分值，生命值减去消耗并转向

        nValue += pBumper->nValue;

        nLife -= pBumper->nCost;

        nDir = (nDir + 3) % 4;

        continue;
      }

      //移动到空白格子

      ptPos = ptNew;
    }

    //总分累加这一次的分值并输出当前分值

    nTotal += nValue;

    cout << nValue << endl;
  }

  //输出总分，程序结束

  cout << nTotal << endl;

  return 0;
}
