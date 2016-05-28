#include <stdio.h>
struct po {
  int x, y;
} p[70000];
int main() {
  int t, a, b, q, n1, n2, x, y, num, flag, bu, tem, diyici, biaoji1, biaoji2;
  scanf("%d", &t);
  int cas = 1;
  while (t--) {
    printf("Caso %d\n", cas++);
    scanf("%d%d", &a, &b);
    scanf("%d", &q);
    x = 0, y = 0;
    num = -1;
    flag = 0;
    bu = 1;  //两次 步数增加一
    tem = 1;
    diyici = 1;
    while (num < 70000) {
      if (x * a + b != y)  //不在线上;
      {
        num++;
        p[num].x = x;
        p[num].y = y;
      }

      if (flag == 0) {
        x--;
      } else if (flag == 1) {
        y++;
      } else if (flag == 2) {
        x++;
      } else if (flag == 3) {
        y--;
      }
      bu--;
      if (bu == 0 && diyici == 1) {
        bu = tem;
        flag++;
        flag %= 4;
        ;
        diyici = 2;
      } else if (bu == 0 && diyici == 2) {
        bu = ++tem;
        flag++;
        flag %= 4;
        ;
        diyici = 1;
      }
    }
    while (q--) {
      scanf("%d%d", &n1, &n2);
      biaoji1 = a * p[n1].x + b - p[n1].y;
      biaoji2 = a * p[n2].x + b - p[n2].y;
      if (biaoji1 * biaoji2 < 0)
        puts("Lados opostos da fronteira");
      else
        puts("Mesmo lado da fronteira");
    }
  }
  return 0;
}
