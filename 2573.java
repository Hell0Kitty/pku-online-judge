//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  ArrayList< Integer> t=new ArrayList< Integer>();
  for(int i=0;i< a;i++)
	t.add(in.nextInt());
  if(a==1){
	System.out.println(t.get(0));
	System.out.println(t.get(0));
  }
  else{
    int total=0;
    Collections.sort(t);
    ArrayList< Integer> t2=new ArrayList< Integer>();
    ArrayList< Integer> t3=new ArrayList< Integer>();
    int m1=t.get(0);
    int m2=t.get(1);
    int w=a;
    while(w>3)
    {
	total+=t.get(w-1)+m1+Math.min(m2*2,m1+t.get(w-2));
	if(m2*2>(m1+t.get(w-2)))
	{
		t2.add(m1);
		t2.add(t.get(w-2));
		t3.add(m1);
		t2.add(m1);
		t2.add(t.get(w-1));
		t3.add(m1);
	}
	else
	{
		t2.add(m1);
		t2.add(m2);
		t3.add(m1);
		t2.add(t.get(w-2));
		t2.add(t.get(w-1));
		t3.add(m2);
	}
	w-=2;
     }
    if(w==2){
	total+=m2;
	t2.add(m1);
	t2.add(m2);
     }
    else {
	total+=m1+m2+t.get(2);
	t2.add(m1);
	t2.add(m2);
	t3.add(m1);
	t2.add(m1);
	t2.add(t.get(2));

     }
     System.out.println(total);
     for(int i=0;i< a-2;i++)
     {
	System.out.println(t2.get(i*2)+" "+t2.get(i*2+1));
	System.out.println(t3.get(i));
     }
     System.out.println(t2.get(a*2-4)+" "+t2.get(a*2-3));
   }
 }
}

