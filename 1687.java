import java.util.*;
class Point{
  int x;
  int y;
  public Point(){
    this.x=0;
    this.y=0;
  }

  public Point(int x,int y){
    this.x=x;
    this.y=y;
  }
}

public class Main{
 
 static int cross_product(Point a,Point b){
   return a.x*b.y-a.y*b.x;
 }

 public static void main(String args[]){
   Point p[]=new Point[55];
   Scanner in=new Scanner(System.in);
    int cse=in.nextInt();
    while(!((cse--)==0)){
       
       int pre=0;
       int tmp=0;
       int id=0;
        int n=in.nextInt();
        for(int i=0;i<n;i++){
          p[i]=new Point();
          p[i].x=in.nextInt();
          p[i].y=in.nextInt();
        }
        int x=in.nextInt();
        int maxs=-1;int ans=0;
        for(int i=0;i<x;i++){
            int y=in.nextInt();
            int sum=0;
            for(int j=0;j<y;j++){
                 id=in.nextInt();
                id--;
                if(j==0){
                    pre=id;
                    tmp=id;
                }
                else{
                    sum+=cross_product(p[pre],p[id]);
                    pre=id;
                }
            }
            sum+=cross_product(p[id],p[tmp]);
            if(sum>maxs){
                maxs=sum;
                ans=i+1;
            }
        }
        System.out.printf("%d\n",ans);
    }
   }
}