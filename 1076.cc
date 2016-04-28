#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void preWork();
void work();
void work1();
int sorttime;
int main(int argc, char *argv[]) {
  work();
  return 0;
}
int set;
int leftp[100];
int knock[100];
int game[100];
int score[100];
string show[100];
bool ifleft[100];
void work() {
  string sname;
  int n;
  int totalGame;
  while (cin >> sname) {
    int x;
    n = 0;
    bool leftpin;
    leftpin = false;
    totalGame = 0;
    while (true) {
      cin >> x;
      if (x == -1) break;
      ifleft[n] = leftpin;
      leftp[n] = x;
      if (!leftpin) {
        game[totalGame] = n;
        totalGame++;
        knock[n] = 10 - leftp[n];
      } else {
        knock[n] = leftp[n - 1] - leftp[n];
      }
      if (leftpin) {
        leftpin = false;
      } else {
        if (x == 0)
          leftpin = false;
        else
          leftpin = true;
      }
      n++;
    }
    game[totalGame] = n;
    for (int i = 0; i < totalGame; i++) {
      score[i] = 0;
      show[i] = "";
      for (int j = game[i]; j < game[i + 1]; j++) {
        score[i] += knock[j];
        if (ifleft[j]) {
          if (knock[j] + knock[j - 1] == 10)
            show[i] += '/';
          else if (knock[j] == 0)
            show[i] += '-';
          else
            show[i] += '0' + knock[j];
        } else {
          if (knock[j] == 10)
            show[i] += 'X';
          else if (knock[j] == 0)
            show[i] += '-';
          else
            show[i] += '0' + knock[j];
        }
      }
      int b;
      b = game[i];
      switch (game[i + 1] - game[i]) {
        case 1: {
          if (knock[b] == 10) {
            if (b + 2 >= n)
              score[i] = -1;
            else {
              score[i] += knock[b + 1];
              score[i] += knock[b + 2];
            }
          } else {
            score[i] = -1;
          }
        } break;
        case 2: {
          if (knock[b] + knock[b + 1] == 10) {
            if (b + 2 >= n)
              score[i] = -1;
            else {
              score[i] += knock[b + 2];
            }
          }
        } break;
      }
    }
    if (totalGame > 10) {
      for (int i = 10; i < totalGame; i++) {
        show[9] += show[i];
      }
    }
    cout << sname;
    for (int i = 0; i < 13 - sname.size(); i++) {
      cout << ' ';
    }
    for (int i = 0; i < totalGame && i < 10; i++) {
      cout << show[i];
      for (int j = 0; j < 4 - show[i].size(); j++) {
        cout << ' ';
      }
    }
    cout << endl;
    int result;
    result = 0;
    for (int i = 0; i < 13; i++) {
      cout << ' ';
    }
    for (int i = 0; i < totalGame && i < 10; i++) {
      if (score[i] < 0) break;
      result += score[i];
      cout << setw(3) << result;
      cout << ' ';
    }
    cout << endl;
    cout << endl;
  }
}
