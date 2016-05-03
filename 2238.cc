#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<cmath>
#include<deque>
#define SF scanf
#define PF printf
using namespace std;
typedef long long LL;
const int MAXN = 40;
double f[MAXN+10][MAXN+10][2];
int p21, p31, d1, r1, p22, p32, d2, r2;
int n, m;
double ans;
void dp() {
	double t31 = 1.0 * p31 / (p31 + p21); // 第一个人投三分
	double m31 = 0.8 * p31 / (p31 + d2);  // 第一个人三分命中
	double m21 = 1.0 * p21 / (p21 + d2);  // 第一个人投两分命中
	double g1 = 0.8 * r1 / (r1 + r2);     // 第一个人投球失败但抢球成功
	double t32 = 1.0 * p32 / (p32 + p22);
	double m32 = 0.8 * p32 / (p32 + d1);
	double m22 = 1.0 * p22 / (p22 + d1);
	double g2 = 0.8 * r2 / (r1 + r2);

	double P31 = t31 * m31;  // 第一个人投三分并命中
	double P21 = (1-t31) * m21; // 第一个人投两分并命中
	double Pr1 = g1 * (1 - P31 - P21); // 第一个人未命中但抢球成功
	double Pf1 = (1-g1) * (1-P31-P21); // 第一个人未命中且抢球失败
	double P32 = t32 * m32;
	double P22 = (1-t32) * m22;
	double Pr2 = g2 * (1 - P32 - P22);
	double Pf2 = (1-g2) * (1-P32-P22);

	double ok31 = P31 / (1 - Pr1); // 在第一个人不听重复“未命中->抢球成功"过程后投三分并命中 (1+Pr1+...+Pr1^n) * P31 = P31 / (1-Pr1)
	double ok21 = P21 / (1 - Pr1); // 在第一个人不听重复“未命中->抢球成功"过程后投两分并命中
	double okf1 = Pf1 / (1 - Pr1); // 在第一个人不听重复“未命中->抢球成功"过程后抢球失败
	double ok32 = P32 / (1 - Pr2);
	double ok22 = P22 / (1 - Pr2);
	double okf2 = Pf2 / (1 - Pr2);
	memset(f, 0, sizeof(f));
	for(int i = n; i < 34; i++)
		for(int j = 0; j < n; j++) {
			f[i][j][0] = f[i][j][1] = 1;
			f[j][i][0] = f[j][i][1] = 0;
		}
	for(int i = n-1; i >= 0; i--)
		for(int j = n-1; j >= 0; j--) {
			double trans1 = ok31 * f[i+3][j][0] + ok21 * f[i+2][j][0];
			double trans2 = ok32 * f[i][j+3][1] + ok22 * f[i][j+2][1];
			f[i][j][0] = (trans1 + trans2 * okf1) / (1 - okf1 * okf2); // 两个人不停重复交换控球权概率 (1 + okf1*okf2 + (okf1*okf2)^2 +....+ (okf1*okf2)^n) = 1 / (1 - okf1 * okf2)
			f[i][j][1] = (trans2 + trans1 * okf2) / (1 - okf1 * okf2);
		}
	ans = max(ans, f[0][0][0]);
}
int main() {
	while(~SF("%d%d%d%d%d%d", &n, &m, &p22, &p32, &r2, &d2)) {
		ans = 0;
		for(p21 = 1; p21 <= 10; p21++) {
			if(m-p21 < 3) break;
			if(m-p21 > 30) continue;
			for(p31 = 1; p31 <= 10; p31++) {
				if(m-p21-p31 < 2) break;
				if(m-p21-p31 > 20) continue;
				for(d1 = 1; d1 <= 10; d1++) {
					if(m-p21-p31-d1 < 1) break;
					if(m-p21-p31-d1 > 10) continue;
					r1 = m-p21-p31-d1;
					dp();
				}
			}
		}
		PF("%.3f\n", ans);
	}
}



