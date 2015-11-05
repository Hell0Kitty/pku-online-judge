#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(void) {
  char ch;
  char str[] = {"`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"};
  char text[10000];
  int len = strlen(str);
  while (gets(text)) {
    for (int k = 0; k < strlen(text); k++) {
      if (text[k] == ' ') cout << text[k];
      for (int i = 0; i < len; i++) {
        if (text[k] == str[i]) cout << str[i - 1];
      }
    }
    cout << endl;
  }
  return 0;
}