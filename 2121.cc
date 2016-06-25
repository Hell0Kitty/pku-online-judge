#include <iostream>
#include <string>
using namespace std;

int main() {
  char c;
  string s;
  int sum;
  int tem;
  int k = 1;
  sum = 0;
  tem = 0;
  bool cmp(string a, string b);
  string max;
  max = "no";
  while (cin >> s) {
    if (s == "negative") {
      k *= -1;
    } else if (s == "one") {
      tem += 1;
    } else if (s == "two") {
      tem += 2;
    } else if (s == "three") {
      tem += 3;
    } else if (s == "four") {
      tem += 4;
    } else if (s == "five") {
      tem += 5;
    } else if (s == "six") {
      tem += 6;
    } else if (s == "seven") {
      tem += 7;
    } else if (s == "eight") {
      tem += 8;
    } else if (s == "nine") {
      tem += 9;
    } else if (s == "ten") {
      tem += 10;
    } else if (s == "eleven") {
      tem += 11;
    } else if (s == "twelve") {
      tem += 12;
    } else if (s == "thirteen") {
      tem += 13;
    } else if (s == "fourteen") {
      tem += 14;
    } else if (s == "fifteen") {
      tem += 15;
    } else if (s == "sixteen") {
      tem += 16;
    } else if (s == "seventeen") {
      tem += 17;
    } else if (s == "eighteen") {
      tem += 18;
    } else if (s == "nineteen") {
      tem += 19;
    } else if (s == "twenty") {
      tem += 20;
    } else if (s == "thirty") {
      tem += 30;
    } else if (s == "forty") {
      tem += 40;
    } else if (s == "fifty") {
      tem += 50;
    } else if (s == "sixty") {
      tem += 60;
    } else if (s == "seventy") {
      tem += 70;
    } else if (s == "eighty") {
      tem += 80;
    } else if (s == "ninety") {
      tem += 90;
    } else if (s == "hundred") {
      tem *= 100;
    } else if (s == "thousand") {
      tem *= 1000;
      sum += tem;
      tem = 0;
    } else if (s == "million") {
      tem *= 1000000;
      sum += tem;
      tem = 0;
    }
    c = getchar();
    if (c == '\n') {
      cout << k*(sum + tem) << endl;
      sum = 0;
      tem = 0;
      k = 1;
    }
  }
}
