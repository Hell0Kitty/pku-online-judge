//* @author:
import java.io.*;
import java.util.*;
public class Main
{
 public static void main(String args[]) throws Exception
 {
  Scanner cin=new Scanner(System.in);
  int N;
  double[][] point;
  int i,j;
  while(true)
  {
	N=cin.nextInt();
	if(N==0) break;
	point=new double[N][4];
	for(i=0;i< N;i++)
	{
         for(j=0;j< 4;j++)
	  {
	   point[i][j]=cin.nextDouble();
	   }
	 }
	 System.out.print("Top sticks:");
	  for(i=0;i< N-1;i++)
	  {
	   for(j=i+1;j< N;j++)
	   {
	    if(fun(point[i],point[j])) break;
	    }
	   if(j==N) System.out.print(" "+(i+1)+",");
	   }
	   System.out.println(" "+N+".");
   }
 }

 static boolean fun(double p[],double q[])
 {
  if(((q[1]-p[1])*(p[0]-p[2])+(q[0]-p[0])*(p[3]-p[1]))*((q[3]-p[1])*(p[0]-p[2])+(q[2]-p[0])*(p[3]-p[1]))< 0)
  if(((p[1]-q[1])*(q[0]-q[2])+(p[0]-q[0])*(q[3]-q[1]))*((p[3]-q[1])*(q[0]-q[2])+(p[2]-q[0])*(q[3]-q[1]))< 0)
	return true;
	return false;
  }
}

