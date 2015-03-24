#include <stdarg.h>
#include <stdio.h>

float cardNumber[300];
void init() {
  int i;
  cardNumber[0] = 0.0;
  for (i = 1; i < 300; i++) {
    cardNumber[i] += cardNumber[i - 1] + 1.0 / (float)(i + 1);
  }
}

int binarySearch(float input) {
  /*int low = 0, high = 300-1;int mid = 0;
  while(low < high){
      mid = (low + high) /2;
      if (input > cardNumber[mid])
      {
          low = mid;
      }else if ( input < cardNumber[mid])
      {
          high = mid;
      }
  }
  //printf("The mid is %d", mid);*/
  int i;
  for (i = 0; i < 300; i++) {
    if (cardNumber[i] > input) return i;
  }
  // return mid;
}

int main() {
  float input;
  init();
  scanf("%f", &input);
  while (input != 0) {
    printf("%d card(s)\n", binarySearch(input));

    scanf("%f", &input);
  }
  return 0;
}
