#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
struct Data
{
    int h,m;
    Data(int _h,int _m){h=_h;m=_m;}
    Data(){};
};
struct Zone
{
    int h,m;
    char s[5];
    void print()
    {
        if(h==12&&m==0)
        {
            if(s[0]=='a')
                printf("midnight\n");
            else
                printf("noon\n");
        }
        else
        {
            printf("%d:%s%d %s\n",h,(m<10)?"0":"",m,s);
        }
    }
};
map<string,Data> ha;
void change(char s[])
{
    if(s[0]=='a')
        strcpy(s,"p.m.");
    else
        strcpy(s,"a.m.");
}
Zone sub(Zone a,Data b)
{
    Zone s;
    s.h=a.h-b.h;
    s.m=a.m-b.m;
    strcpy(s.s,a.s);
    if(s.m<0)
    {
        s.m+=60;
        s.h--;
    }
    else if(s.m>59)
    {
        s.m-=60;
        s.h++;
    }
    if(s.h<=0)
    {
        if(s.h<0)
            change(s.s);
        s.h+=12;
    }
    else if(s.h>12)
    {
        s.h-=12;
        if(a.h!=12)
            change(s.s);
    }
    else if(s.h==12)
    {
        if(a.h!=12)
            change(s.s);
    }
    else if(a.h==12)
        change(s.s);
    return s;
}
int main()
{
    ha.clear();
    ha["UTC"]=Data(0,0);ha["GMT"]=Data(0,0);ha["BST"]=Data(1,0);
    ha["IST"]=Data(1,0);ha["WET"]=Data(0,0);ha["WEST"]=Data(1,0);
    ha["CET"]=Data(1,0);ha["CEST"]=Data(2,0);ha["EET"]=Data(2,0);
    ha["EEST"]=Data(3,0);ha["MSK"]=Data(3,0);ha["MSD"]=Data(4,0);
    ha["AST"]=Data(-4,0);ha["ADT"]=Data(-3,0);ha["NST"]=Data(-3,-30);
    ha["NDT"]=Data(-2,-30);ha["EST"]=Data(-5,0);ha["EDT"]=Data(-4,0);
    ha["CST"]=Data(-6,0);ha["CDT"]=Data(-5,0);ha["MST"]=Data(-7,0);
    ha["MDT"]=Data(-6,0);ha["PST"]=Data(-8,0);ha["PDT"]=Data(-7,0);
    ha["HST"]=Data(-10,0);ha["AKST"]=Data(-9,0);ha["AKDT"]=Data(-8,0);
    ha["AEST"]=Data(10,0);ha["AEDT"]=Data(11,0);ha["ACST"]=Data(9,30);
    ha["ACDT"]=Data(10,30);ha["AWST"]=Data(8,0);
    int T;
    for(scanf("%d",&T);T;T--)
    {
        char s[20],a[10],b[10];
        Zone x,y,utc;
        scanf(" %s",s);
        if(s[0]<='9')
        {
            scanf("%s%s%s",&x.s,a,b);
            sscanf(s,"%d:%d",&x.h,&x.m);
        }
        else
        {
            scanf("%s%s",a,b);
            x.h=12;x.m=0;
            if(s[0]=='n')
                strcpy(x.s,"p.m.");
            else
                strcpy(x.s,"a.m.");
        }
        utc=sub(x,ha[a]);
        y=sub(utc,Data(-ha[b].h,-ha[b].m));
        y.print();
    }
    return 0;
}




