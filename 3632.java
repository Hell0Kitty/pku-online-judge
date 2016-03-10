//* @author: 82638882@163.com
import java.util.Scanner;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  while(a!=0)
  {
    int b=in.nextInt();
    int[] c=new int[b];
    for(int i=0;i< b;i++)
    {
        c[i]=in.nextInt();
    }
    int d,e,g;
    for(d=e=c[0],g=0;g< b;g++)
    {
        if(d>c[g])d=c[g];
        if(e< c[g])e=c[g];
    }
    System.out.println((e-d)*2);
    a--;
    }
  }
}

