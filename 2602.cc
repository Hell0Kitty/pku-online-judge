#include <iostream>
#include <string>
using namespace std;

const int size = 1000000;  //大数位数上限
int n;                     //大数位数

int a[size + 1];
int b[size + 1];

void add(char *A, char *B, char *ans) {
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  int pa = 0, pb = 0;

  int lena = strlen(A);
  int lenb = strlen(B);

  /*倒序*/

  for (int i = lena - 1; i >= 0; i--) a[pa++] = A[i] - '0';
  for (int j = lenb - 1; j >= 0; j--) b[pb++] = B[j] - '0';

  int len = lena > lenb ? lena : lenb;
  char *c = new char[len + 1];  //倒序的ans

  int w = 0;  //低位到高位的进位
  for (int k = 0; k < len; k++) {
    int temp = a[k] + b[k] + w;
    c[k] = temp % 10 + '0';
    w = temp / 10;
  }
  len--;

  for (w = 0; len >= 0; len--)  // w和len均作指针使用，已无意义
    ans[w++] = c[len];
  ans[w] = '\0';

  delete c;
  return;
}

char A[size + 1];
char B[size + 1];
char ans[size + 1];

int main(int i) {
  while (cin >> n) {
    getchar();
    for (i = 0; i < n; i++) {
      A[i] = getchar();
      getchar();  //空格
      B[i] = getchar();
      getchar();  //回车
    }
    A[i] = B[i] = '\0';

    add(A, B, ans);
    cout << ans << endl;
  }
  return 0;
}