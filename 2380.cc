#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000010;
typedef struct _Node {
  int row;
  int col;
  int value;
} Node;
int Array[MAX];
Node Input[500010];
int rowdata[500010];
int coldata[500010];
int row, col, n;
bool cmprow(const Node& left, const Node& right) {
  return left.row < right.row;
}
void createrowmap() {
  sort(&Input[0], &Input[n], cmprow);
  int begin = 0;
  row = 0;
  for (int i = 0; i != n; ++i)
    if (Input[i].row != Input[begin].row) {
      rowdata[row] = Input[begin].row;
      row++;
      begin = i;
    }
  rowdata[row] = Input[begin].row;
  row++;
}
bool cmpcol(const Node& left, const Node& right) {
  return left.col < right.col;
}
void createcolmap() {
  sort(&Input[0], &Input[n], cmpcol);
  int begin = 0;
  col = 0;
  for (int i = 0; i != n; ++i)
    if (Input[i].col != Input[begin].col) {
      coldata[col] = Input[begin].col;
      col++;
      begin = i;
    }
  coldata[col] = Input[begin].col;
  col++;
}
int binarysearch(int* a, int left, int right, int key) {
  int middle;
  while (left <= right) {
    middle = (left + right) / 2;
    if (a[middle] == key)
      return middle;
    else if (a[middle] < key)
      left = middle + 1;
    else
      right = middle - 1;
  }
  return -1;
}
int main() {
  int place1, place2;
  scanf("%d", &n);
  for (int i = 0; i != n; ++i)
    scanf("%d%d%d", &Input[i].col, &Input[i].row, &Input[i].value);
  createrowmap();
  createcolmap();
  for (int i = 0; i != n; ++i) {
    place1 = binarysearch(rowdata, 0, row - 1, Input[i].row);
    place2 = binarysearch(coldata, 0, col - 1, Input[i].col);
    Array[place1 * col + place2] += Input[i].value;
  }
  printf("-1");
  for (int i = 0; i != col; ++i) printf(" %d", coldata[i]);
  printf("\n");
  int k = 0;
  for (int i = 0; i != row; ++i) {
    printf("%d", rowdata[i]);
    for (int j = 0; j != col; ++j) printf(" %d", Array[k++]);
    printf("\n");
  }
  return 0;
}
