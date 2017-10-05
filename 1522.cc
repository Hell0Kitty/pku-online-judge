#include<iostream>
#include<map>
#include<string.h>
#include<stdio.h>
using namespace std;

map<string,int> maps;
int fa[200];

int find(int number)
{   if(fa[number]==number) return number;
    else
    {  fa[number]=find(fa[number]);
       return fa[number];
    }
}

//实现字符串映射成数字，构造并查集，返回值是字符串path的编号
//形参path是待映射的字符串，count是已经使用的字符编号
int build(char path[],int& count)
{
    int index;
    if(maps.find(string(path))==maps.end()) //新的字符串
    {   maps[string(path)]=++count; //映射
        index=count;
        fa[count]=count; //并查集的一个根
    }
    else index=maps[string(path)];
    return index;
}

int main()
{
    int n;
    int number=1;
    while(scanf("%d",&n)&&n)
    {   int i,p;
        char starting[15],ending[15];
        for(i=0;i<n;i++)  //构造起点坐标的字符串
        {   scanf("%d",&p);
            starting[i]=p+'0';
        }
        starting[n]=0;
        for(i=0;i<n;i++) //构造结尾坐标的字符串
        {   scanf("%d",&p);
            ending[i]=p+'0';
        }
        ending[n]=0;
        int count=0;
        maps.clear();
        char path[15]; //一条相邻路径
        while(scanf("%d",&p))
        {   if(p==-1) break;
            int start,end;
            path[0]=p+'0';  //构造相邻路径起点坐标的字符串
            for(i=1;i<n;i++)
            {   scanf("%d",&p);
                path[i]=p+'0';
            }
            path[n]=0;
            start=build(path,count); //实现字符串映射成数字，构造并查集
            for(i=0;i<n;i++)
            {   scanf("%d",&p);
                path[i]=p+'0';
            }
            path[n]=0;
            end=build(path,count); //实现字符串映射成数字，构造并查集
            int h1=find(start);
            int h2=find(end);
            if(h1!=h2) fa[h1]=h2; //一个新的根节点
       }
       int possible=1;
       if(maps.find(string(starting))==maps.end()||maps.find(string(ending))==maps.end())
            possible=0;  //不在路径中
       else
       {    int start=maps[string(starting)];
            int end=maps[string(ending)];
            int h1=find(start);
            int h2=find(end);
            if(h1!=h2) possible=0;  //根节点不相同
       }
       if(possible) printf("Maze #%d can be travelled\n",number++);
       else printf("Maze #%d cannot be travelled\n",number++);
   }
return 0;
}


