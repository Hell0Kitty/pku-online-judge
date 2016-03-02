import java.util.*;
public class Main
{
 public static void main(String[] args)
 {
  Scanner in=new Scanner(System.in);
  int a=in.nextInt();
  while((a--)!=0)
  {
	int b=in.nextInt();
	int[] arr=new int[b];
	int u=0;
	for(int i=1;i<=b;i++)
	{
        int y=i;
	 while(true)
	 {
	  if(arr[u]==0) y--;
	  if(y==-1)
	  {
		arr[u]=i;
		break;
	   }
	  u++;
	  if(u>=b) u%=b;
	 }
	}
	for(int i=0;i< b-1;i++)
		System.out.print(arr[i]+" ");
	System.out.println(arr[b-1]);
   }
  }
}

