#include <iostream>
#include <algorithm>
#define MAX_N 305
using namespace std;
struct bomber
{
	int x, y;
	int v;
}bombers[MAX_N];
int validIndex[MAX_N];
int validNum;
struct plane
{
	int x, y;
}planes[MAX_N];
struct missle
{
	int x, rnum;
	int rel[MAX_N];
}missles[MAX_N];
int bn, pn, mn, sb, sp, sm, caseN;
bool compare(const bomber &b1, const bomber &b2)
{
	return b1.x <= b2.x;
}
bool canHit(int b, int m)
{
	if(missles[m].x <= bombers[b].x) return false;
	return (missles[m].x - bombers[b].x) * sm >= bombers[b].y * sb;
}
bool theSameBomber(int b1, int b2)
{
	if(bombers[b1].y >= bombers[b2].y) return false;
	return (bombers[b1].x - bombers[b2].x) * sm == (bombers[b2].y - bombers[b1].y) * sb;
}
bool theSameBP(const bomber &b, const plane &p, const missle &m)
{
	if(!(m.x >= b.x && m.x >= p.x && p.y < b.y)) return false;
	if((m.x - b.x) * sm < b.y * sb) return false;
	if((m.x - p.x) * sm < p.y * sp) return false;
	double ft = double(m.x - b.x) / sb - double(b.y) / sm;
	double s1 = m.x - b.x - ft * sb;
	double s2 = b.y;
	double s3 = m.x - p.x - ft * sp;
	double s4 = p.y;
	if((__int64)s1 * sp * s4 != (__int64)s2 * sb * s3) return false;
	return true;
}
int pre[MAX_N];
bool v[MAX_N];
bool can(int node)
{
	for(int i = 0; i < missles[node].rnum; i++)
	{
		int to = missles[node].rel[i];
		if(v[to]) continue;
		v[to] = true;
		if(pre[to] == -1 || can(pre[to]))
		{
			pre[to] = node;
			return true;
		}
	}
	return false;
}
int main()
{
	int c = 0, i, j, k;
	scanf("%d", &caseN);
	for(c = 1; c <= caseN; c++)
	{
		scanf("%d%d%d", &bn, &pn, &mn);
		scanf("%d%d%d", &sb, &sp, &sm);
		for(j = 0; j < bn; j++) 
		{
			scanf("%d%d", &bombers[j].x, &bombers[j].y);
			bombers[j].v = -1;
		}
		for(j = 0; j < pn; j++) scanf("%d%d", &planes[j].x, &planes[j].y);
		for(j = 0; j < mn; j++)
		{
			scanf("%d", &missles[j].x);
			missles[j].rnum = 0;
		}
		sort(bombers, bombers + bn, compare);
		validNum = 0;
		for(i = bn - 1; i >= 0; i--)
		{
			if(bombers[i].v == -1)
			{
				validIndex[validNum++] = i;
				bombers[i].v = i;
			}
			else continue;
			for(j = i - 1; j >= 0; j--)
			{
				if(bombers[j].v != -1) continue;
				if(theSameBomber(i, j)) bombers[j].v = i;
			}
		}
		for(k = 0; k < mn; k++)
		{
			for(j = 0; j < validNum; j++)
			{
				bool can = true;
				int index = validIndex[j];
				if(!canHit(index, k))
					continue;
				for(i = 0; i < pn; i++)
				{
					if(theSameBP(bombers[index], planes[i], missles[k]))
					{
						can = false;
						break;
					}
				}
				if(can)  missles[k].rel[missles[k].rnum++] = j;
			}
		}
		int countv = 0;
		for(i = 0; i < validNum; i++) pre[i] = -1;
		for(i = 0; i < mn; i++)
		{
			memset(v, 0, sizeof(v));
			if(can(i)) countv++;
		}
		printf("Mission #%d: %d bomber(s) exploded\n", c, countv);
	}
	return 0;
}



