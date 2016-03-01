import java.io.*;
public class Main
{
 public static void main(String[] args) throws IOException
 {
   InputStreamReader is=new InputStreamReader(System.in);
   BufferedReader in=new BufferedReader(is);
   int[] s=new int[1000010];
   int size=0;
   while(true)
   {
	int u=in.read();
	if(u=='\n')break;
	s[size++]=u;
    }
   int n=Integer.parseInt(in.readLine());
   int[] arr=new int[n];
   char[] crr=new char[n];
   int l=0;
   for(int i=0;i< n;i++)
   {
	int ww=in.read();
	if(ww=='Q')
	{
        in.read();
	 int u=0;
	 while(true)
	 {
	  int temp=in.read();
	  if(temp>='0'&&temp<='9')
	  {
		u*=10;
		u+=temp-'0';
	  }
	  else break;
	 }
	 char ans='\0';
	 for(int j=l-1;j>=0;j--)
	 {
	  if(arr[j]< u) u--;
	  else if(arr[j]==u){
		ans=crr[j];
		break;
	  }
	 }
	if(ans=='\0')
		ans=(char)s[u-1];
	System.out.println(ans);
     }
    else if(ww=='I')
    {
	in.read();
	crr[l]=(char)in.read();
	in.read();
	int u=0;
	while(true)
	{
	   int temp=in.read();
	   if(temp>='0'&&temp<='9')
	   {
		u*=10;
		u+=temp-'0';
	   }
	   else break;
	 }
	if(u>l+size) u=l+size+1;
	arr[l]=u;
	l++;
     }
     in.readLine();
   }
 }
}

