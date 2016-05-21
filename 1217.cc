# include <cstdio>
# include <cstring>
# include <iostream>
# include <map>
using namespace std;
# define encode(a,b) (((a)<<6)|(b))
# define getp1(a) ((a)>>6)
# define getp2(a) ((a)&63)
int main()
{
     double res[21][2];
     //p[i][j]，A得到i-1分，B得到j-1分的概率，以后为了处理方便，可以将得-1,0,1,2分看作得0,1,2,3分
     double p[4][4]={{0,0,0,1.0/16},{1.0/16,3.0/8,1.0/8,0},{1.0/8,3.0/16,0,0},{1.0/16,0,0,0}};
     memset(res,0,sizeof(res));
     map<int,double> table[21];
     table[0][encode(0,0)]=1.0;//边界情况：A得0分，B得0分的概率为1
     for(int step=1;step<=21;step++)
     {
         for(map<int,double>::iterator ita=table[step-1].begin();ita!=table[step-1].end();ita++)
         {
             int p1=getp1(ita->first),p2=getp2(ita->first);
             if(step!=21)
             {

                 for(int i=0;i<4;i++)
                     for(int j=0;j<4;j++)
                         table[step][encode(p1+i,p2+j)]+=(ita->second)*p[i][j];//状态转移
             }
             if(p1<p2)//累加A输给B的概率
                 res[step-1][0]+=ita->second;
             else if(p1==p2)//累加打平的概率
                 res[step-1][1]+=ita->second;
         }
     }
     printf("Round   A wins    B wins    Tie\n");
     for(int i=1;i<=20;i++)//输出格式注意,如果需要在printf内输出%的话要用%%
         printf("%5d%10.4f%%%9.4f%%%9.4f%%\n",i,(1-res[i][0]-res[i][1])*100,res[i][0]*100,res[i][1]*100);
     return 0;
 }


