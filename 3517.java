 //* @author: 82638882@163.com
import java.io.*;
class Main
{
 static int n,k,m;
 public static void main(String[] args) throws IOException
 {
    InputStreamReader is=new InputStreamReader(System.in);
    BufferedReader in=new BufferedReader(is);
    while(true)
    {
        String[] ss=in.readLine().split(" ");
     n=Integer.parseInt(ss[0]);
     k=Integer.parseInt(ss[1]);
     m=Integer.parseInt(ss[2]);
     if(n==0) break;
     System.out.println((f(n-1)+m)%n+1);
    }
   }

 static int f(int num)
 {
    if(num==1) return 0;
    else return (k+f(num-1))%num;
 }
}

