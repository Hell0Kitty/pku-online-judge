import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(true)
   {
    int n=in.nextInt();
    if(n==0)break;
    int i,j,m=1;
    while(true)
    {
          i=0;
      j=n-1;
      while(j!=0)
       {
        i=(i+m-1)%j;
        j--;
        if(i==0) break;
       }
      if(j==0)
       {
        System.out.println(m);
        break;
       }
       m++;
    }
    }
  }
}

