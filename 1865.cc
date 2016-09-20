#include <iostream>
#include <cmath>
using namespace std;

double sigma(double x) {
	return 1.0 / (1.0 + exp(-x));
}

int f[105];
int t[105];

int main() {
	int n;
	while(scanf("%d",&n) && n) {
		for(int i=0;i<n;i++) scanf("%d %d",&f[i],&t[i]);
		double da, db;
		double wa, wb;
		wa = wb = 0;
		while(true) {
			double a,b,c,d;
			double dda, ddb;
			a = b = c = d = dda = ddb = 0;
			for(int i=0;i<n;i++) {
				double prob = sigma(wa + f[i] * wb);
				double tb = prob * (1-prob);
				dda += prob - t[i];
				ddb += f[i] * (prob - t[i]);
				a += tb;
				b += tb * f[i];
				c += tb * f[i];
				d += tb * f[i] * f[i];
			}
			double temp = 1.0 / (d - b * c / a);
			da = (1.0 / a + b * c * temp / a / a) * dda + (-b * temp / a) * ddb;
			db = (-c * temp / a) * dda + temp * ddb;
			if(fabs(da) < 1e-10 || fabs(db) < 1e-10) break;
			wa -= da;
			wb -= db;
		}
		printf("%.4f %.4f\n", wa, wb);
	}
	return 0;
}



