#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<queue>
#define ll long long;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define inf 0x3f3f3f3f
#define ins 0xc0
using namespace std;
int M, N, sx, sy, ex, ey;
char a[305][305];
int t[305][305];
int d[4][2] = { 1, 0, 0, 1, 0, -1, -1, 0 };
struct pnt{
	int x, y;
};
int bfs()
{
	pnt p, np;
	p.x = sx;
	p.y = sy;
	memset(t, 0x3f, sizeof t);
	t[sx][sy] = 0;
	queue< pnt > que;
	que.push(p);
	while (!que.empty()){
		p = que.front(); que.pop();
		for (int i = 0; i < 4; i++){
			np.x = p.x + d[i][0];
			np.y = p.y + d[i][1];
			if (np.x >= 0 && np.x < M&&np.y >= 0 && np.y < N&&a[np.x][np.y] != 'R'&&a[np.x][np.y] != 'S'){
				if (a[np.x][np.y] == 'E'||a[np.x][np.y]=='T'){
					if (t[p.x][p.y] + 1 < t[np.x][np.y]){
						t[np.x][np.y] = t[p.x][p.y] + 1;
						que.push(np);
					}
				}
				else if (a[np.x][np.y] == 'B'){
					if (t[p.x][p.y] + 2 < t[np.x][np.y]){
						t[np.x][np.y] = t[p.x][p.y] + 2;
						que.push(np);
					}
				}
			}
		}
	}
	return (t[ex][ey] == inf ? -1 : t[ex][ey]);
}
int main()
{
	while (scanf("%d%d", &M, &N) != EOF && (M || N)){
			for (int i = 0; i < M; i++) scanf("%s", &a[i]);
			for (int i = 0; i < M; i++){
				for (int j = 0; j < N; j++){
					if (a[i][j] == 'Y'){
						sx = i;
						sy = j;
					}
					else if (a[i][j] == 'T'){
						ex = i;
						ey = j;
					}

				}
			}

			int tt = bfs();
			printf("%d\n", tt);
		}
		return 0;
}




