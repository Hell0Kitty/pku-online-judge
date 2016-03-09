import java.util.Scanner;
public class Main{
 public static void main(String args[]){

  int n,m;
  int i,j,k,sum;
  Scanner sc=new Scanner(System.in);
    while(true)    {
       n=sc.nextInt();
       m=sc.nextInt();

          if(n==-1&&m==-1)break;
          sum=0;
          for(i=n;i>=1;i--)
          {
              sum+=(n-i);
              if(sum>=m)break;
              }
          for(j=1;j< i;j++) System.out.printf("%d ",j);
          k=m+i-(n-i)*(n-i-1)/2;

          System.out.printf("%d",k);

          for(j=n;j>=i;j--) if(j!=k) System.out.printf(" %d",j);
          System.out.printf("\n");
     }
    }
}




}

