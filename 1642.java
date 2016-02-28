import java.io.*;
import java.util.Scanner;
public class Main
{
  public static void main(String args[])
  {
    Scanner cin=new Scanner(System.in);
    int x[]=new int[20];
    int y[]=new int[20];
    int z[]=new int[20];
    int map[][][]=new int[20][20][20];
    int tp=0;
    int i,j,k,t,n;
    while(cin.hasNext())
    {  
      n=cin.nextInt();
      if(n==0)
        return;
      if(tp==0)
        tp=1;
      else
        System.out.println("\n");
      for(i=0;i<20;i++)
        for(j=0;j<20;j++)
          for(k=0;k<20;k++)
            map[i][j][k]=0;
      for(i=0,j=0;i<n;)
      {
        t=cin.nextInt();
        if(t==0)
        {
          i++;
          j=0;
        }
        else
        {
          for(k=0;k<t;k++)
            map[i][j][k]=1;
          j++;
        }
      }

      for(i=0;i<20;i++)
      {
        for(j=0;j<20;j++)
        {
          t=0;
          for(k=0;k<20;k++)
            if(map[j][k][i]==1)
              t++;
          if(t==0&&j==0)
          {
            i=20;
            break;
          }
          if(t==0)
            break;
          if(j!=0)
            System.out.print(" ");
          System.out.print(t);
        }
        if(i!=20)
          System.out.println();
      }
      System.out.println();    

      for(i=0;i<20;i++)
      {
        for(j=0;j<20;j++)
        {
          t=0;
          for(k=0;k<20;k++)
            if(map[k][i][j]==1)
              t++;
          if(t==0&&j==0)
          {
            i=20;
            break;
          }
          if(t==0)
            break;
          if(j!=0)
            System.out.print(" ");
          System.out.print(t);
        }
        if(i!=20)
          System.out.println();
      }
    }
    
  }
}

