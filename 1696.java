import java.util.Scanner;
import java.util.Arrays;

 class  point implements Comparable {
    int id ;
    int ord ;
    double x;
    double y;

     public int compareTo(Object o) {//升序排列
        return this.ord - ((point) o).ord;   
     }   
   }

   public class Main{
     point[] p;
     boolean vis[] ;
     double ans ;
     int  n ;
     static final int inf=100000000;

     public Main(){
                
    }

     //向量(x1,y1),(x2,y2)的叉积
     public double det(double x1,double y1,double x2,double y2){
      return x1*y2 - x2*y1;
     }

     //小于0,说明向量ab的极角大于ac的极角     

    double cross(point a,point b,point c){
      return det(b.x - a.x, b.y - a.y, c.x - a.x,c.y - a.y);
    }

    //距离
   double dis(point a,point b) {
     double  x1 = a.x;
     double y1 = a.y;
     double x2 = b.x;
     double y2 = b.y ;
     return   (x2 - x1 )*(x2 - x1) + (y2-y1)*(y2 - y1);
 }

  void dfs(int pre,int num){
    //System.out.println("OK");
    if(num == n) return ;
     int mi = 1;
     while(vis[mi]) mi++;
     for(int i = mi + 1 ;i <= n;i++){
         if(vis[i]) continue ;
         double w = cross(p[pre],p[mi],p[i]);
         if(w  < 0) mi = i;
         if((w ==0) && dis(p[pre],p[i]) < dis(p[pre],p[mi])) mi = i;
     }
     p[mi].ord = num + 1;
 
     vis[mi] = true ;
     dfs(mi,num + 1) ;
 }

  

  public static void main(String args[]){
    Main ma=new Main();
    ma.go();
  }
    public void go(){
      Scanner in=new Scanner(System.in);
       int  t;
       t=in.nextInt();
        
    while(t-->0){
     n=in.nextInt();
     int mi = inf ;
     vis=new boolean[n+1];
     p=new point[n+1];
     p[0]=new point();
     for(int i = 1 ; i<= n;i++){
       p[i]=new point();
       p[i].id=in.nextInt();
       p[i].x=in.nextDouble();
       p[i].y=in.nextDouble();  
 
       //找y最小的
       if(mi == inf||p[mi].y > p[i].y) 
         mi =  i;
      }
      vis[mi] = true;
      p[mi].ord = 1 ;
      dfs(mi,1);
      Arrays.sort(p);
      System.out.printf("%d",n);
       for(int i = 1;i <=n;i++){
          System.out.printf(" %d",p[i].id) ;
        }
       System.out.println();
   }
 }
}

