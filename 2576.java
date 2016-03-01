import java.io.*;
import java.util.Arrays;
public class Main
{

 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  int a=Integer.parseInt(in.readLine());
  int total=0,l1=0,l2=0,i;
  int[] arr=new int[a];
  for(i=0;i< a;i++)
  {
   arr[i]=Integer.parseInt(in.readLine());
   total+=arr[i];
  }
  int u=a/2;
  int[] p1=new int[u];
  int[] p2=new int[a-u];
  Arrays.sort(arr);
  int sum1=0,sum2=0,u1,ans1=-1,ans2=-1;
  for(i=0;l1< u;i++)
   {
	p1[l1++]=arr[i];
	if(l1< u){
		p1[l1++]=arr[a-i-1];
		sum1+=arr[a-i-1];
	}
	sum1+=arr[i];
   }
   for(;l2< a-u;i++)
   {
	p2[l2++]=arr[i];
	sum2+=arr[i];
   }
   u1=Math.abs(sum1-sum2);
   ans1=sum1;
   ans2=sum2;
   for(i=0;i< 10000;i++)
   {
	int t1=(int) (Math.random()*l1);
	int t2=(int) (Math.random()*l2);
	sum1+=p2[t2]-p1[t1];
	sum2+=p1[t1]-p2[t2];
	int ww=p1[t1];
	p1[t1]=p2[t2];
	p2[t2]=ww;
	if(Math.abs(sum1-sum2)< u1)
	{
		u1=Math.abs(sum1-sum2);
		ans1=sum1;
		ans2=sum2;
	}
    }
    sum1=Math.min(ans1, ans2);
    sum2=Math.max(ans1, ans2);
    System.out.println(sum1+" "+sum2);
   }
}

