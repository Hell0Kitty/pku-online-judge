#include <stdio.h>
#include <memory.h>
#include <iostream>
using namespace std;
#define maxBound 20005 * 6

struct {
  int marble[7];
  bool reachable;
} status[maxBound];
int marble[7];
int marbleValueSum = 0;
int caseNO = 1;

void answer() {
  printf("Collection #%d:\n", caseNO++);
  if (marbleValueSum % 2 != 0) {
    printf("Can't be divided.\n");
  } else {
    memset(status, 0, sizeof(status));
    status[0].reachable = true;
    for (int i = 1; i <= 6; i++) {
      status[0].marble[i] = marble[i];
    }
    //  cout<<"Incoming here"<<endl;
    for (int i = 0; i <= marbleValueSum / 2; i++) {
      if (status[i].reachable) {
        for (int j = 1; j <= 6; j++) {
          if (status[i].marble[j] > 0) {
            status[i + j].reachable = true;
            for (int k = 1; k <= 6; k++) {
              status[i + j].marble[k] = status[i].marble[k];
            }
            status[i + j].marble[j]--;
          }
        }
      }
    }
    if (status[marbleValueSum / 2].reachable) {
      printf("Can be divided.\n");
    } else {
      printf("Can't be divided.\n");
    }
  }
  printf("\n");
}

int main() {
  while (1) {
    int i;
    int shouldEnd = true;
    marbleValueSum = 0;
    for (i = 1; i <= 6; i++) {
      scanf("%d", marble + i);
      marbleValueSum += marble[i] * i;
      if (marble[i] != 0) {
        shouldEnd = false;
      }
    }
    if (shouldEnd) {
      return 0;
    }
    answer();
  }

  return 0;
}
