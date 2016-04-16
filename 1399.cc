#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned int uint;
const int MAX = 256;
const uint INF = 1 << 30;
const int DIR[4][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

class Town {
private:
        uint step[MAX][MAX];
        int w, h, terrain[MAX][MAX];
        int bsr, bsc, bdr, bdc;
        bool go(int, int, int, int) const;
        bool see(int, int, int, int) const;
        bool visible(int, int, int, int, bool) const;
        inline void push(queue<int>& Q, int r, int c, uint s) { Q.push((r<<8)+c); step[r][c] = s; }
public:
        void make();
        uint walk();
};
void Town::make() {
        scanf("%d %d", &h, &w); int i, j;
        for(i = 0; i < h; i++)
                for(j = 0; j < w; j++) scanf("%d", &terrain[i][j]);
        memset(step, -1, sizeof(step));
        scanf("%d %d %d %d", &bsr, &bsc, &bdr, &bdc);
        bsr--; bsc--; bdr--; bdc--;
}
uint Town::walk() {
        queue<int> Q;
        if(bsr == bdr && bsc == bdc) return 0;
        push(Q, bsr, bsc, 0);
        while(!Q.empty()) {
                int i, p = Q.front(); Q.pop();
                int x = p >> 8, y = p & 255;
                for(i = 0; i < 4; i++) {
                        int cx = x+DIR[i][0], cy = y+DIR[i][1];
                        if(go(x, y, cx, cy)) {
                                push(Q, cx, cy, step[x][y]+1);
                                if(cx == bdr && cy == bdc) return step[bdr][bdc];
                        }
                }
        }
        return INF;
}
bool Town::go(int sr, int sc, int dr, int dc) const {
        if(dr < 0 || dr >= h || dc < 0 || dc >= w || step[dr][dc] <= step[sr][sc]+1) return false;
        int diff = terrain[sr][sc]-terrain[dr][dc];
        if(diff > 3 || diff < -1) return false;
        else return see(dr, dc, bsr, bsc) || see(dr, dc, bdr, bdc);
}
bool Town::see(int r1, int c1, int r2, int c2) const {
        return visible(r1, c1, r2, c2, true) && visible(c1, r1, c2, r2, false);
}
bool Town::visible(int x1, int y1, int x2, int y2, bool subx) const {
        if(x1 == x2) return true;
        else if(x1 > x2) { swap(x1, x2); swap(y1, y2); }
        int z1 = subx ? terrain[x1][y1] : terrain[y1][x1], z2 = subx ? terrain[x2][y2] : terrain[y2][x2];
        int dx = x2-x1, dy = y2-y1, dz = z2-z1, y = 2*dx*y1+dy, z = (2*z1+1)*dx+dz;
        int cx, p = (dy > 0) ? 1 : 0;
        for (cx = x1+1; cx <= x2; cx++) {
                int ry = (y + dx - p) / (2 * dx) ;
                int ry2 = (y + dx - 1 + p) / (2 * dx) ;
                if(subx) {
                        if (z < terrain[cx-1][ry]*2*dx || z < terrain[cx][ry2]*2*dx) return false;
                } else {
                        if(z < terrain[ry][cx-1]*2*dx || z < terrain[ry2][cx]*2*dx) return false;
                }
                z += 2*dz ; y += 2*dy;
        }
        return true;
}

int main()
{
        Town town;
        int t, T;

        scanf("%d", &T);
        for(t = 0; t < T; t++) {
                town.make();
                uint path = town.walk();
                if(path == INF) printf("Mission impossible!\n");
                else printf("The shortest path is %u steps long.\n", path);
        }

        return 0;
}



