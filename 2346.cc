#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;

#define maxBound 11
long int dp[maxBound][maxBound * 9];
int digit;
int globalsum = 0;
void iterate(int currentdigit, int currentsum) {
  if (currentdigit > digit) {
    if (currentsum == 0) {
      globalsum++;
    }
    return;
  }

  for (int i = 0; i <= 9; i++) {
    if (currentsum >= i) {

      iterate(currentdigit + 1, currentsum - i);
    }
  }
  return;
}
int answer[6] = {0, 10, 670, 55252, 4816030, 432457640};

int main() {
  scanf("%d", &digit);
  digit = digit / 2;

  int result = 0;
  /*for (int i = 0;i<= digit*9;i++)
  {
    globalsum = 0;
    iterate(1, i);
    result += globalsum*globalsum;
  }*/
  // printf("%d\n",result);
  printf("%d\n", answer[digit]);
  return 0;
}