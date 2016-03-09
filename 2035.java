import java.util.Scanner;
import java.util.Arrays;
public class Main{

 public static void main(String args[])
{
 Scanner sc=new Scanner(System.in);

    int c[][]=new int[11][53],p[]=new int[11],r[]=new int[2],d[]=new int[11],count[]=new int[11];
    int casen,i,j,k,pn,top,discard,noanswer;
    casen=sc.nextInt();
    for(k=1;k<=casen;k++)
    {
      pn=sc.nextInt();
      for(i=0;i< pn;i++){count[i]=c[i][0]=0;p[i]=1;}
      c[0][0]=52;top=0;noanswer=0;r[0]=r[1]=0;
      for(i=1;i<=52;i++)
        c[0][i]=sc.nextInt();
      while(top< pn&&c[top][0]!=0)
      {
        if(noanswer!=0)break;
        discard=0;
        for(i=0;i< pn;i++)
        {
           if(discard!=0){

            for(j=c[i][0];j>=p[i];j--)c[i][j+1]=c[i][j];
            c[i][0]++;
            c[i][p[i]]=discard;
            p[i]++;if(p[i]>c[i][0])p[i]=1;
        }
        discard=0;
       if(c[i][0]!=0){
           count[i]++;if(count[i]>13)count[i]=1;
       if(c[i][p[i]]==count[i])
       {
       discard=count[i];if(top==i)r[1]=0;
       for(j=p[i];j< c[i][0];j++)c[i][j]=c[i][j+1];
       c[i][0]--;p[i]--;
       if(c[i][0]==0)d[i]=count[i];
       if(top==i&&c[i][0]==0)top++;
       }
          else if(top==i&&r[1]==0){r[0]=p[i];r[1]=count[i];}
          else if(top==i&&r[0]==p[i]&&r[1]==count[i])
             {noanswer=1;break;}
          p[i]++;if(p[i]>c[i][0])p[i]=1;
      }
     }
   }
   System.out.printf("Case %d:",k);
   if(noanswer!=0) System.out.printf(" unwinnable\n");
   else {
         for(i=0;i< pn;i++) System.out.printf(" %d",d[i]);
         System.out.printf("\n");
        }
    }
  }
}

