#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int n, x, d, spos[300], i, lens, lenc, t, a, b;
    string s, p, c;
    char m[200];

    while(cin >> n && n){
          cin >> s >> p >> c;
          lens = s.length();
          for (i = 0;i  < lens; i++)
              spos[s[i]] = i;

          lenc = c.length();
          d = (int(pow(lenc, 1.5) + n)) % lenc;
          m[d] = p[spos[c[d]]];
          for (i = lenc + d - 1; i > d; i--)
          {
              t = i % lenc;
              a = spos[c[t]];
              b = spos[m[(t+1)%lenc]];
              m[t] = p[a^b];
          }
          m[lenc] = '\0';

          cout << m << endl;
    }
}




