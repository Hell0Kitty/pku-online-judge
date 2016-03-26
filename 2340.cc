# include <cstdio>
# include <cstring>
# include <queue>
# include <cstdlib>
# include <vector>
using namespace std;
priority_queue<int,vector<int>,greater<int> > refer;
struct node
{
    int t,num;
    char op;
};
vector<node> data;
int main()
{
    char str[100];
    for(int i=1;i<=30000;i++)
       refer.push(i);
    int c[30001];
    memset(c,0,sizeof(c));
    while(gets(str))
    {
       node tmp;
       tmp.t=atoi(strtok(str," "));
       tmp.op=*strtok(NULL," ");
       if(tmp.op=='.')
          tmp.num=atoi(strtok(NULL," "));
       data.push_back(tmp);
    }
    int now=0,last=0;
    for(now=0;now<data.size();now++)
    {
       while(data[now].t-data[last].t>=600)
       {
            if(c[data[last].num]&&data[now].t-c[data[last].num]>=600)
            {
                refer.push(data[last].num);
                c[data[last].num]=0;
            }
            last++;
       }
       switch(data[now].op)
       {
           case '+':
              c[refer.top()]=data[now].t;
              printf("%d\n",refer.top());
              data[now].num=refer.top();
              refer.pop();
              break;
           case '.':
              if(c[data[now].num])
              {
                 printf("+\n");
                 c[data[now].num]=data[now].t;
              }
              else
                 printf("-\n");
              break;
       };

    }
    return 0;
}



