  import java.util.Scanner;
import java.util.Arrays;
public class Main{
   int map[][]=new int[22][22];
   int d[]=new int[16];
   char code[]={'.','!','X','#'};

   int sum(int i,int j){
    return map[i][j]+map[i-1][j]+map[i+1][j]+map[i][j-1]+map[i][j+1];
   }

  public void doIt(){
   Scanner sc=new Scanner(System.in);
   int n=sc.nextInt();

   for(int i=0;i< 16;i++)
    d[i]=sc.nextInt();

  for(int i=1;i<=20;i++)
   for(int j=1;j<=20;j++)
     map[i][j]=sc.nextInt();

   while((n--)!=0){
     int tem[][]=new int[22][22];
     for(int i=1;i<=20;i++)
    for(int j=1;j<=20;j++){
       tem[i][j]=map[i][j]+d[sum(i,j)];
       if(tem[i][j]>3)
         tem[i][j]=3;
       if(tem[i][j]< 0)
         tem[i][j]=0;
    }
    for(int i=1;i<=20;i++)
    for(int j=1;j<=20;j++){
        map[i][j]=tem[i][j];
    }
   }
  for(int i=1;i<=20;i++){
    for(int j=1;j<=20;j++){
    System.out.printf("%c",code[map[i][j]]);
    }
    System.out.println();
   }


}
 public static void main(String args[]){
   Main m=new Main();
   m.doIt();
 }
}

