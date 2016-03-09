import java.util.Scanner;
public class Main{
  public static void main(String args[])
{
   char cc[][]=new char[3][3];
   Scanner sc=new Scanner(System.in);

   int n,i,j;
   n=sc.nextInt();
   while((n--)!=0)
   {
    for(i=0;i< 3;i++)
        cc[i]=sc.next().toCharArray();

    int x=0,o=0;
       boolean xw=false,ow=false;
       boolean bb=true;
    for(i=0;i< 3;i++)
     for(j=0;j< 3;j++)
     {
        if(cc[i][j]=='X')x++;
        else if(cc[i][j]=='O')o++;
     }
    if(x-o>1||x< o)bb=false;
    for(i=0;i< 3;i++)
    {
      boolean tt=true;
      for(j=0;j< 2;j++)
      {
        if(cc[i][j]!=cc[i][j+1])
        {
        tt=false;
        break;
         }

       }
       if(tt)
       {
        if(cc[i][0]=='X')xw=true;
        else if(cc[i][0]=='O')ow=true;
        }
      }

     for(j=0;j< 3;j++)
    {
      boolean  tt=true;
      for(i=0;i< 2;i++)
      {
        if(cc[i][j]!=cc[i+1][j])
         {
        tt=false;
        break;
         }
       }
       if(tt)
        {
        if(cc[0][j]=='X')xw=true;
        else if(cc[0][j]=='O')ow=true;
        }
      }
     if(cc[0][0]==cc[1][1]&&cc[1][1]==cc[2][2]&&cc[2][2]=='X')xw=true;
     else if(cc[0][0]==cc[1][1]&&cc[1][1]==cc[2][2]&&cc[2][2]=='O')ow=true;
     if(cc[0][2]==cc[1][1]&&cc[1][1]==cc[2][0]&&cc[2][0]=='X')xw=true;
     else if(cc[0][2]==cc[1][1]&&cc[1][1]==cc[2][0]&&cc[2][0]=='O')ow=true;
     if(ow&&xw) bb=false;
     else if(ow&&x!=o)bb=false;
     else if(xw&&x==o)bb=false;
     if(bb) System.out.println("yes");
     else System.out.println("no");
    }
   }
}

