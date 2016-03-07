import java.util.*;
 public class Main {
 
       
static int target,l;
static char num[]=new char[6];
static int max;
static int tp[]=new int[6],ans[]=new int[6],ansnum,ansptr;

static void dfs(int startIndex,int sumTotal,int ptr)
{
  int i,t=0;
  if(startIndex==l)
  {
    if(sumTotal==max)
      ansptr=-1;
    else
      if(sumTotal>max)
      {
        ansptr=1;
        max=sumTotal;
        for(i=0;i<ptr;i++)
          ans[i]=tp[i];
        ansnum=ptr;
      }
    return;
  }
  for(i=1;i<l-startIndex+1;i++)
  {
    t*=10;
    t+=num[startIndex+i-1]-'0';
    if(t+sumTotal>target)
      return;
    tp[ptr]=startIndex+i-1;
    dfs(startIndex+i,sumTotal+t,ptr+1);
  }
}



public static void main(String args[]){
    
    Scanner sc=new Scanner(System.in);
   
  int i,j,k;
  while(sc.hasNext())
  {
   target=sc.nextInt();
   num=sc.next().toCharArray();
    if(target==0)
      break;

    l=num.length;
    ansptr=0;
    max=0;
    dfs(0,0,0);
    if(ansptr==0)
      System.out.printf("error\n");
    else
      if(ansptr==-1)
        System.out.printf("rejected\n");
      else
      {
        System.out.printf("%d ",max);
        for(i=0,j=0;j<ansnum-1;i++)
        {
          System.out.printf("%c",num[i]);
          if(ans[j]==i)
          {
            System.out.printf(" ");
            j++;
          }
        }
        for(;i<l;i++)
          System.out.printf("%c",num[i]);
        System.out.printf("\n");
      }
  }
 }
}
