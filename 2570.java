//* @author: 82638882@163.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main
{
 static int[][] m=new int[201][201];
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
   {
    int n=Integer.parseInt(in.readLine());
    if(n==0)break;
    for(int i=0;i< 201;i++)
     for(int j=0;j< 201;j++)
	m[i][j]=0;
    String[] ss;
    while(true)
    {
	ss=in.readLine().split(" ");
	int a=Integer.parseInt(ss[0]);
	int b=Integer.parseInt(ss[1]);
	if(a==0&&b==0)break;
	for(int i=0;i< ss[2].length();i++)
	{
	  int w=ss[2].charAt(i)-'a';
	  m[a][b]|=1<< w;
	}
     }
     for(int k=1;k<=n;k++)
       for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	   m[i][j]|=m[i][k]&m[k][j];
     while(true)
     {
	ss=in.readLine().split(" ");
	int a=Integer.parseInt(ss[0]);
	int b=Integer.parseInt(ss[1]);
	if(a==0&&b==0) break;
	char ch;
	for(ch='a';ch<='z';ch++)
	{
	  if((m[a][b]&(1<<(ch-'a')))!=0)
	   System.out.print(ch);
	}
	if(m[a][b]==0) System.out.print("-");
	System.out.println();
      }
     System.out.println();
   }
 }
}

