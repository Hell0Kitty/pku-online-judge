#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <map>
#include <deque>
using namespace std;
#define PSS pair<int,int>
#define x first
#define y second
int n,m,g;
char Map[17][17];

struct dat {
 PSS pos[3];
 int step;
} ini,aim;

deque<dat> que1,que2;

#define N 15
short h1[N][N][N][N][N][N],
 h2[N][N][N][N][N][N];

const int dx[5]={0,0,-1,1,0},
 dy[5]={-1,1,0,0,0};

inline short& h(short h[][N][N][N][N][N],const dat & cur) {
 return h[cur.pos[0].x-1][cur.pos[0].y-1]
 [cur.pos[1].x-1][cur.pos[1].y-1]
 [cur.pos[2].x-1][cur.pos[2].y-1];
}

inline void expand(dat &cur,deque<dat> &que,short h1[][N][N][N][N][N]) {
 register int d1,d2,d3,p1,q1,p2,q2,p3,q3;
 if (g==1) {
 for (d1=0;d1<4;d1++) {
 p1=cur.pos[0].x+dx[d1],
 q1=cur.pos[0].y+dy[d1];
 if (Map[p1][q1]==' ') {
 cur.pos[0]=PSS(p1,q1);
 cur.step++;
 if (h(h1,cur)<0) {
 h(h1,cur)=cur.step;
 que.push_back(cur);
 }
 cur=que.front();
 }
 }
 } else

 if (g==2) {
 for (d1=0;d1<5;d1++) {
 p1=cur.pos[0].x+dx[d1],
 q1=cur.pos[0].y+dy[d1];
 if (Map[p1][q1]!=' ') continue;

 for (d2=0;d2<5;d2++)
 if (d1+d2<8) {

 p2=cur.pos[1].x+dx[d2],
 q2=cur.pos[1].y+dy[d2];
 if (Map[p2][q2]!=' ') continue;

 if (p1!=p2||q1!=q2)
 if (p1!=cur.pos[1].x||q1!=cur.pos[1].y||
 p2!=cur.pos[0].x||q2!=cur.pos[0].y) {
 cur.pos[0]=PSS(p1,q1);
 cur.pos[1]=PSS(p2,q2);
 cur.step++;
 if (h(h1,cur)<0) {
 h(h1,cur)=cur.step;
 que.push_back(cur);
 }
 cur=que.front();
 }
 }
 }
 } else

 if (g==3) {
 for (d1=0;d1<5;d1++) {
 p1=cur.pos[0].x+dx[d1],
 q1=cur.pos[0].y+dy[d1];
 if (Map[p1][q1]!=' ') continue;

 for (d2=0;d2<5;d2++) {
 p2=cur.pos[1].x+dx[d2],
 q2=cur.pos[1].y+dy[d2];
 if (Map[p2][q2]!=' ') continue;
 if (p1==p2&&q1==q2) continue;
 if (p1!=cur.pos[1].x||q1!=cur.pos[1].y||
 p2!=cur.pos[0].x||q2!=cur.pos[0].y)
 for (d3=0;d3<5;d3++)
 if (d1+d2+d3<12) {
 p3=cur.pos[2].x+dx[d3],
 q3=cur.pos[2].y+dy[d3];
 if (Map[p3][q3]!=' ') continue;
 if (p2==p3&&q2==q3 ||
 p3==p1&&q3==q1) continue;

 if (p2!=cur.pos[2].x||q2!=cur.pos[2].y||
 p3!=cur.pos[1].x||q3!=cur.pos[1].y)
 if (p3!=cur.pos[0].x||q3!=cur.pos[0].y||
 p1!=cur.pos[2].x||q1!=cur.pos[2].y) {
 cur.pos[0].x=p1,cur.pos[0].y=q1;
 cur.pos[1].x=p2,cur.pos[1].y=q2;
 cur.pos[2].x=p3,cur.pos[2].y=q3;
 cur.step++;
 if (h(h1,cur)<0) {
 h(h1,cur)=cur.step;
 que.push_back(cur);
 }
 cur=que.front();
 }
 }
 }
 }
 }
}

int main() {

 int i,j,k;
 while (~scanf("%d%d%d\n",&m,&n,&g)) {
 if (!(m+n+g)) break;
 memset(Map,0,sizeof(Map));
 for (i=1;i<=n;i++) {
 gets(&Map[i][1]);
 for (j=1;j<=m;j++)
 if (Map[i][j]!='#') {
 switch (Map[i][j]) {
 case 'a': ini.pos[0]=PSS(i,j); break;
 case 'b': ini.pos[1]=PSS(i,j); break;
 case 'c': ini.pos[2]=PSS(i,j); break;
 case 'A': aim.pos[0]=PSS(i,j); break;
 case 'B': aim.pos[1]=PSS(i,j); break;
 case 'C': aim.pos[2]=PSS(i,j);
 }
 Map[i][j]=' ';
 }
 }

 que1.clear(),que1.push_back(ini);
 que2.clear(),que2.push_back(aim);
 memset(h1,0xff,sizeof(h1));
 memset(h2,0xff,sizeof(h2));
 h(h1,ini)++;
 h(h2,aim)++;
 int ans=-1,cnt1=0,cnt2=0;
 while (que1.size()||que2.size()) {
 register dat cur;
 if (que1.size()) {
 cur=que1.front();
 if (h(h2,cur)>=0) {
 ans=cur.step+h(h2,cur);
 break;
 }
 expand(cur,que1,h1);
 que1.pop_front();
 }
 if (que2.size()) {
 cur=que2.front();
 if (h(h1,cur)>=0) {
 ans=cur.step+h(h1,cur);
 break;
 }
 expand(cur,que2,h2);
 que2.pop_front();
 }
 }
 printf("%d\n",ans);
 }
 return 0;
}


