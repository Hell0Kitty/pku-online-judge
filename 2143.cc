#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

#define sz(v) ((int)(v).size())
#define rep(i, n) for(int i = 0; i < n; i++)
#define repf(i, a, b) for(int i = a; i <= b; i++)
#define repd(i, a, b) for(int i = a; i >= b; i--)
#define out(n) printf("%d\n", n)
#define mset(a, b) memset(a, b, sizeof(a))
#define wh(n) while(1 == scanf("%d", &n))
#define whz(n) while(1 == scanf("%d", &n) && n != 0)
#define lint long long

using namespace std;

const int INF = 1 << 30;

const int MaxN = 10;

int board[MaxN][MaxN][MaxN * MaxN * MaxN];
int n, m, p;
int maxz;

void put_chess(int x, int y, int id)
{
    int z = 1;
    while(board[x][y][z] != -1) z++;
    board[x][y][z] = id;
    if(z > maxz) maxz = z;
}

int check_one()
{
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1;  k <= maxz; k++) {
                int kk = k;
                int total = 0;
                int id = board[i][j][kk];
                if(id == -1) break;
                while(kk <= maxz && board[i][j][kk] == id) {
                    total++;
                    kk++;
                }
                if(total >= m && id != -1) return id;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= maxz; k++) {
            for(int j = 1; j <= n; j++) {
                int jj = j;
                int total = 0;
                int id = board[i][jj][k];
                if(id == -1) continue;
                while(jj <= n && board[i][jj][k] == id) {
                    total++;
                    jj++;
                }
                if(total >= m && id != -1) return id;
            }
        }
    }
    for(int j = 1; j <= n; j++) {
        for(int k = 1; k <= maxz; k++) {
            for(int i = 1; i <= n; i++) {
                int ii = i;
                int total = 0;
                int id = board[ii][j][k];
                if(id == -1) continue;
                while(ii <= n && board[ii][j][k] == id) {
                    total++;
                    ii++;
                }
                if(total >= m && id != -1) return id;
            }
        }
    }
    return -1;
}

int check_two()
{
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
            int jj = j, kk = k;
            int id = board[i][jj][kk];
            int total = 0;
            if(id == -1) continue;
            while(id == board[i][jj][kk] && jj <= n && kk <= maxz) {
                total++;
                jj++; kk++;
            }
            if(total >= m && id != -1) return id;
        }
        for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
            int jj = j, kk = k;
            int id = board[i][jj][kk];
            int total = 0;
            if(id == -1) continue;
            while(jj >= 1 && kk <= maxz && id == board[i][jj][kk]) {
                total++;
                jj--; kk++;
            }
            if(total >= m && id != -1) return id;
        }
    }
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) for(int k = 1; k <= maxz; k++) {
            int ii = i, kk = k;
            int id = board[ii][j][kk];
            int total = 0;
            if(id == -1) continue;
            while(id == board[ii][j][kk] && ii <= n && kk <= maxz) {
                total++;
                ii++; kk++;
            }
            if(total >= m && id != -1) return id;
        }
        for(int i = 1; i <= n; i++) for(int k = 1; k <= maxz; k++) {
            int ii = i, kk = k;
            int id = board[ii][j][kk];
            int total = 0;
            if(id == -1) continue;
            while(ii >= 1 && kk <= maxz && id == board[ii][j][kk]) {
                total++;
                ii--; kk++;
            }
            if(total >= m && id != -1) return id;
        }
    }
    for(int k = 1; k <= maxz; k++) {
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
            int ii = i, jj = j;
            int id = board[ii][jj][k];
            int total = 0;
            if(id == -1) continue;
            while(id == board[ii][jj][k] && ii <= n && jj <= n) {
                total++;
                ii++; jj++;
            }
            if(total >= m && id != -1) return id;
        }
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) {
            int ii = i, jj = j;
            int id = board[ii][jj][k];
            int total = 0;
            if(id == -1) continue;
            while(ii >= 1 && jj <= n && id == board[ii][jj][k]) {
                total++;
                ii--; jj++;
            }
            if(total >= m && id != -1) return id;
        }
    }
    return -1;
}

int check_three()
{
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii <= n && jj <= n && kk <= maxz && board[ii][jj][kk] == id) {
            total++;
            ii++, jj++, kk++;
        }
        if(total >= m && id != -1) return id;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii <= n && jj >= 0 && kk <= maxz && board[ii][jj][kk] == id) {
            total++;
            ii++, jj--, kk++;
        }
        if(total >= m && id != -1) return id;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii <= n && jj <= n && kk >= 0 && board[ii][jj][kk] == id) {
            total++;
            ii++, jj++, kk--;
        }
        if(total >= m && id != -1) return id;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii <= n && jj >= 0 && kk >= 0 && board[ii][jj][kk] == id) {
            total++;
            ii++, jj--, kk--;
        }
        if(total >= m && id != -1) return id;
    }

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii >= 0 && jj <= n && kk <= maxz && board[ii][jj][kk] == id) {
            total++;
            ii--, jj++, kk++;
        }
        if(total >= m && id != -1) return id;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii >= 0 && jj >= 0 && kk <= maxz && board[ii][jj][kk] == id) {
            total++;
            ii--, jj--, kk++;
        }
        if(total >= m && id != -1) return id;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][k];
        if(-1 == id) continue;
        int total = 0;
        while(ii >= 0 && jj <= n && kk >= 0 && board[ii][jj][kk] == id) {
            total++;
            ii--, jj++, kk--;
        }
        if(total >= m && id != -1) return id;
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) for(int k = 1; k <= maxz; k++) {
        int ii = i, jj = j, kk = k;
        int id = board[ii][jj][kk];
        if(-1 == id) continue;
        int total = 0;
        while(ii >= 0 && jj >= 0 && kk >= 0 && board[ii][jj][kk] == id) {
            total++;
            ii--, jj--, kk--;
        }
        if(total >= m && id != -1) return id;
    }
    return -1;
}

int check_board()
{
    int res = -1;
    res = check_one();
    if(res != -1) return res;
    res = check_two();
    if(res != -1) return res;
    res = check_three();
    if(res != -1) return res;
    return -1;
}

int main()
{
    while(3 == scanf("%d%d%d", &n, &m, &p)) {
        if(0 == n && 0 == m && 0 == p) break;
        int id = 1;
        int total;
        bool f = false;
        mset(board, -1);
        maxz = 0;
        int res;
        for(int i = 0; i < p; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            if(!f) {
                put_chess(x, y, id);
                res = check_board();
                if(res != -1) {
                    f = true;
                    total = i + 1;
                }
                id ^= 1;
            }
        }
        if(f) {
            if(res == 1) printf("Black %d\n", total);
            else printf("White %d\n", total);
        }
        else puts("Draw");
    }
    return 0;
}



