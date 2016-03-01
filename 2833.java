//* @author: 82638882@163.com
import java.io.*;
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  StringBuffer buf=new StringBuffer();
  try {
	while(true)
	{
         char c;
	  int[] u=new int[3];
	  for(int i=0;i< 3;i++)
	  {
	    while(true)
	    {
		c=(char)in.read();
		if(c==32||c==13)
			break;
		buf.append(c);
	     }
	     u[i]=Integer.parseInt(buf.toString());
	     buf.delete(0,buf.length());
	   }
	  if(u[0]==0&&u[1]==0&&u[2]==0)break;
	  int[] max=new int[u[0]];
	  int[] min=new int[u[1]];
	  for(int i=0;i< u[1];i++)
		min[i]=9999999;
	  double total=0;
	  in.read();
	  for(int i=0;i< u[2];i++)
	  {
	   while(true)
	   {
		c=(char)in.read();
		if(c==32||c==13)
			break;
		buf.append(c);
	    }
	   int w=Integer.parseInt(buf.toString());
	   buf.delete(0,buf.length());
	   if(max[0]< w)max[0]=w;
	   if(min[u[1]-1]>w)min[u[1]-1]=w;
	   Arrays.sort(max);
	   Arrays.sort(min);
	   total+=w;
	  }
	 for(Integer e:max)
		total-=e;
	for(Integer e:min)
		total-=e;
	in.read();
	System.out.printf("%.6f\n",total/(u[2]-u[1]-u[0]));
   }
  } catch (IOException e) {}
 }
}

