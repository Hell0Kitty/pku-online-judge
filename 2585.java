import java.io.*;
public class Main
{
 static int[][] map=new int[10][10];
 static int[][]	p=new int[4][4];
 public static void main(String[] args)throws IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  while(true)
  {
   String s=in.readLine();
   if(s.equals("ENDOFINPUT"))break;
   String[] ss;
   for(int i=0;i< 4;i++)
   {
	ss=in.readLine().split(" ");
	for(int j=0;j< 4;j++)
		p[i][j]=Integer.parseInt(ss[j]);
   }
   in.readLine();
   for(int i=1;i< 10;i++)
     for(int j=1;j< 10;j++)
         map[i][j]=0;
   f();
   for(int i=1;i< 10;i++)
	map[i][i]=0;
   while(true)
   {
      boolean qq=false;
      for(int i=1;i< 10;i++)
	for(int j=1;j< 10;j++)
          for(int k=1;k< 10;k++)
	    if(map[i][j]==1&&map[j][k]==1&&map[i][k]==0)
	    {
		map[i][k]=1;
		qq=true;
	    }
      if(!qq)break;
    }
    boolean bb=true;
    for(int i=1;i< 10;i++)
	if(map[i][i]==1){
          bb=false;
	  break;
	}
    if(bb) System.out.println("THESE WINDOWS ARE CLEAN");
    else System.out.println("THESE WINDOWS ARE BROKEN");
   }
 }

  static void f()
  {
        int x;
 	x=p[0][1];
	map[x][1]=1;
	map[x][2]=1;
	x=p[0][2];
	map[x][2]=1;
	map[x][3]=1;
	x=p[1][0];
	map[x][1]=1;
	map[x][4]=1;
	x=p[2][0];
	map[x][4]=1;
	map[x][7]=1;
	x=p[1][3];
	map[x][3]=1;
	map[x][6]=1;
	x=p[2][3];
	map[x][6]=1;
	map[x][9]=1;
	x=p[3][1];
	map[x][7]=1;
	map[x][8]=1;
	x=p[3][2];
	map[x][8]=1;
	map[x][9]=1;
	x=p[1][1];
	map[x][1]=1;
	map[x][2]=1;
	map[x][4]=1;
	map[x][5]=1;
	x=p[1][2];
	map[x][2]=1;
	map[x][3]=1;
	map[x][5]=1;
	map[x][6]=1;
	x=p[2][1];
	map[x][4]=1;
	map[x][5]=1;
	map[x][7]=1;
	map[x][8]=1;
	x=p[2][2];
	map[x][5]=1;
	map[x][6]=1;
	map[x][8]=1;
	map[x][9]=1;
   }
}

