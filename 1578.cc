#include <iostream>
#include <string>
using namespace std;

const int maxlength = 2001, maxl = 100, maxc = 30;

string header, nextheader, word[maxl][maxc];
int lnum, cnum, csize[maxc];

void init() {
  string st;
  int l = 0, c = 0, i;

  memset(csize, 0, sizeof(csize));
  cnum = header.length();
  while (1) {
    getline(cin, nextheader);
    if (nextheader[0] == '>' || nextheader[0] == '<' || nextheader[0] == '=' ||
        nextheader[0] == '*')
      break;
    for (i = 0; i < cnum - 1; i++) {
      word[l][i] = nextheader.substr(0, nextheader.find("&"));
      nextheader.erase(0, nextheader.find("&") + 1);
      if (int(word[l][i].length()) > csize[i]) csize[i] = word[l][i].length();
    }
    word[l][cnum - 1] = nextheader;
    if (int(word[l][cnum - 1].length()) > csize[cnum - 1])
      csize[cnum - 1] = word[l][cnum - 1].length();
    l++;
  }
  lnum = l;
}

void printl(int w, string st) {
  int i, l = w - st.length();

  cout << st;
  for (i = 0; i < l; i++) cout << " ";
}

void printc(int w, string st) {
  int i, l = w - st.length();

  for (i = 0; i < l / 2; i++) cout << " ";
  cout << st;
  for (i = 0; i < l / 2; i++) cout << " ";
  if (l % 2 != 0) cout << " ";
}

void printr(int w, string st) {
  int i, l = w - st.length();

  for (i = 0; i < l; i++) cout << " ";
  cout << st;
}

void printword(int i, string st) {
  switch (header[i]) {
    case '<':
      printl(csize[i], st);
      break;
    case '=':
      printc(csize[i], st);
      break;
    case '>':
      printr(csize[i], st);
      break;
  }
}

void print() {
  int i, j;

  // first line
  cout << "@-";
  for (i = 0; i < cnum - 1; i++) {
    for (j = 0; j < csize[i]; j++) cout << "-";
    cout << "---";
  }
  for (j = 0; j < csize[cnum - 1]; j++) cout << "-";
  cout << "-@";
  cout << endl;

  // second line
  cout << "|";
  for (i = 0; i < cnum; i++) {
    cout << " ";
    printword(i, word[0][i]);
    cout << " |";
  }
  cout << endl;

  // third line
  cout << "|-";
  for (i = 0; i < cnum - 1; i++) {
    for (j = 0; j < csize[i]; j++) cout << "-";
    cout << "-+-";
  }
  for (j = 0; j < csize[cnum - 1]; j++) cout << "-";
  cout << "-|";
  cout << endl;

  // other lines
  for (j = 1; j < lnum; j++) {
    cout << "|";
    for (i = 0; i < cnum; i++) {
      cout << " ";
      printword(i, word[j][i]);
      cout << " |";
    }
    cout << endl;
  }

  // last line
  cout << "@-";
  for (i = 0; i < cnum - 1; i++) {
    for (j = 0; j < csize[i]; j++) cout << "-";
    cout << "---";
  }
  for (j = 0; j < csize[cnum - 1]; j++) cout << "-";
  cout << "-@";
  cout << endl;
}

int main() {
  getline(cin, header);
  while (header[0] != '*') {
    init();
    print();
    header = nextheader;
  }
  return 0;
}
