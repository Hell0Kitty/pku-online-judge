
/****************************************************************************************************
Source Code
Problem: 1185  User: new_star
Memory: 316K  Time: 235MS
Language: G++  Result: Accepted
****************************************************************************************************/
// Source Code
#include <cstdio>
char map[100][11];
int vipmap[100], row, column, s[61], sNum, c[61], f[2][61][61], roll, connons;
int main(void) {  //读图并压缩成相应的状态图
  scanf("%d%d", &row, &column);
  for (int i = 0; i < row; i++) scanf("%s", &map[i]);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++)
      if (map[i][j] == 'H') vipmap[i] += (1 << j);

  //合法状态及其总数,和相应状态的炮兵数
  sNum = 0;
  for (int k = 0; k < (1 << column); k++) {
    int m = k;
    if (((m << 1) & k) || ((m << 2) & k)) continue;
    c[sNum] = m % 2;
    while (m = (m >> 1)) c[sNum] += m % 2;
    s[sNum++] = k;
  }

  //用滚动数组依次求出每行的最优解
  // roll为当前行,(roll+1)%2为前一行也即下一行
  roll = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < sNum; j++) {
      if ((s[j] & vipmap[i])) continue;  //状态j是否与i行地图冲突
      if (i == 0)
        f[roll][j][0] = c[j];
      else if (i == 1) {
        for (int k = 0; k < sNum; k++) {
          if ((s[k] & vipmap[i - 1])) continue;
          if ((s[j] & s[k])) continue;
          if (f[roll][j][k] < f[(roll + 1) % 2][k][0] + c[j])
            f[roll][j][k] = f[(roll + 1) % 2][k][0] + c[j];
        }
      } else {
        for (int k = 0; k < sNum; k++) {
          if ((s[k] & vipmap[i - 1])) continue;  //状态k是否与i-1行地图冲突
          if (s[j] & s[k]) continue;             //状态j、k是否彼此冲突
          for (int l = 0; l < sNum; l++) {
            if ((s[l] & vipmap[i - 2])) continue;  //状态l是否与i-2行地图冲突
            if ((s[j] & s[l]) || (s[k] & s[l]))
              continue;  //状态j、l、k是否彼此冲突
            if (f[roll][j][k] < f[(roll + 1) % 2][k][l] + c[j])
              f[roll][j][k] = f[(roll + 1) % 2][k][l] + c[j];
          }
        }
      }
    }
    roll = (roll + 1) % 2;
  }
  roll = (roll + 1) % 2;

  //搜索最优解
  connons = 0;
  for (int j = 0; j < sNum; j++)
    for (int k = 0; k < sNum; k++)
      if (connons < f[roll][j][k]) connons = f[roll][j][k];
  printf("%d\n", connons);
  return 0;
}
