//* @author: 82638882@163.com
import java.util.*;
import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  int[] arr=new int[a];
  int u,total;
  for(int i=0;i< a;i++)
  {
	total=0;
	while(true)
	{
         u=in.read();
	  if(u>'9'||u< '0')break;
		total*=10;
		total+=u-'0';
	}
	arr[i]=total;
    }
    if(a< 4)
	System.out.println("The set is rejected.");
    else
    {
	Arrays.sort(arr);
	if(arr[a-1]-arr[0]< arr[1])
		System.out.println("The set is rejected.");
	else{
	  boolean bb=false;
	  for(int i=a-1;i>=2;i--)
	  {
	    if(arr[i]-arr[i-2]< arr[i-1])
	    {
		System.out.println("The set is accepted.");
		bb=true;
		break;
	    }
	   }
	   if(!bb) System.out.println("The set is rejected.");
	}
     }
  }
}

