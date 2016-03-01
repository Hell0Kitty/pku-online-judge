//* @author: 82638882@163.com
import java.io.*;
import java.util.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
	InputStreamReader is=new InputStreamReader(System.in);
	BufferedReader in=new BufferedReader(is);
	String s=in.readLine();
	int a=Integer.parseInt(s);
	int[] t1=new int[a];
	int[] t2=new int[a];
	int[] t3=new int[a];
	int[] t4=new int[a];
	int[] t5=new int[a*a];
	int[] t6=new int[a*a];
	int abl=0,cdl=0;
	String[] ss;
	for(int i=0;i< a;i++)
	{
         ss=in.readLine().split(" ");
	  t1[i]=Integer.parseInt(ss[0]);
	  t2[i]=Integer.parseInt(ss[1]);
	  t3[i]=Integer.parseInt(ss[2]);
	  t4[i]=Integer.parseInt(ss[3]);
	}
	for(int i=0;i< a;i++)
	  for(int j=0;j< a;j++)
	  {
	   t5[abl++]=t1[i]+t2[j];
	   t6[cdl++]=t3[i]+t4[j];
	  }
	Arrays.sort(t5);
	Arrays.sort(t6);
	int l1=0,l2=cdl-1,ans=0,k,m;
	while(l1< abl&&l2>-1)
	{
	  if(t5[l1]+t6[l2]==0){
		k=0;
		m=0;
		for(int i=l1;i< abl;i++)
	         if(t5[l1]!=t5[i]) break;
		  else k++;
		l1+=k;
		for(int i=l2;i>-1;i--)
		  if(t6[l2]!=t6[i]) break;
		  else m++;
		l2-=m;
		ans+=k*m;
	  }
	  else if(t5[l1]+t6[l2]>0) l2--;
	  else l1++;
      }
      System.out.println(ans);
  }
}

