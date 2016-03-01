//* @author: 82638882@163.com
import java.io.*;
public class Main
{
 static int[][] p;
 static int a;
 static long[][] w;
 public static void main(String[] args) throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
    a=Integer.parseInt(in.readLine());
    if(a==-1) break;
    p=new int[a][a];
    w=new long[a][a];
    w[0][0]=1;
    for(int i=0;i< a; i++)
    {
	for(int j=0;j< a; j++)
		p[i][j]=in.read()-'0';
	in.readLine();
    }
    for(int j=0;j< a;j++)
	if(p[0][j]+j< a) w[0][p[0][j]+j]+=w[0][j];
    for(int i=1;i< a;i++)
    {
	for(int j=0;j< a;j++)
		if(p[i-1][j]+i-1< a) w[p[i-1][j]+i-1][j]+=w[i-1][j];
	for(int j=0;j< a-1;j++)
		if(p[i][j]+j< a) w[i][p[i][j]+j]+=w[i][j];
     }
     System.out.println(w[a-1][a-1]);
   }
  }
}

