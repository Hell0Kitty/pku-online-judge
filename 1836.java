import java.util.Scanner;
public class Main{
   private int n;
   private double a[];
   int b[],c[],sum[];
   
   public Main(int n,double a[]){
    this.n=n;
    this.a=a;
    b=new int[n+1];
    c=new int[n+1];
    sum=new int[n+1];
  }

   public static void main(String args[]){
     Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      double a[]=new double[n+1];
      for(int i=1;i<=n;i++){
        a[i]=sc.nextDouble();//下标从1开始
   
       }
      Main ma=new Main(n,a);
     // ma.showB();
      //ma.showC();
      System.out.println(ma.doIt());
      
  }

   private void showB(){
     for(int i=1;i<=n;i++){
        System.out.println(b[i]+"  ");
     }
    }

   private void showC(){
     for(int i=1;i<=n;i++){
        System.out.println(c[i]+"  ");
     }
   }
  
   private void lis(){//a[]的前i个元素中，最长递增子序列的长度为b[i]
    b[1] = 1;
    for (int i=2;i<=n;i++)
    {
        int max = 0;
        for (int j=1;j<i;j++)
        {
            if (a[j]<a[i] && b[j]>max)
            {
                 max = b[j];
            }
        }
        b[i] = max + 1;
    } 
  // showB();
}

private void flis()//a[]的从后向前的n-i+1元素中，最长递增子序列的长度为c[i]
{
     c[n] = 1;
    for (int i=n-1;i>=1;i--)
    {
        int max = 0;
        
        for (int j=n;j>i;j--)
        {
            if (a[j]<a[i] && c[j]>max)
            {
                max = c[j];
            }
        }
        c[i] = max + 1;
    }
}

 

  private int doIt(){
    lis();
    flis();
    int min=n;
   for(int i=1;i<=n;i++){
      for (int j = i + 1; j <= n; j++) {//最高点可以有两个,如果a[i]后面有与自己等高的人
            if (a[i] == a[j]){
              if(c[i]<=c[j])
                c[i]=c[j]+1;
            }
        }

      sum[i]=n-(b[i]+c[i]-1);
      if(sum[i]<min){
           min=sum[i];
      }
   }
  return min;
 }

}
