#include <iostream>
#include <map>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
map<string, int> text;
map<string, int> text1;
string temp;
bool allPunc(string &str) {
  char c;
  string temp = "";
  bool allP = true;
  for (int i = 0; i < str.length(); i++) {
    c = str[i];
    if (c >= 'A' && c <= 'Z') {
      allP = false;
      temp = temp + char(c - 'A' + 'a');
    } else if (c >= 'a' && c <= 'z') {
      allP = false;
      temp = temp + c;
    } else if (c >= '0' && c <= '9') {
      allP = false;
      temp = temp + c;
    }
  }
  str = temp;
  return allP;
}
void checkInsert(const string &str) {
  map<string, int>::iterator it;
  it = text1.find(str);
  if (it != text1.end()) {
    it->second++;
  }
}
void init() {
  map<string, int>::iterator it;
  for (it = text1.begin(); it != text1.end(); it++) it->second = 0;
}
double getRes() {
  double total = 0;
  map<string, int>::iterator it;
  map<string, int>::iterator it1;
  for (it = text.begin(); it != text.end(); it++) {
    it1 = text1.find(it->first);
    total += sqrt(double(it->second) * double(it1->second));
  }
  return total;
}
int main() {
  text.clear();
  while (cin >> temp && temp != "----------") {
    if (!allPunc(temp)) {
      map<string, int>::iterator it;
      it = text.find(temp);
      if (it == text.end())
        text[temp] = 1;
      else
        text[temp]++;
    }
  }
  while (cin >> temp && temp != "----------") {
    text1 = text;
    init();
    if (!allPunc(temp)) checkInsert(temp);
    while (cin >> temp && temp != "----------") {
      if (!allPunc(temp)) checkInsert(temp);
    }
    printf("%.2f\n", getRes());
  }
  return 0;
}
