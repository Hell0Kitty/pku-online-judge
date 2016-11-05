#include<iostream>
#include<vector>
using namespace std;
struct point{
 int p,n,m;
 char ch;
}list[2000];
bool sign[2000];
vector<char>end;
int n,k,m,n1,h,r;
int bfs()
{
    point temp;
 h=0; r=1;
 list[0].n=(n+k*1000)%k;
 list[0].m=(n+m*1000)%m;
 list[0].p=0;
 list[0].ch=0;
 while(r>h)    
 {
  temp=list[h];
  if(temp.n==n1&& h)  
   return 1;
  temp.n=(temp.n+m)%k; //+
  if(sign[temp.n]==0)
  {
   sign[temp.n]=1;
   temp.ch='+';
   temp.p=h;
   list[r++]=temp;
  }
  temp=list[h];
  temp.n=(temp.n-m+k*1000)%k;//-
  if(sign[temp.n]==0)
  {
   sign[temp.n]=1;
   temp.ch='-';
   temp.p=h;
   list[r++]=temp;
  }
  temp=list[h];
  temp.n=(temp.n*m)%k;//*
  if(sign[temp.n]==0)
  {
   sign[temp.n]=1;
   temp.ch='*';
   temp.m=temp.m*m%m;//娉ㄦ剰杩欏彞,濡傛灉娌℃湁绛変綘涓嬫鎵ц%鏃讹紝灏变細鍑虹幇 (*m%k) %m杩欐牱鐨勯敊璇簡
   temp.p=h;
   list[r++]=temp;
  }
  temp=list[h];
  temp.n=temp.m%k;//%
  if(sign[temp.n]==0)
  {
   sign[temp.n]=1;
   temp.ch='%';
   temp.p=h;
   list[r++]=temp;
  }
  ++h;
 }//while
 return 0;
}
int main()
{
 char s;
 int i;
   while(cin>>n>>k>>m)
   {
    if(k!=0 && m!=0)
    {
    memset(sign,0,sizeof(sign));
    end.clear();
    n1=(n+1+k*1000)%k;
    if(bfs())    
    {
     while(h)
     {
      s=list[h].ch;
      end.push_back(s);
      h=list[h].p;
     }
     cout<<end.size()<<endl;
     for(i=end.size()-1;i>=0;i--)
      cout<<end[i];
     cout<<endl;
    }
    else
     cout<<0<<endl;
    }
    else break;
   }
   return 0;
}


