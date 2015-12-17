#include <stdio.h>
#include <string.h>
const short MAX_LETTER = 21;
const short ALP_LEN = 26;
short Letter[ALP_LEN] = {-1, 1,  2, 3, -1, 1, 2, -1, -1, 2,  2, 4,  5,
                         5,  -1, 1, 2, 6,  2, 3, -1, 1,  -1, 2, -1, 2};
char word[MAX_LETTER];
char soundex[MAX_LETTER];

int main() {
  while (gets(word)) {
    short len = strlen(word);
    short j = 0;
    for (short i = 0; i < len;) {
      if (Letter[word[i++] - 'A'] != -1) {
        soundex[j++] = Letter[word[i - 1] - 'A'] + '0';
        if (i < len) {
          char a = Letter[word[i] - 'A'] + '0';
          while (i < len && a == soundex[j - 1]) {
            a = Letter[word[++i] - 'A'] + '0';
          }
        }
      }
    }
    soundex[j] = '\0';
    puts(soundex);
  }
  return 0;
}