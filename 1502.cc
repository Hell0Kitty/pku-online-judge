#include <iostream>
using namespace std;
#include <string.h>
#include <stdio.h>
const int size = 110;
#define maxint 999999
class poj1502
{
   private:
     int map[size][size];
   public:
    int n;
    void input();
    void Foldy(); 
};
int translate(char str[])
{
 int sum=0,k,len;
 if(str[0]=='x')
 return -1;
 else
 {
  len=strlen(str);
  for(k=0;k<len;k++)
  sum=sum*10+(str[k]-'0');
 }
 return sum;
}
void poj1502::input()
{
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      map[i][j]=maxint;
    }
    map[i][i]=0;
  }
  char str[20];
  int weight;
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<i;j++)
    {
      scanf("%s",str);
      weight=translate(str);
      if(-1==weight)
      {
           map[i][j]=maxint;
           map[j][i]=map[i][j];
      }
      else
      {
       map[i][j]=weight;
       map[j][i]=map[i][j];
      }
    }
  }
}
void poj1502::Foldy()
{
  for(int k=1;k<=n;k++)
  {
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
      {
        map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
      }
    }
  }
  int min=0;
  for(int k=2;k<=n;k++)
  if(map[1][k]>min)
  min=map[1][k];
  cout<<min<<endl;
}
int main()
{
 poj1502 t;
 while(scanf("%d",&t.n)!=EOF)
 {
        t.input();
        t.Foldy();
 }
 return 1;
}
