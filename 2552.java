import java.util.*;
public class Main
{
 public static void main(String[] args)
  {
   ArrayList< Integer> a=new ArrayList< Integer>();
   for(int i=2;i< 35000;i++)
	 a.add(i);
   int count=0;
   while(count< a.size())
    {
	 for(int i=count+a.get(count);i< a.size();i+=a.get(count))
		 a.set(i, 0);
	 for(int i=0;i< a.size();i++)
		 if(a.get(i)==0){
			 a.remove(i);
		 }
	 count++;
    }
    Scanner in=new Scanner(System.in);
    while(true)
    {
	int w=in.nextInt();
	if(w==0) break;
	System.out.println(a.get(w-1));
    }
 }
}

