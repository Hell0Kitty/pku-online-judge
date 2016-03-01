import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(in.hasNext())
  {
	int a=in.nextInt();
	int b=in.nextInt();
	if(a==1)System.out.println(b);
	else{
	 ArrayList< Integer> arr=new ArrayList< Integer>();
	 for(int i=1;i< a;i++)
	 {
	  int m=a,n=i;
	  while(m%n!=0)
	   {
		int w=m;
		m=n;
		n=w%n;
	   }
	  if(n==1) arr.add(i);
	  }
	   int c=arr.size();
	   int k=b/c;
	   int u=b%c;
	   if(u==0){
	    u=c;
	    k-=1;
	   }
	System.out.println(a*k+arr.get(u-1));
	}
    }
  }
}

