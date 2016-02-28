import java.util.Scanner;
public class Main {

/**
* @param args
*/
static final int max=100;
//static final int inf=1000000000;
static int mapstrstr[][];
public static void main(String[] args) {
   // TODO Auto-generated method stub
   Scanner sc=new Scanner(System.in);
   int t,x,y,z,m,n;
   mapstrstr=new int[max][max];
   t=sc.nextInt();
   for(int i0=0;i0< t;i0++)
   {
    n=sc.nextInt();
    m=sc.nextInt();
    for(int j=1;j<=n;j++)
    {
     for(int l=j+1;l<=n;l++)
     {
      mapstrstr[j][l]=mapstrstr[l][j]=100000;
     }
     mapstrstr[j][j]=100000;
    }
    for(int j=1;j<=m;j++)
    {
     int temp1=sc.nextInt();
     int temp2=sc.nextInt();
     mapstrstr[temp1][temp2]=1;
    }
    for(int k=1;k<=n;k++)
     for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      {
       if(mapstrstr[i][j]>mapstrstr[i][k]+mapstrstr[k][j])
       mapstrstr[i][j]=mapstrstr[i][k]+mapstrstr[k][j];
      }
      //System.out.println(mapstrstr[4][1]);
      /*
    for(int i=1;i<=n;i++)
    {

    for(int j=1;j<=n;j++)
    {
    System.out.print(mapstrstr[i][j]+" ");

    }
    System.out.println("");
    }
    */
    z=0;
    for(int i=1;i<=n;i++)
    {x=y=0;
     for(int j=1;j<=n;j++)
      if(mapstrstr[i][j]!=100000)x++;
     for(int j=1;j<=n;j++)
      if(mapstrstr[j][i]!=100000)y++;
     if(x>=(n+1)/2||y>=(n+1)/2)z++;
    }
    System.out.println(z);
   }

}

}


