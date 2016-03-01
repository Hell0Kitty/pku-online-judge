//* @author: 82638882@163.com
import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
   TreeSet< Long> t=new TreeSet< Long>();
   Scanner in=new Scanner(System.in);
   int[] arr=new int[10000001];
   arr[0]=1;
   int k1=0,k2=0;
   for(int i=1;i< 10000001;i++)
    {
	int y1=arr[k1]*2+1;
	int y2=arr[k2]*3+1;
	arr[i]=Math.min(y1, y2);
	if(arr[i]==y1) k1++;
	if(arr[i]==y2) k2++;
     }
    while(in.hasNext())
    {
	int a=in.nextInt();
	System.out.println(arr[a-1]);
    }
  }
}

