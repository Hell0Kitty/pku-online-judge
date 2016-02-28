/*高斯消元,然后根据消元后的矩阵得到答案,若有矛盾的行则无解

   否则解的个数为2^k   k为矩阵全为0的行数
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

class Gaus 
{
    int a[][],num;
    static int M=2;
    Gaus(int m[][],int n)
    {
    a=m;
    num=n;
    }
    
    int mod(int a) //对M求余
    {
    return (a%M+M)%M;
    }
    
    void swap(int x,int y) //交换a[x],a[y]
    {
    int temp[];
    temp=a[x];
    a[x]=a[y];
    a[y]=temp;
    }
    
    void change() //矩阵变换
    {
    int i,j,k,max;
    for(i=0;i<num-1;i++)
    {
       max=i;
       for(j=i+1;j<num;j++)
       {
        if(a[j][i]>a[max][i])
         max=j;
       }
       if(a[max][i]==0)continue;
       swap(i,max);
       for(j=i+1;j<num;j++)
       {
        if(a[j][i]==0)continue;
        for(k=i+1;k<=num;k++)
        {
         a[j][k]=mod(a[j][k]*a[i][i]-a[i][k]*a[j][i]);
        }
        a[j][i]=0;
       }
    }
    }
    
    int noUse()//返回全为0的行数,若有不成立的行返回-1
    {
    int count=0,i,j;
    boolean zero;
    for(i=num-1;i>=0;i--)
    {
       zero=true;
       for(j=0;j<num;j++)
       {
        if(a[i][j]!=0)
        {
         zero=false;
         break;
        }
       }
       if(zero)
       {
        if(a[i][num]!=0)return -1;
        count++;
       }
    }
    return count;
    }
}

public class Main {
static int value[];
static void init()
{
   value=new int[29];
   value[0]=1;
   for(int i=1;i<29;i++)
   {
    value[i]=2*value[i-1];
   }
}
    public static void main(String args[]) throws IOException
    {
    init();
    int a[][]=new int[28][29],t1,t2,t,n,i;
    int s1[]=new int[28];
    Gaus data;
    t=cin.nextInt();
    while((t--)>0)
    {
       n=cin.nextInt();
       for(i=0;i<n;i++)s1[i]=cin.nextInt();
       for(i=0;i<n;i++)
       {
        t1=cin.nextInt();
        Arrays.fill(a[i],0);
        a[i][i]=1;
        if(t1==s1[i])a[i][n]=0;
        else a[i][n]=1;
       }
       while(true)
       {
        t1=cin.nextInt();
        t2=cin.nextInt();
        if(t1==0&&t2==0)break;
        a[t2-1][t1-1]=1;
       }
       data=new Gaus(a,n);
       data.change();
       t1=data.noUse();
       if(t1<0)System.out.println("Oh,it's impossible~!!");
       else System.out.println(value[t1]);
    }
    
    }
}
