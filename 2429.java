//* @author:
import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main
{
 public static void main(String args[]) throws Exception
 {
   Scanner cin=new Scanner(System.in);
   long a,b,c,i;
   while(cin.hasNext())
    {
	a=cin.nextLong();
	b=cin.nextLong();
	c=b/a;
	for(i=(long)Math.sqrt(c);i>=1;i--)
	{
	  if(c%i==0&&GCD(i,c/i)==1)
	  {
		System.out.println((a*i)+" "+(b/i));
		break;
	  }
	}
     }
 }

static long GCD(long a,long b)
{
  long temp;
  while(b!=0)
   {
    a=a%b;
    temp=a;
    a=b;
    b=temp;
   }
  return a;
}

static long LCM(long a,long b)
{
 return a/GCD(a,b)*b;
 }
}

