#include <cstdio>
#include <cstring>
#define MAXN 805
#define MAXM 34350
#define INF 2147483647
using namespace std;

char sc;
int T, kase;
int r, c, d;
int px[MAXN], py[MAXN], ph[MAXN], plr;
int map[20][20];
int st, en, L;
int fst[MAXN], nxt[MAXM], to[MAXM], e;
int cap[MAXM], flw[MAXM];
int que[MAXN], hd, tl;
int dis[MAXN], num[MAXN];
int pre[MAXN], cur[MAXN];

inline int nxtInt() {
	while ((sc = getchar()) < '0' || sc > '9'); int r = sc - '0';
	while ((sc = getchar()) >= '0' && sc <= '9') (r *= 10) += sc - '0';
	return r;
}

inline int min(int x, int y) {
	if (x > y) return y; else return x;
}

inline int sqr(int x) {
	return x * x;
}

inline void add_edge(int u, int v, int c) {
	nxt[e] = fst[u]; fst[u] = e; to[e] = v; cap[e] = c; flw[e++] = 0;
}

inline void Inv_bfs(int en) {
	memset(dis, 0, sizeof dis);
	for (dis[que[hd = tl = 0] = en] = 1; hd <= tl; ++hd)
		for (int e = fst[que[hd]], v = to[e]; ~e; v = to[e = nxt[e]])
			if (!dis[v]) que[++tl] = v, dis[v] = dis[que[hd]] + 1;
}

inline int augment() {
	int aug = INF;
	for (int u = en; u ^ st; u = to[pre[u] ^ 1])
		aug = min(aug, cap[pre[u]] - flw[pre[u]]);
	for (int u = en; u ^ st; u = to[pre[u] ^ 1])
		flw[pre[u]] += aug, flw[pre[u] ^ 1] -= aug;
	return aug;
}

inline int ISAP(int st, int en) {
	int flow = 0, u = st;  Inv_bfs(en);
	memset(num, 0, sizeof num);
	for (int i = st; i <= en; ++num[dis[i++]]);
	memcpy(cur, fst, sizeof cur);
	while (dis[st] <= en + 1) {
		if (u == en) flow += augment(), u = st;
		bool adv = false;
		for (int e = cur[u]; ~e && !adv; e = nxt[e])
			if (cap[e] > flw[e] && dis[to[e]] + 1 == dis[u])
				adv = true, pre[to[e]] = e, cur[u] = e, u = to[e];
		if (!adv) {
			int nw = en + 1;
			for (int e = fst[u]; ~e; e = nxt[e])
				if (cap[e] > flw[e] && dis[to[e]])
					nw = min(nw, dis[to[e]]);
			if (!--num[dis[u]]) break;
			++num[dis[u] = nw + 1];
			cur[u] = fst[u];
			if (u ^ st) u = to[pre[u] ^ 1];
		}
	}
	return flow;
}

int main() {
	for (T = nxtInt(); T; --T) {
		L = plr = 0; memset(map, 0, sizeof map);
		r = nxtInt(); d = nxtInt();
		while ((sc = getchar()) < '0' || sc > '9'); c = 1;
		if (sc -= '0') map[0][0] = ++plr, ph[plr] = sc, px[plr] = py[plr] = 0;
		while ((sc = getchar()) >= '0' && sc <= '9') {
			if (sc -= '0') map[0][c] = ++plr, ph[plr] = sc, px[plr] = 0, py[plr] = c; ++c;
		}
		for (int i = 1; i < r; ++i)
			for (int j = 0; j < c; ++j) {
				while ((sc = getchar()) < '0' || sc > '9');
				if (sc -= '0') map[i][j] = ++plr, ph[plr] = sc, px[plr] = i, py[plr] = j;
			}
		memset(fst, -1, sizeof fst); e = 0; st = 0; en = plr << 1 | 1;
		for (int i = 1; i <= plr; ++i) {
			add_edge(i, i + plr, ph[i]), add_edge(i + plr, i, 0);
			if (px[i] < d || px[i] >= r - d || py[i] < d || py[i] >= c - d)
				add_edge(i + plr, en, INF), add_edge(en, i + plr, 0);
			for (int j = i + 1; j <= plr; ++j)
				if (sqr(px[i] - px[j]) + sqr(py[i] - py[j]) <= sqr(d)) {
					add_edge(i + plr, j, INF), add_edge(j, i + plr, 0);
					add_edge(j + plr, i, INF), add_edge(i, j + plr, 0);
				}
		}
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j) {
				while ((sc = getchar()) ^ '.' && sc ^ 'L');
				if (sc == 'L') ++L, add_edge(st, map[i][j], 1), add_edge(map[i][j], st, 0);
			}
		printf("Case #%d: ", ++kase);
		switch (L -= ISAP(st, en)) {
		case 0: printf("no lizard was "); break;
		case 1: printf("1 lizard was "); break;
		default: printf("%d lizards were ", L); break;
		}
		puts("left behind.");
	}
	return 0;
}



