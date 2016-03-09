/* @author: */
import java.util.Scanner;
public class Main{

  public static void  main(String args[])
{
   Scanner sc=new Scanner(System.in);
   int p[][]=new int[305][305];
   char c[][]=new char[305][305];

   int n,m,i,j,k;

   while(sc.hasNext())
   {
      n=sc.nextInt();
      m=sc.nextInt();

     if(m==0&&n==0) break;
     for(i=0;i< n;i++)
        c[i]=sc.next().toCharArray();

     int x1=0,y1=0,x2=0,y2=0;
     for(i=0;i< n;i++)
    for(j=0;j< m;j++) p[i][j]=999999;
     for(i=0;i< n;i++)
     {
    for(j=0;j< m;j++)
    {
      if(c[i][j]=='Y')
      {
        x1=i;
        y1=j;
        c[i][j]=1;
      }
      else if(c[i][j]=='T')
      {
        x2=i;
        y2=j;
        c[i][j]=1;
       }
     else if(c[i][j]=='E')c[i][j]=1;
     else if(c[i][j]=='B')c[i][j]=2;
    }
      }
      p[x1][y1]=0;
      while(true)
      {
     boolean bb=false;
     for(i=0;i< n;i++)
     {
       for(j=0;j< m;j++)
       {
        if(p[i][j]==999999)continue;
        if(i>0&&c[i-1][j]<3&&p[i-1][j]>p[i][j]+c[i-1][j])
        {
              p[i-1][j]=p[i][j]+c[i-1][j];
           bb=true;
        }
        if(i< n-1&&c[i+1][j]<3&&p[i+1][j]>p[i][j]+c[i+1][j])
        {
          p[i+1][j]=p[i][j]+c[i+1][j];
          bb=true;
        }
        if(j>0&&c[i][j-1]<3&&p[i][j-1]>p[i][j]+c[i][j-1])
        {
           p[i][j-1]=p[i][j]+c[i][j-1];
           bb=true;
        }
        if(j< m-1&&c[i][j+1]<3&&p[i][j+1]>p[i][j]+c[i][j+1])
        {
          p[i][j+1]=p[i][j]+c[i][j+1];
          bb=true;
        }
        }
    }
    if(!bb)break;
     }
     if(p[x2][y2]>50000) System.out.println("-1");
     else System.out.printf("%d\n",p[x2][y2]);
   }
  }
}

