#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct nod
{
double x,y;
double s,r,d;
double dis;
}enermy[1000];

bool cmp(nod a, nod b)
{
return a.dis<b.dis;
}

void distance(int x)
{
enermy[x].dis= sqrt ( enermy[x].y*enermy[x].y+(100-enermy[x].x)*(100-enermy[x].x) )-enermy[x].r;
}

int main()
{
double HP;
double len;
int n,i;
int mark;
while(cin>>n)
{
mark=1;
len=100;
for(i=0;i<n;i++)
{
scanf("%lf%lf%lf%lf%lf",&enermy[i].x,&enermy[i].y,&enermy[i].s,&enermy[i].r,&enermy[i].d);
distance(i);
}
scanf("%lf",&HP);

sort(enermy,enermy+n,cmp);

for(i=0;i<n;i++)
{
if(enermy[i].dis>len)
continue;
else
{
len+=enermy[i].s;
HP-=enermy[i].d;
}
if(HP<=0)
{
mark=0;
break;
}
}

if(mark==1)
cout<<"Safe!"<<endl;
else
cout<<"Danger!"<<endl;
}
return 0;
}




