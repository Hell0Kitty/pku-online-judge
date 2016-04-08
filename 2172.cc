<pre class = "lang:c++ decode:true">
#include &lt; math.h & gt;
#include &lt; stdio.h & gt;
#include &lt; stdlib.h & gt;

    struct point {
  double x, y, h;
} a, b;

void Swap(double &amp; a, double &amp; b) {
  double t;
  t = a;
  a = b;
  b = t;
}

bool check(double c, double d, double a, double b) {
  if (a * b & lt; c * d) return false;
  if (a & lt; b) Swap(a, b);
  if (c & lt; d) Swap(c, d);
  if (b & lt; d) return false;
  if (a & gt; = c & amp; &amp; b & gt; = d) return true;
  double dis = sqrt(c * c + d * d);
  double p = asin(b / dis);
  double q = asin(d / dis);
  double sita = p - q;
  double Len = c * cos(sita) + d * sin(sita);
  if (Len & lt; = a) return true;
  return false;
}

int main() {
  scanf("%lf %lf %lf %lf %lf", &amp; a.x, &amp; a.y, &amp; a.h, &amp; b.x, &amp;
        b.y);
  if (check(a.x, a.y, b.x, b.y) || check(a.x, a.h, b.x, b.y) ||
      check(a.y, a.h, b.x, b.y))
    puts("YES");
  else
    puts("NO");
  return 0;
}
