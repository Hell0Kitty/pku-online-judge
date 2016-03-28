#include <iostream>
#include <string>
using namespace std;

string extractword(string str, int index, bool afterdigit, int& step,
                   bool& isdigit, int& digit, bool& neg) {
  string word;
  neg = false;
  isdigit = false;
  digit = 0;
  step = 0;
  bool effective = false;
  bool repeatedzero = false;
  if (!afterdigit) {
    effective = true;
  }
  for (int i = index; i < str.length(); ++i) {
    step++;
    if (str[i] == '-' || str[i] == '+') {
      if (i == index) {
        if (!afterdigit && str[i] == '-') {
          neg = true;
        }
      } else {
        if (isdigit & neg) {
          digit *= -1;
        }
        step--;
        return word;
      }
      if (!afterdigit && i + 1 < str.length() &&
          (str[i + 1] <= '9' && str[i + 1] >= '0')) {
        continue;
      }
    }

    if (str[i] <= '9' && str[i] >= '0') {
      if (!isdigit) {
        if (i != index &&
            !(i == index + 1 && (str[index] == '+' || str[index] == '-') &&
              effective)) {
          step--;
          return word;
        }
      }
      isdigit = true;
      afterdigit = true;
      digit = digit * 10 + str[i] - '0';
      if (str[i] == '0' && i + 1 < str.length() &&
          (str[i + 1] <= '9' && str[i + 1] >= '0')) {
        continue;
      }
    }

    if (str[i] <= 'Z' && str[i] >= 'A') {
      str[i] += 'a' - 'A';
    }

    if (str[i] <= 'z' && str[i] >= 'a') {
      if (isdigit) {
        if (neg) {
          digit *= -1;
        }
        step--;
        return word;
      }
    }
    word.push_back(str[i]);
  }
  if (isdigit && neg) {
    digit *= -1;
  }
  return word;
}

int compare(string a, string b) {
  bool afterdigita = false, afterdigitb = false;

  int i = 0, j = 0;
  while (i < a.length() && j < b.length()) {
    int stepa = 0, stepb = 0;
    bool isdigita = false, isdigitb = false;
    bool isnega = false, isnegb = false;
    int digita = -1, digitb = -1;
    string worda =
        extractword(a, i, afterdigita, stepa, isdigita, digita, isnega);
    string wordb =
        extractword(b, j, afterdigitb, stepb, isdigitb, digitb, isnegb);

    if (isdigita) {
      afterdigita = true;
    } else {
      afterdigita = false;
    }
    if (isdigitb) {
      afterdigitb = true;
    } else {
      afterdigitb = false;
    }
    if (isdigita && isdigitb) {
      if (isnega && !isnegb) {
        if (worda == "0" && wordb == "0") {
          return 0;
        } else {
          return -1;
        }
      }

      if (isnegb && !isnega) {
        if (worda == "0" && wordb == "0") {
          return 0;
        } else {
          return -1;
        }
      }

      if (worda.length() != wordb.length()) {
        if (isnega) {
          return worda.length() < wordb.length() ? 1 : -1;
        } else {
          return worda.length() < wordb.length() ? -1 : 1;
        }
      }

      for (int i = 0; i < worda.length(); ++i) {
        if (worda[i] != wordb[i]) {
          if (isnega) {
            return (worda[i] - '0') < (wordb[i] - '0') ? 1 : -1;
          } else {
            return (worda[i] - '0') < (wordb[i] - '0') ? -1 : 1;
          }
        }
      }

    } else {
      if (worda < wordb) {
        return -1;
      } else if (worda > wordb) {
        return 1;
      }
    }
    i += stepa;
    j += stepb;
  }
  if (i < a.length()) {
    return 1;
  }
  if (j < b.length()) {
    return -1;
  }
  return 0;
}

int main() {
  int N;
  cin >> N;
  for (int no = 0; no < N; ++no) {
    string a, b;
    cin >> a >> b;
    cout << no + 1 << " ";
    cout << compare(a, b) << endl;
  }
  return 0;
}
