#include "stdio.h"
#include "math.h"
#define N 210

typedef struct
{
double x;
double y;
double z;
}point; point al[N],em[N];

double eqa,eqb,eqc,eqd,eq;

int numa,nume;

int friend_or_foe()
{
bool judge;
int count = 0,i,j;
eqa = 0;
eqb = 0;
eqc = 0;
eqd = 0;
while (count++ < 100000)
{
judge = 1;
for (i = 1;i <= nume;i ++)
{
eq = eqa * em[i].x + eqb * em[i].y + eqc * em[i].z + eqd;

if (eq <= 0)
{
eqa += em[i].x;
eqb += em[i].y;
eqc += em[i].z;
eqd += 3;
judge = 0;
}
}

for (i = 1;i <= numa;i ++)
{
eq = eqa * al[i].x + eqb * al[i].y + eqc * al[i].z + eqd;

if (eq > 0)
{
eqa -= al[i].x;
eqb -= al[i].y;
eqc -= al[i].z;
eqd -= 3;
judge = 0;
}
}
if (judge)
break;
}

printf("%.6lf %.6lf %.6lf %.6lf\n",eqa,eqb,eqc,eqd);

return 0;
}

int main()
{
int i;
while(1)
{
scanf("%d",&numa);

if (numa < 0)
{
scanf("%d",&nume);
break;
}

for (i = 1;i <= numa;i ++)
scanf("%lf%lf%lf",&al[i].x,&al[i].y,&al[i].z);

scanf("%d",&nume);

for (i = 1;i <= nume;i ++)
scanf("%lf%lf%lf",&em[i].x,&em[i].y,&em[i].z);

friend_or_foe();
}

return 0;
}




