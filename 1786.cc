#include <iostream>
#include <string>
#include <algorithm>
#define F(i, a, b) for (int i = a; i <= b; i++)
using namespace std;
char numchr[15] = {'2', '3', '4', '5', '6', '7', '8',
                   '9', 'T', 'J', 'Q', 'K', 'A'},
     colorchr[4] = {'S', 'W', 'N', 'E'}, color2chr[128];
string title[4] = {"South player:", "West player:", "North player:",
                   "East player:"};
int chr2num[128], chr2color[128], chr2dir[128];

struct Card {
  int n, c;
  Card() { n = 0; }
  Card(int a, int b) { c = a, n = b; }
  bool operator<(const Card& b) const {
    if (c == b.c) return n < b.n;
    return (c < b.c);
  }
};
Card play[4][15];
void init() {
  chr2num[(int)'2'] = 0;
  chr2num[(int)'3'] = 1;
  chr2num[(int)'4'] = 2;
  chr2num[(int)'5'] = 3;
  chr2num[(int)'6'] = 4;
  chr2num[(int)'7'] = 5;
  chr2num[(int)'8'] = 6;
  chr2num[(int)'9'] = 7;
  chr2num[(int)'T'] = 8;
  chr2num[(int)'J'] = 9;
  chr2num[(int)'Q'] = 10;
  chr2num[(int)'K'] = 11;
  chr2num[(int)'A'] = 12;
  chr2color[(int)'C'] = 0;
  chr2color[(int)'D'] = 1;
  chr2color[(int)'S'] = 2;
  chr2color[(int)'H'] = 3;
  chr2dir[(int)'S'] = 0;
  chr2dir[(int)'W'] = 1;
  chr2dir[(int)'N'] = 2;
  chr2dir[(int)'E'] = 3;
  color2chr[0] = 'C';
  color2chr[1] = 'D';
  color2chr[2] = 'S';
  color2chr[3] = 'H';
}
int main() {
  char startch, c, n;
  int now;
  init();
  while (scanf("%c\n", &startch) && startch != '#') {
    F(i, 0, 3)
    play[i][0].n = 0;
    now = chr2dir[startch];
    now = (now + 1) % 4;
    F(i, 0, 1) {
      F(j, 1, 26) {
        scanf("%c%c", &c, &n);
        int len = ++play[now][0].n;
        play[now][len] = Card(chr2color[c], chr2num[n]);
        now = (now + 1) % 4;
      }
      scanf("\n");
    }
    F(i, 0, 3) {
      sort(&play[i][1], &play[i][14]);
      printf("%s\n", title[i].c_str());
      printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
      F(j, 1, 13)
      printf("|%c %c", numchr[play[i][j].n], numchr[play[i][j].n]);
      printf("|\n");
      F(j, 1, 13)
      printf("| %c ", color2chr[play[i][j].c]);
      printf("|\n");
      F(j, 1, 13)
      printf("|%c %c", numchr[play[i][j].n], numchr[play[i][j].n]);
      printf("|\n");
      printf("+---+---+---+---+---+---+---+---+---+---+---+---+---+\n");
    }
    printf("\n");
  }
  return 0;
}
