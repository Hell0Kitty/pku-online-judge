import java.util.*;
public class Main {
static long get_Area(long x1,long y1, long x2,long y2)
{
        return x1*y2-x2*y1;
}

public static void main(String[] args){
 Scanner sc = new Scanner(System.in);
int move[][]={{0,0},{1,-1},{1,0},{1,1},{0,-1},{0,0},{0,1},{-1,-1},{-1,0},{-1,1}};

    int d,ncase;
    long x0,y0,newx,newy,area; 
    ncase=sc.nextInt();
  
    while((ncase--)!=0)
    {
     String  ss=sc.next();
       
        x0=y0=area=0;
        for(int i=0;i<=ss.length()-1;i++)
        {
            d=ss.charAt(i)-'0';
            newx=x0+move[d][0];
            newy=y0+move[d][1];
            area+=get_Area(x0,y0,newx,newy);      
            x0=newx;
            y0=newy;
        }
        if(area<0)
           area*=-1;
        if(area%2!=0)
           System.out.printf("%d.5\n",area/2);
        else
           System.out.printf("%d\n",area/2); 
    }
   }
}