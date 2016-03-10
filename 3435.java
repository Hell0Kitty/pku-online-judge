/* @author: */
import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

 int n,i,j,k1,k2,p[][]=new int[101][101];
 n=sc.nextInt();

 int len=n*n;
 for(i=0;i< len;i++)
   for(j=0;j< len;j++)
    p[i][j]=sc.nextInt();
 boolean bb[]=new boolean[101],is=true;
  //memset(bb,0,sizeof(bb));
 for(i=0;i< len;i++)
 {
    Arrays.fill(bb,false);
    for(j=0;j< len;j++)
    {
         if(p[i][j]==0)continue;
      if(bb[p[i][j]])break;
      bb[p[i][j]]=true;
    }
    if(j< len)break;
   }
  if(i< len)is=false;
  for(j=0;j< len;j++)
  {
    Arrays.fill(bb,false);
    for(i=0;i< len;i++)
    {
         if(p[i][j]==0)continue;
      if(bb[p[i][j]])break;
      bb[p[i][j]]=true;
    }
    if(i< len)break;
   }
   if(j< len)is=false;
   for(i=0;i< len;i+=n)
    {
    for(j=0;j< len;j+=n)
    {
       Arrays.fill(bb,false);
       for(k1=i;k1< i+n;k1++)
       {
        for(k2=j;k2< j+n;k2++)
        {
             if(p[k1][k2]==0)continue;
          if(bb[p[k1][k2]])break;
          bb[p[k1][k2]]=true;
        }
        if(k2!=j+n)break;
        }
       if(k1!=i+n)is=false;
       if(is==false)break;
    }
    if(is==false)break;
     }
     if(is) System.out.println("CORRECT");
     else System.out.println("INCORRECT");
   }
}

