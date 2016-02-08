#include<stdio.h>
#include<string.h>
#define eps 1e8
int mat[25][25],levi[25],levj[25];
int n,visi[25],visj[25],mari[25],marj[25],value,test;
int dfs(int i)
{
    visi[i]=1;
    int j;
    for(j=0;j<n;j++)
    if(0==visj[j]&&mat[i][j]==levi[i]+levj[j])
    {
        visj[j]=1;
        if(marj[j]==-1||dfs(marj[j]))
        {
            marj[j]=i;
            mari[i]=j;
            return 1;
        }
    }
    return 0;
}
void KM()
{
    int i,j,ki,min;
    for(i=0;i<n;i++)
    {
        levi[i]=-eps;
      for(j=0;j<n;j++)
       levi[i]=levi[i]>mat[i][j]?levi[i]:mat[i][j];
    }
    memset(levj,0,sizeof(levj));
    memset(mari,-1,sizeof(mari));
    memset(marj,-1,sizeof(marj));
    for(i=0;i<n;i++)
    while(1)
    {
        memset(visi,0,sizeof(visi));
        memset(visj,0,sizeof(visj));
        if(dfs(i))break;min=eps;
        for(ki=0;ki<n;ki++)
        if(visi[ki])
          for(j=0;j<n;j++)
          if(0==visj[j]&&min>levi[ki]+levj[j]-mat[ki][j])
          min=levi[ki]+levj[j]-mat[ki][j];
         for(ki=0;ki<n;ki++)
         {
             if(visi[ki])levi[ki]-=min;
             if(visj[ki])levj[ki]+=min;
         }
    }
    value=0;
    for(i=0;i<n;i++)
       value-=mat[i][mari[i]];
}
void dfs2(int pos,int para)
{
    if(para>value)return;
    if(pos>=n)
    {
        if(para!=value)return;
        printf("Best Pairing %d\n",test++);
        for(int i=0;i<n;i++)
        printf("Supervisor %d with Employee %d\n",i+1,mari[i]+1);
    }
    else
    {
        for(int j=0;j<n;j++)
        if(visj[j]==0)
        {
            visj[j]=1;
            mari[pos]=j;
            dfs2(pos+1,para-mat[pos][j]);
            visj[j]=0;
        }
    }
}
int main()
{
    int i,j,T,man,I=1;
    scanf("%d",&T);
    while(T--)
    {
        if(I!=1)printf("\n");
        scanf("%d",&n);
        memset(mat,0,sizeof(mat));
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
             scanf("%d",&man);
             man--;
             mat[man][i]-=j;
          }
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
          {
              scanf("%d",&man);
              man--;
              mat[i][man]-=j;
          }
          KM();
          printf("Data Set %d, Best average difference: %.6f\n",I++,value*0.5/n);
          memset(visj,0,sizeof(visj));test=1;
          dfs2(0,0);
          }
    return 0;
}



