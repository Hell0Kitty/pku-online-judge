#include <stdio.h>
#include <math.h>

#define	EPS		1E-8

double	h, d, v;
double	r;

double
getv(double s) {

	double	_h;

	_h = r - s;

	return h * r * r * acos(_h / r) / 3.0 -
		   _h * h * sqrt(r * r - _h * _h) * 2.0 / 3.0 +
		   _h * _h * _h * h / r * log(( r + sqrt(r * r - _h * _h) ) / _h) / 3.0;
}

int
main() {

	int		t;

	double	lft, rht, mid;

	scanf("%d", &t);
	while ( t-- ) {

		scanf("%lf%lf%lf", &h, &d, &v);
		r = d / 2.0;

		lft = 0.0;
		rht = r;

		while ( rht - lft > EPS ) {

			mid = ( lft + rht ) / 2.0;

			if ( getv(mid) < v ) lft = mid;
			else rht = mid;
		}

		printf("%.5lf\n", d - ( lft + rht ) / 2.0);
	}

	return 0;
}


