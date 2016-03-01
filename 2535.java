import java.util.Scanner;
import java.util.Arrays;
public class Main{
 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);
 int cnt[]=new int[101];
 int temp[]=new int[101];
 boolean arr[]=new boolean[101];
 int n,p,i,j;
  n=sc.nextInt();
  p=sc.nextInt();
  Arrays.fill(cnt,0);
  Arrays.fill(arr,false);
  for(i=0;i< n;i++)
  {
	int max=0,min=999999;
	for(j=0;j< p;j++)
	{
          temp[j]=sc.nextInt();
          if(max< temp[j])max=temp[j];
	   if(min>temp[j])min=temp[j];
	}
	for(j=0;j< p;j++)
	{
	  if(temp[j]==min) cnt[j]++;
	  if(temp[j]==max) arr[j]=true;
	}
   }
   boolean bb=false;
   for(i=0;i< p;i++)
   {
	if(arr[i]||n/2>=cnt[i]) continue;
	if(bb) System.out.printf(" ");
	System.out.printf("%d",i+1);
	bb=true;
   }
   if(!bb) System.out.println("0");
 }
}

