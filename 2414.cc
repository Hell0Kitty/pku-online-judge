#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int N, L, T[2050];
char code[2050][1050];

int main() {
    int ret, lim; 
    while (scanf("%d %d", &N, &L), N|L) {
        ret = 0; 
        lim = N << 1;
        for (int i = N; i < lim; i++) {
            scanf("%s", code[i]);
        }
        for (int p = 0; p < L; ++p) {
            for (int i = N; i < lim; ++i) {
                T[i] = 1 << (code[i][p]-'A');
            }
            for (int i = N-1; i > 0; --i) {
                int lch = i << 1, rch = i << 1 | 1;
                T[i] = T[lch] & T[rch]; 
                if (T[i] == 0) { 
                    T[i] = T[lch] | T[rch];
                    ++ret;
                }
            }
            for (int i = 0; i < 26; ++i) {
                if (T[1] & (1 << i)) {
                    putchar('A' + i);
                    break;    
                }    
            } 
        }
        printf(" %d\n", ret); 
    }
    return 0;
}



