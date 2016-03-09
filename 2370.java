//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt(),t=0,i;
  int[] b=new int[a];
  for(i=0;i< a;i++)
    b[i]=in.nextInt();
  a/=2;
  Arrays.sort(b);
  for(i=0;i<=a;i++)
    t+=b[i]/2+1;
  System.out.println(t);
 }
}

