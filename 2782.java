//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  int b=in.nextInt();
  ArrayList< Integer> t=new ArrayList< Integer>();
  while((a--)!=0)
	t.add(in.nextInt());
  Collections.sort(t);
  int count=0;
  int u=t.size()-1;
  int k=0;
  while(k<=u)
  {
	int q=b;
	q-=t.get(u--);
	if(q>=t.get(k))
		k++;
	count++;
   }
  System.out.println(count);
 }
}

