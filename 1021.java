import java.util.Scanner;
import java.util.Arrays; 
public class Main{
   static int n_limit=100*100;
   static int width;
   static int height;
    
   static boolean in_map(int x,int y){  
    if (0<=x&&x< width&&0<=y&&y< height) return true;  
    else return false;  
   }  
   
   static int calculate(int x,int y,int[][] map)  
{  
     int i=x-1,j=y-1,i2=x+1,j2=y+1,temp=1;  
     while (in_map(i,y)&&map[i][y]!=0){ i--;temp++;}  
     while (in_map(x,j)&&map[x][j]!=0){ j--;temp++;}  
     while (in_map(i2,y)&&map[i2][y]!=0){ i2++;temp++;}  
     while (in_map(x,j2)&&map[x][j2]!=0) {j2++;temp++;}  
     
     return temp;  
 }  
    
  public static void main(String args[])  
 {  
     int flag,test_n;
     int x1[]=new int[n_limit];
     int x2[]=new int[n_limit];
     int y1[]=new int[n_limit];
     int y2[]=new int[n_limit];
     int value1[]=new int[n_limit];
     int value2[]=new int[n_limit];  


     Scanner sc=new Scanner(System.in);
     test_n=sc.nextInt();
    
     while ((test_n--)!=0)  
     {   
          width=sc.nextInt();
          height=sc.nextInt();
          int n=sc.nextInt();
        
          int[][] map1=new int[width][height];
          int[][] map2=new int[width][height];
          Arrays.fill(value1,0);
          Arrays.fill(value2,0);
         // Arrays.fill(map1,0);
          //Arrays.fill(map2,0);
           for (int i=0;i< n;i++){
            x1[i]=sc.nextInt();
            y1[i]=sc.nextInt();
             map1[x1[i]][y1[i]]=i+1;
         } 
         

         for (int i=0;i< n;i++){
           x2[i]=sc.nextInt();
           y2[i]=sc.nextInt();
           map2[x2[i]][y2[i]]=i+1;
         }
  
         for (int i=0;i< n;i++)  
         {  
             value1[i]=calculate(x1[i],y1[i],map1);  
             value2[i]=calculate(x2[i],y2[i],map2);  
         }  

        Arrays.sort(value1,0,n);  
        Arrays.sort(value2,0,n);  

         flag=1;  
        for (int i=0;i< n;i++)  
         {  
            if (value1[i]!=value2[i])  
             {  
                 flag=0;  
                 break;  
             }  
        }  
         if (flag!=0) System.out.printf("YES\n");  
         else System.out.printf("NO\n");  
     }  
     
   }
 }

