import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
	Scanner in=new Scanner(System.in);
	int n=in.nextInt();
	String[] ss1=new String[n];
	String[] ss2=new String[n];
	int[] p=new int[n];
	in.nextLine();
	for(int i=0;i< n;i++)
	{
	  ss1[i]=in.nextLine();
	  ss2[i]=in.nextLine();
	}
	int m=in.nextInt();
	in.nextLine();
	String s;
	for(int i=0;i< m;i++)
	{
	   s=in.nextLine();
	   for(int j=0;j< n;j++)
	   {
	     if(s.equals(ss1[j]))
		{
		   p[j]++;
		   break;
	 	}
	   }
	}
	int max=0,tag=-1;;
	boolean bb=false;
	for(int i=0;i< n;i++)
	{
	   if(p[i]>max){
		max=p[i];
		bb=false;
		tag=i;
	    }
	    else if(p[i]==max)bb=true;
	}
	if(bb) System.out.println("tie");
	else System.out.println(ss2[tag]);
   }
}

