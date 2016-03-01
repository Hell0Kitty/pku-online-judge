//* @author: 82638882@163.com
import java.io.*;
import java.util.Arrays;
class Main
{
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
    int a=Integer.parseInt(in.readLine());
    if(a==0) break;
    my[] p=new my[a];
    for(int i=0;i< a;i++)
    {
	String[] ss=in.readLine().split(" ");
	p[i]=new my(Integer.parseInt(ss[0]),Integer.parseInt(ss[1]));
    }
    Arrays.sort(p);
    int cnt=0;
    for(int i=1,n=0;i< a;i++)
    {
	if(p[n].a==p[i].a){
		cnt++;
		n=i;
	}
	else if(p[n].b<=p[i].b) cnt++;
	else n=i;
     }
     System.out.println(a-cnt);
    }
  }
}
class my implements Comparable< my>
{
	int a,b;
	public my(int x,int y)
	{
		a=x;
		b=y;
	}
	public int compareTo(my o) {
		if(a==o.a)return o.b-b;
		return a-o.a;
	}
}

