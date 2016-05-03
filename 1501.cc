#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;
int dim = 0;
char matrix[105][105];

int inline round(int para) {
  if (para < 0)
    return dim + para;
  else if (para >= dim)
    return para - dim;
  return para;
}

void proc(string& word) {
  if (word.size() > dim) {
    puts("Not found");
    return;
  }
  bool global_found = false;

  for (int i = 0; i < dim; ++i)
    for (int j = 0; j < dim; ++j) {
      if (matrix[i][j] == word[0]) {
        // four direction;
        // right
        //	cout << "[dbg] match point start at: " <<  i  << " " << j <<
        // endl;
        bool matched = true;
        int t = 0;

        //	cout << "[dbg] now go right" << endl;
        for (; t < word.size(); ++t) {
          if (word[t] == matrix[i][round(j + t)])
            continue;
          else {
            matched = false;
            break;
          }
        }
        if (matched) {
          global_found = true;
          printf("%d,%d ", i + 1, j + 1);
          printf("%d,%d\n", i + 1, round(j + t - 1) + 1);
        }

        // left
        matched = true;
        //  cout << "[dbg] now go left" << endl;;
        for (t = 0; t < word.size(); ++t) {
          if (word[t] == matrix[i][round(j - t)])
            continue;
          else {
            matched = false;
            break;
          }
        }
        if (matched) {
          global_found = true;
          printf("%d,%d ", i + 1, j + 1);
          printf("%d,%d\n", i + 1, round(j - t + 1) + 1);
        }

        // down
        matched = true;
        //	cout << "[dbg] now go down" << endl;
        for (t = 0; t < word.size(); ++t) {
          if (word[t] == matrix[round(i + t)][j]) {
            //		cout << "[dbg] current coordinate: " << round(i+t) << "
            //"
            //<<
            // j
            //<< endl;
            continue;
          } else {
            matched = false;
            break;
          }
        }
        if (matched) {
          global_found = true;
          printf("%d,%d ", i + 1, j + 1);
          printf("%d,%d\n", round(i + t - 1) + 1, j + 1);
        }

        // up
        matched = true;
        //	cout << "[dbg] now go up" << endl;
        for (t = 0; t < word.size(); ++t) {
          if (word[t] == matrix[round(i - t)][j])
            continue;
          else {
            matched = false;
            break;
          }
        }
        if (matched) {
          global_found = true;
          printf("%d,%d ", i + 1, j + 1);
          printf("%d,%d\n", round(i - t + 1) + 1, j + 1);
        }
      }
    }
  if (!global_found) puts("Not found");
}

int main(int argc, char const* argv[]) {
  /* code */
  while (true) {
    cin >> dim;
    // cout << "[dbg] input dim: " << dim << endl;

    if (!dim) break;
    string buffer;
    for (int i = 0; i < dim; ++i) {
      cin >> buffer;
      for (int j = 0; j < dim; ++j) {
        matrix[i][j] = buffer[j];
      }
    }

    while (true) {
      string word;
      cin >> word;
      if (word[0] == '0') return 0;
      //	cout << "[dbg] current word: " << word << endl;
      proc(word);
    }
  }
  return 0;
}