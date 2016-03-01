import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
	String s=in.readLine();
	int a=Integer.parseInt(s);
	if(a==0)break;
	int[][] arr=new int[a][a];
	String[] ss;
	for(int i=0;i< a;i++)
	{
	  ss=in.readLine().split(" ");
	  for(int j=0;j< a;j++)
	   arr[i][j]=Integer.parseInt(ss[j]);
	}
	boolean bb=true;
	for(int i=0;i< a-1;i++)
	{
		int k=arr[i][0]-arr[i+1][0];
		for(int j=1;j< a;j++)
		{
	         if(k!=arr[i][j]-arr[i+1][j])
		  {
			bb=false;
			break;
		  }
		}
		if(!bb)break;
	}
	System.out.println((bb?"":"not ")+"homogeneous");
   }
 }
}

