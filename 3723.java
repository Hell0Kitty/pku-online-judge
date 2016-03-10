//Kruskal 算法:
import java.io.*;
import java.util.*;

class cin
{
static int leave=0;
static StringTokenizer st;
static BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
static int nextInt() throws Exception
{
    while (leave==0)
    {
     st=new StringTokenizer(in.readLine());
     leave=st.countTokens();
    }
    leave--;
    return Integer.parseInt(st.nextToken());
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
   father=new int[n];
   this.clear();
}

void clear()
{
   int i;
   for(i=0;i< num;i++)father[i]=i;
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
   int sum=0,f1,f2;
   Arrays.sort(e,new Cmp());
   for(i=0;i< numOfE;i++)
   {
    if(points.num==1)break;
    if(points.union(e[i].from,e[i].to))
    {
     sum+=e[i].weight;
    }
   }
   return sum+10000*points.num;
}

}
public class Main {
    public static void main(String args[]) throws Exception
    {
    int g,b,r,t,i;
    E e[];
    t=cin.nextInt();
    Kruskal data;
    while((t--)>0)
    {
       g=cin.nextInt();
       b=cin.nextInt();
       r=cin.nextInt();
       e=new E[r];
       for(i=0;i< r;i++)
       {
        e[i]=new E();
        e[i].init(cin.nextInt(),cin.nextInt()+g,10000-cin.nextInt());
       }
       data=new Kruskal(e,r,g+b);
       System.out.println(data.cost());
    }
    }
}

