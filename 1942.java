import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
  {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    while(true)
    {
	String[] ss=in.readLine().split(" ");
	Long n=Long.parseLong(ss[0]);
	Long m=Long.parseLong(ss[1]);
	if(n==0&&m==0) break;
	long ans=1;
	n=m+n;
	if(m>n-m) m=n-m;
	long temp=m;
	for(long i=n-m+1;i<=n;i++)
	{
		ans*=i;
		while(temp!=0&&ans%temp==0)
		{
			ans/=temp;
			temp--;
		}
	}
	System.out.println(ans);
     }
  }

}

