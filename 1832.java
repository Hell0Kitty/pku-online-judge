/*
对于一个状态可认为它是从一个都没有的时候转化而来的,其步数为

第一个"1"处的权值 - 第2个"1"处的权值 + 第3个"1"处的权值 - 第4个"1"处的权值 +......(从左到右算)

     即第2*k+1个"1"时是加,第2*k个"1"是减,

而某一位的权值为2^(i+1)-1,(i从右到左,从0开始算)

      所以两种状态转化最小步数为两种状态步数差的绝对值,如:


s1     1   0    0    0
s2    0    1    1    0
权值:15   7    3    1

sum1=15

sum2=7-3=4

所以最终结果为|4-15|=11

    因为n<128,所以要用高精度
*/




import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class cin
{
static BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
static StringTokenizer st;
static int leave=0;
static int nextInt()throws IOException
{
   return Integer.parseInt(next());
}
static String nextLine()throws IOException
{
   return in.readLine();
}
static String next() throws IOException
{
   while(leave==0)
   {
    st=new StringTokenizer(in.readLine());
    leave=st.countTokens();
   }
   leave--;
   return st.nextToken();
}
static boolean hasNext() throws IOException
{
   while(leave==0)
   {
    String temp=in.readLine();
    if(temp==null)return false;
    st=new StringTokenizer(temp);
    leave=st.countTokens();
   }
   return true;
}
}

class MyBigInt   //大整数类
{
    static int num,VALUE=1000000000;
    int data[];
    static void init(int n)
    {
    num=n;
    }
    
    MyBigInt(int x)
    {
    data=new int[num];
    Arrays.fill(data,0);
    data[num-1]=x%VALUE;
        data[num-2]=x/VALUE;
    }
    
    MyBigInt add(MyBigInt a) //+
    {
    int i,c=0,t;
    MyBigInt sum=new MyBigInt(0);
    for(i=num-1;i>=0;i--)
    {
       t=data[i]+a.data[i]+c;
       sum.data[i]=(t)%VALUE;
       c=t/VALUE;
    }
    return sum;
    }
    
    MyBigInt sub(MyBigInt a) //大数-小数
    {
    int i,c=0,t;
    MyBigInt s=new MyBigInt(0);
    for(i=num-1;i>=0;i--)
    {
       t=data[i]-a.data[i]+c;
       if(t<0)
       {
        t+=VALUE;
        c=-1;
       }
       else c=0;
       s.data[i]=t;
    }
    return s;
    }
    
    boolean bigThan(MyBigInt a)
    {
    int i=0;
    for(i=0;i<num;i++)
    {
         if(data[i]>a.data[i])return true;
         else if(data[i]<a.data[i])return false;
    }
    return true;
    }
    
    void print()
    {
    int i;
    boolean ok=false;
    for(i=0;i<num;i++)
    {
       if(ok)
       {
        System.out.printf("%09d",data[i]);
       }
       else if(data[i]>0)
       {
        ok=true;
        System.out.print(data[i]);
        continue;
       }
    }
    if(!ok)System.out.print("0");
    }
}

class Answer
{
String s1,s2;
static MyBigInt v[];
static void init()
{
   MyBigInt.init(5);
   v=new MyBigInt[128];
   int i;
   v[0]=new MyBigInt(1);
   for(i=1;i<128;i++)
   {
    v[i]=v[i-1].add(v[i-1]).add(v[0]);
//    v[i].print();
//    System.out.println();
   }
}

Answer(String a,String b)
{
   s1=a;
   s2=b;
}

void out()
{
   MyBigInt v1=valueOf(s1),v2=valueOf(s2);
//   v1.print();
//   v2.print();
   if(!v1.bigThan(v2))
   {
    v2.sub(v1).print();
   }
   else v1.sub(v2).print();
   System.out.println();
}

MyBigInt valueOf(String s)
{
   int i=0,k=s.length();
   MyBigInt value=new MyBigInt(0);
   while(i<s.length())
   {
    while(i<s.length()&&s.charAt(i)!='1')
    {
     i+=2;
    }
    if(i<s.length())value=value.add(v[(k-i)/2]);
    i+=2;
    while(i<s.length()&&s.charAt(i)!='1')
    {
     i+=2;
    }
    if(i<s.length())value=value.sub(v[(k-i)/2]);
    i+=2;
   }
   return value;
}
}

public class Main 
{
    public static void main(String args[]) throws IOException
    {
    int t;
    Answer.init();
    Answer data;
    t=cin.nextInt();
    while((t--)>0)
    {
       cin.nextInt();
       data=new Answer(cin.nextLine(),cin.nextLine());
       data.out();
    }
    }
}
