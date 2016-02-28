import java.util.Scanner;
public class Main{
 public static void main(String args[]){
 Scanner sc=new Scanner(System.in);
 int a[]=new int[11];
 boolean flag=false;
 while(sc.hasNext())
 {
  flag=true;
  int n=sc.nextInt();
  if(n==0)
    break;
  for(int i=1;i<=n;i++)
   a[i]=sc.nextInt();
   if(n%2==1)
    {
      System.out.printf("1\n");
      continue;
    }//如果是奇数，则必然是第一个人赢
    for(int i=1;i<n&&flag;i++)
     {
      for(int j=i+1;j<=n&&flag;j++)
        if(a[i]!=0&&a[i]==a[j]){
         a[i]=0;
         a[j]=0;
         break;
        }
     
        if(a[i]!=0) flag=false;
     }//如果是偶数，则判断是否成双成对
    if(!flag)
      System.out.printf("1\n");
    else System.out.printf("0\n");
 }
}
}