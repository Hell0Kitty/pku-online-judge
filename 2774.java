import java.io.*;
/**
 * coded by huangjinyc
 */


/*
 *  我的height,rank,SA的值都是从0开始计算的，排名最前的为0；SA中的直接指代字符的位置，第一个字符为0，依次计算
 *  Height也是从名次0开始计算；
 */

class Suffix {
final static int BUK_SIZE=201000;
final static int STRLEN=201000;
static int  Buket[]=new int[BUK_SIZE]; //桶排序的桶子
 char[] ch;
static int SA[]=new int[STRLEN]; //记录后缀数组
static int SA1[]=new int[STRLEN]; //在基数排序的时候的暂存中间状态的SA，两次基数排序之间。
static int Rank[]=new int[STRLEN]; //记录名次数组
static int Rank1[]=new int[STRLEN]; //用来记录上一轮的rank排名，因为i+1轮的rank要根据i轮的rank来重新排名
static int Height[]=new int[STRLEN];  //height不用讲了
 public Suffix(String s ) //初始化
 {
  ch=s.toCharArray();
 }
 public int Compare(int i,int j,int factor)
 {
 if(Rank[i]!=Rank[j])
  return (Rank[j]-Rank[i]);
 else
  return (Rank[j+factor]-Rank[i+factor]);

 }
 public void CreateSA()
 {


  for(int i=0;i<=256;i++)  //对刚开始的时候字符串进行基数排序，得到我们的SA和Rank初始值
  {
   Buket[i]=0;
  }
  for(int i=0;i< ch.length;i++)
  {
   Buket[ch[i]]++;
  }
  for(int i=1;i<=256;i++)
  {
   Buket[i]+=Buket[i-1];
  }
  for(int i=ch.length-1;i>=0;i--)
  {
   SA[--Buket[ch[i]]]=i;
  }
   for(int i=0;i< ch.length;i++)
   {
    Rank[i]=0;
   }
  Rank[SA[0]]=0;
   for(int i=1;i< ch.length;i++)
   {
     Rank[SA[i]]=Rank[SA[i-1]];  //根据基排序的结果依次排名
        if(ch[SA[i]]!=ch[SA[i-1]])
        {
    Rank[SA[i]]++;
     }
   }
  int factor=1;
  while(factor< ch.length)  //factor是步长，倍增算法的因子，factor*=2
  {


   //第一轮基排序，对键值2排序
   for(int i=0;i< BUK_SIZE;i++)
   {
    Buket[i]=0;
   }
   for(int i=0;i< ch.length;i++)
   {
    if(SA[i]+factor< ch.length) //如果key2没有超出去字符串则直接将key的rank进行桶排序
    {
     Buket[Rank[SA[i]+factor]]++;
    }
   else  //超出，则给桶的0号增加1，说明key2是最小的
    {
     Buket[0]++;
    }
   }
   for(int i=1;i< ch.length;i++)
   {
    Buket[i]+=Buket[i-1];
   }
   for(int i=ch.length-1;i>=0;i--)
   {
    if(SA[i]+factor< ch.length){  //同上，将中间状态保存在SA1中
     SA1[--Buket[Rank[SA[i]+factor]]]=SA[i];
    }else{
     SA1[--Buket[0]]=SA[i];
    }
   }

   ///第二轮基排序
   for(int i=0;i< ch.length;i++)
   {
    Buket[i]=0;
   }
   for(int i=0;i< ch.length;i++)
   {
       Buket[Rank[SA1[i]]]++;
   }
   for(int i=1;i< ch.length;i++)
   {
    Buket[i]+=Buket[i-1];
   }
   for(int i=ch.length-1;i>=0;i--) //利用SA1得到我们的SA
   {
    SA[--Buket[Rank[SA1[i]]]]=SA1[i];
   }

  int j=0;//排在第一的名次设置为0，相同key1,key2则名次是一样的
   for(int i=1;i< ch.length;i++)
   {
     //根据基排序的结果依次排名，如果SA[i]和SA[i-1]所指位置开始向后移动s*factor-1都相等，
	 //则直接rank[SA[i]]=rank[SA[i-1]],否则加1
        if(Compare(SA[i],SA[i-1],factor)!=0)
        {
    j++;
     }
        Rank1[SA[i]]=j;
   }
   for(int i=0;i< ch.length;i++)
   //Rank1推出Rank,之所以要给出Rank1，是因为我们的Compare用到了Rank，
   //如果Compare中不用rank，顺序比较字符串的话也就可以不要Rank1
   {
    Rank[i]=Rank1[i];
   }
   factor*=2;
  }
  for(int i=0;i< ch.length;i++) //根据rank推出SA
  {
   SA[Rank[i]]=i;
  }


 }

 void CalculateHeightFast()  //根据h[i]>=h[i-1]-1,即height[rank[i]]>=height[rank[i-1]]-1,几乎是线性的算法
 {
    for(int i=0;i< Height.length;i++)
    {
     Height[i]=0;
    }
    int j=0;
    for(int i=0,k=0;i< ch.length;i++)
    {
     if(Rank[i]==0)
     {
      continue;
     }
     for(j=SA[Rank[i]-1];(i+k< ch.length&&j+k< ch.length)&&ch[i+k]==ch[j+k];)//利用K直接跳，不用从头开始进行
     {
      k++;
     }
     Height[Rank[i]]=k;
     if(k>0)  //这里减一就是为了下一轮的height[rank[i]]>=height[rank[i-1]]-1做准备，为0就不减了
      k--;
    }
 }
}
public class Main {

 public static void main(String[] args)throws Exception{
  // TODO Auto-generated method stub
  BufferedReader in =
   new BufferedReader(
   new InputStreamReader(System.in));
    String s1=in.readLine();
    String s2=in.readLine();
     String s=s1+"$"+s2;
 //如字符串 abba  和 bab 应该只输出2的，如果不加”$"则输出3，所以在s1和s2中间添加一个最小的不出现的字符，如'$'
        int len1=s1.length();
        int len2=s.length();
        Suffix t=new Suffix(s);
   t.CreateSA();
   t.CalculateHeightFast();
   int b=0;
   for(int i=1;i< len2;i++)
   {
        if((t.SA[i]< len1&&t.SA[i-1]>=len1)||(t.SA[i]>=len1&&t.SA[i-1]< len1))
        {
     if(t.Height[i]>b)
       b=t.Height[i];
        }

   }

   System.out.println(b);

 }

}

