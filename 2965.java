import java.util.Scanner;
public class Main{
 static int gra[][]=new int[5][5];
 static char ch[]=new char[5];
 public static void main(String args[])
{
  Scanner sc=new Scanner(System.in);
   int i,j,k,f;
   for(i=1;i<=4;i++)
   {
     ch=sc.next().toCharArray();

      for(j=0;j< 4;j++)
    if(ch[j]=='+'){
      for(f=1;f<=4;f++){
        gra[i][f]++;
        if(f!=i)
         gra[f][j+1]++;
      }
    }
   }
   int sum=0;
   for(i=1;i<=4;i++)
    for(j=1;j<=4;j++)
     if(gra[i][j]%2!=0)
     {
      sum++;
     }
     System.out.printf("%d\n",sum);
   for(i=1;i<=4;i++)
    for(j=1;j<=4;j++)
     if(gra[i][j]%2!=0)
     {
      System.out.printf("%d %d\n",i,j);
     }
    }
}

