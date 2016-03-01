//* @author:
import java.util.*;
public class Main{
 public static void main(String args[]){
    Scanner in=new Scanner(System.in);
    int t=0;
    while (in.hasNext())
   {
      int N=in.nextInt();
      if(N==0) break;
      int R=in.nextInt();
      int S[]=new int[R];
      int E[]=new int[R];
      for (int i = 0; i < R; i++)
      {
	 S[i]=in.nextInt();
        E[i]=in.nextInt();
       }
	System.out.printf("Genome %d\n", ++t);
	int Q=in.nextInt();
	while ((Q--)!=0)
	{
	  int p=in.nextInt();
	  for (int i = 0; i < R; i++)
         {
	    if (p >= S[i] && p <= E[i])
	    {
	       p = S[i] + E[i] - p;
	     }
	  }
	  System.out.printf("%d\n", p);
       }
     }
  }
}

