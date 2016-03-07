import java.util.Scanner;
public class Main{
  public static void main(String args[]){
   long  n;
   int k,t;
   int ans[]=new int[65];
   char a[]=new char[66];
   Scanner sc=new Scanner(System.in);
   t=sc.nextInt();
   while((t--)!=0){
     k=sc.nextInt();
     a=sc.next().toCharArray();
    n=sc.nextLong();
   
    for(int i=0;i<k;i++){
     if((n&0x1)!=0){
      ans[k-1-i]=1;
      if(a[k-i-1]=='p')
       n=n-1;
      else n=n+1;
     }else
      ans[k-1-i]=0;
      n/=2;
     }
     if(n==0){
      for(int i=0;i<k;i++)
        System.out.printf("%d",ans[i]);
      System.out.printf("\n");
    }else System.out.printf("Impossible\n");
   }
  }
 }