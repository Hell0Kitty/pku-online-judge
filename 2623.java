import java.io.*;
import java.util.*;
public class Main
{//1979
 public static void main(String[] args) throws IOException
 {
	InputStreamReader is=new InputStreamReader(System.in);
	BufferedReader in=new BufferedReader(is);
	int a=Integer.parseInt(in.readLine());
	int[] arr=new int[a+1];
	for(int i=1;i<=a;i++)
		arr[i]=Integer.parseInt(in.readLine());
	Arrays.sort(arr);
	double t;
	if(a%2==0)t=arr[a/2]/2.0+arr[a/2+1]/2.0;
	else t=arr[(a+1)/2];
	System.out.printf("%.1f",t);
  }
}

