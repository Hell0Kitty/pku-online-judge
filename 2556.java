import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  while(in.hasNext())
  {
   String s=in.next();
   System.out.println("300 420 moveto");
   System.out.println("310 420 lineto");
   int b=0;
   int x=310;
   int y=420;
   for(int i=0;i< s.length();i++)
    {
	char c=s.charAt(i);
	if(b==0)
	{
	   if(c=='A'){
	     y-=10;
	     b=1;
	   }
	   else {
	    y+=10;
	    b=3;
	   }
         }
	else if(b==1)
	 {
	   if(c=='A'){
	     x-=10;
	     b=2;
	   }
	   else {
	    x+=10;
	    b=0;
	   }
	}
	else if(b==2)
	 {
	   if(c=='A'){
	     y+=10;
	     b=3;
	   }
	   else {
	    y-=10;
	    b=1;
	   }
	}
	else if(b==3)
	 {
	   if(c=='A'){
	     x+=10;
	     b=0;
	   }
	   else {
	     x-=10;
	     b=2;
	   }
	}
	System.out.println(x+" "+y+" lineto");
     }
     System.out.println("stroke");
     System.out.println("showpage");
    }
 }
}

