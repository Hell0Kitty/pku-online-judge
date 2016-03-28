#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>

using std::priority_queue;
using std::vector;
using std::swap;
using std::stack;
using std::sort;
using std::max;
using std::min;
using std::pair;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::set;
using std::queue;
using std::string;
using std::istringstream;
using std::make_pair;
using std::greater;

int arr[3];

int main() {
  int T;
  int n_case = 0;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", arr);
    while (getchar() != ':')
      ;

    scanf("%d", arr + 1);
    while (getchar() != ':')
      ;

    scanf("%d", arr + 2);

    printf("%d ", ++n_case);
    for (int i = 5; i >= 0; --i)
      for (int j = 0; j < 3; ++j) printf("%c", ((1 << i) & arr[j]) ? '1' : '0');
    printf(" ");
    for (int i = 0; i < 3; ++i)
      for (int j = 5; j >= 0; --j)
        printf("%c", ((1 << j) & arr[i]) ? '1' : '0');
    printf("\n");
  }
  return 0;
}
