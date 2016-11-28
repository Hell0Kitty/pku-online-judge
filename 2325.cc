#include <stdio.h>
#include <string.h>
#include <stack>
#include <deque>
#include <queue>
#include <limits.h>
#include <time.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>
using namespace std;
template <class R> string R__MonthName(R name){string mon[15];mon[1]="January";mon[2]="February";mon[3]="March";mon[4]="April";mon[5]="May";mon[6]="June";mon[7]="July";mon[8]="August";mon[9]="September";mon[10]="October";mon[11]="November";mon[12]="December";return mon[name];}
template <class R> R R__MonthDay(R num){R month[13];month[1]=31;month[2]=28;month[3]=31;month[4]=30;month[5]=31;month[6]=30;month[7]=31;month[8]=31;month[9]=30;month[10]=31;month[11]=30;month[12]=31;return month[num];}
template <class R> R R__GCD(R a,R b){if(b==0) return a;else return R__GCD(b,a%b);}
template <class R> R R__LCM(R a,R b){return (a*b)/R__GCD(a,b);}
template <class R> R R__POW( R a, R b){if(b==0) return 1; R x=a;for(R i=2;i<=b;i++) a=a*x;return a;}
template <class R> R R__BigMod(R a,R b,R c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){R x=R__BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*R__BigMod(a,b-1,c)%c)%c;}
template <class R> R R__Factorial(R a){R b=1;for(R i=1;i<=a;i++)b=b*i;return b;}
template <class R> R R__BinarySearch(R a[],R l,R h,R n){while(l<=h){R m=(l+h)/2;if(n<a[m])h=m-1;else if(n>a[m])l=m+1;else return m;} return -1;}
char arr[10000];
int div(int m)
{
    char x[10000]={NULL};
    int num=0,f=0,i=0,j=0;
    while(arr[i]!=NULL)
    {
        num=num*10+arr[i]-48;
        if(num>=m)
        {
            int di=num/m;
            num=num%m;
            x[j]=di+48;f=1;j++;
        }
        else if(f==1)
        {
            x[j]=48;j++;
        }
        i++;
    }
    if(num==0) {strcpy(arr,x);return 0;}
    else return 1;
}
int main()
{
    while(scanf("%s",&arr))
    {
        if(arr[0]=='-'&&arr[1]=='1') break;
        if(arr[1]==NULL)
        {
            cout<<"1"<<arr<<"\n";continue;
        }
        string C;
        for(int i=9;i>1;i--)
        {
            while(div(i)==0)
            {
                char a=i+48;
                C=C+a;
            }
        }
        sort(C.begin(),C.end());

       if(arr[0]=='1'&&arr[1]==NULL) cout<<C<<"\n";else cout<<"There is no such number.\n";
    }
    return 0;
}



