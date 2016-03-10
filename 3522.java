import java.io.*;
import java.util.*;
/*求生成树的最大权值与最小权值的最小差:
 *基本思想:先对边排序. 若其在相邻的一组边能生成树,记录最大权值与最小权值的最小差,枚举所有情况
 *如何保证这样求出的是最优解呢,因为边已经按权值进行排序,相邻的一组边生成的树必然是最小的(上界和下界之差最小)
 */
class cin
{
static BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
static int a,c;
static int nextInt() throws IOException
{
   c=in.read();
   a=0;
   while(c==' '||c=='\r'||c=='\n')c=in.read();
   while(c!=' '&&c!='\r'&&c!='\n')
   {
    a=a*10+c-'0';
    c=in.read();
   }
   return a;
}
}

class E
{
int weight,from,to;
void init(int x,int y,int z)
{
   weight=z;
   from=x;
   to=y;
}
}

class Cmp implements Comparator
{
public int compare(Object a,Object b)
{
   int c=((E)a).weight-((E)b).weight;
   if(c< 0)return -1;
   return 1;
}
}

class Set
{
int father[];
int num;
Set(int n)
{
   num=n;
   father=new int[n+1];
   this.clear();
}

void clear()
{
   int i;
   num=father.length-1;
   for(i=1;i<=num;i++)father[i]=i;
}

int findF(int x)
{
   int t=x;
   while(t!=father[t])
   {
    t=father[t];
   }
   while(x!=father[x])
   {
    father[x]=t;
    x=father[x];
   }
   return t;
}

boolean union(int x,int y)
{
   int fx=findF(x),fy=findF(y);
   if(fx==fy)return false;
   father[fy]=fx;
   num--;
   return true;
}
}

class Kruskal
{
E e[];
int numOfE,numOfTree,i,j,numOfD;
Set points;

Kruskal(E a[],int m,int n)
{
   e=a;
   numOfE=m;
   numOfD=n;
   points=new Set(numOfD);
}

int cost()
{
   int dis=100000,h,k=0;
   Arrays.sort(e,new Cmp());
   for(i=0;i< numOfE;i++)    //主要部分代码
   {
    if(points.union(e[i].from,e[i].to))
    {
     if(points.num==1)   //生成一棵树
     {
      k++;
      while(true)
      {
       points.clear();
       for(h=k;h<=i;h++)
       {
        points.union(e[h].from, e[h].to);
       }
       if(points.num==1)k++; //去掉不必要的边
       else break;
      }
      if(dis>e[i].weight-e[k-1].weight) //计算并保留最小差值
       dis=e[i].weight-e[k-1].weight;
     }
    }
   }
   if(dis==100000)dis=-1;
   return dis;
}

}

public class Main {
    public static void main(String args[]) throws IOException
    {
    int n,m,i;
    E e[];
    while(true)
    {
       n=cin.nextInt();
       m=cin.nextInt();
       if(n==0&&m==0)break;
       e=new E[m];
       for(i=0;i< m;i++)
       {
        e[i]=new E();
        e[i].init(cin.nextInt(), cin.nextInt(), cin.nextInt());
       }
       Kruskal data=new Kruskal(e,m,n);
       System.out.println(data.cost());
    }
    }
 }

