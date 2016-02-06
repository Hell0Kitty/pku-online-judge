#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<map>
#include<cstdlib>
#include<cmath>
#include<vector>
#define LL long long
#define IT __int64
#define zero(x) fabs(x)<eps
#define mm(a,b) memset(a,b,sizeof(a))
const int INF=0x7fffffff;
const double inf=1e8;
const double eps=1e-8;
const double PI=acos(-1.0);
const int Max=20001;
const double R=3437.5;
using namespace std;
int sign(double x)
{
    return (x>eps)-(x<-eps);
}
typedef struct Node
{
    double x;
    double y;
    Node(const double &_x=0, const double &_y=0) : x(_x), y(_y) {}
    void input()
    {
        cin>>x>>y;
    }
    void output()
    {
        cout<<x<<" "<<y<<endl;
    }
}point;
double xmult(point p0,point p1,point p2)
{
	return(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dmult(point p0,point p1,point p2)
{
	return(p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double Distance(point p1,point p2)
{
	return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) );
}
double Distance_Angle(double Angle_1,double Angle_2,double Angle_3,double Angle_4)
{
    double theta,dis;
    Angle_1=Angle_1*PI/180;
    Angle_2=Angle_2*PI/180;
    Angle_3=Angle_3*PI/180;
    Angle_4=Angle_4*PI/180;
    theta=acos(cos(Angle_1)*cos(Angle_3)*cos(Angle_2-Angle_4)+sin(Angle_1)*sin(Angle_3));
    dis=theta*R;
    return dis;
}
int main()
{
    int n,m,i,j;
    int HH,MM,SS;
    double dis;
    double x1,x2,x3;
    double y1,y2,y3;
    double a1,a2,a3;
    double b1,b2,b3;
    double Angle_1,Angle_2,Angle_3,Angle_4;
    char str1[100],str2[100],str3[100],str4[100],str5[100];
    char c1,c2,c3;
    while(scanf("%s",&str1)!=EOF)
    {
        getchar();
        scanf("%c%d%c",&c1,&n,&c2);

        scanf("%s%s",&str1,&str2);
        scanf("%d:%d:%d.",&HH,&MM,&SS);

        scanf("%s%s%s%s",&str1,&str2,&str3,&str4);
        scanf("%lf%c%lf%c%lf%c",&x1,&c1,&x2,&c2,&x3,&c3);
        Angle_1=x1+x2/60+x3/3600;
        scanf("%s",&str1);
        if(str1[0]=='S')//鍗楃粡鐨勭偣鍊兼槸璐熷�
            Angle_1=-Angle_1;

        scanf("%s",&str1);

        scanf("%lf%c%lf%c%lf%c",&y1,&c1,&y2,&c2,&y3,&c3);

        Angle_2=y1+y2/60+y3/3600;
        scanf("%s",&str1);
        if(str1[0]=='W')
            Angle_2=-Angle_2;

        scanf("%s%s%s%s%s",&str1,&str2,&str3,&str4,&str5);
        scanf("%lf%c%lf%c%lf%c",&a1,&c1,&a2,&c2,&a3,&c3);
        Angle_3=a1+a2/60+a3/3600;
        scanf("%s",&str1);
        if(str1[0]=='S')
            Angle_3=-Angle_3;

        scanf("%s",&str1);
        scanf("%lf%c%lf%c%lf%c",&b1,&c1,&b2,&c2,&b3,&c3);
        Angle_4=b1+b2/60+b3/3600;
        scanf("%s",&str1);
        if(str1[0]=='W')
            Angle_4=-Angle_4;

        scanf("%s",&str1);

        dis=Distance_Angle(Angle_1,Angle_2,Angle_3,Angle_4);
        cout<<"The distance to the iceberg: "<<setprecision(2)<<setiosflags(ios::fixed)<<dis<<" miles."<<endl;
        if(sign(dis-100+0.005)<0)
            cout<<"DANGER!"<<endl;
    }
    return 0;
}



