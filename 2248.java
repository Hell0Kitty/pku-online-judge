import java.util.Scanner;
public class Main{
  static int arr[]=new int[20];
  static int n,minn;
  static int save[]=new int[20];

 static void bfs(int a)
{
   int i,j;
   if(a>=minn)return;
   if(arr[a-1]==n)
   {
     if(a< minn){
    minn=a;
    for(i=0;i< a;i++)
      save[i]=arr[i];
     }
     return;
    }
    for(i=a-1;i>=0;i--)
    {
    for(j=i;j>=0;j--)
    {
       if(arr[i]+arr[j]>n)continue;
       if(arr[i]+arr[j]<=arr[a-1])continue;
       arr[a]=arr[i]+arr[j];
       if(a==minn-2&&arr[a]< n)break;
       bfs(a+1);
    }
    if(j!=0)break;
    }
}

 public static void main(String args[])
{
      Scanner sc=new Scanner(System.in);
    while(sc.hasNext())
    {
        n=sc.nextInt();
        if(n==0) break;
     minn=11;
     arr[0]=1;
     bfs(1);
     for(int k=0;k< minn-1;k++)
      System.out.printf("%d ",save[k]);
    System.out.printf("%d\n",save[minn-1]);
    }
  }
}

