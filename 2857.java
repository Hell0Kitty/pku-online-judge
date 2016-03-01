import java.util.*;

/**
 *
 * @author leo
 */
public class Main {
  public static int judge(double H,double V,double h,double v,double x,double y,int state){

   if((x>H*h&&y< V*v)||(x< H*h&&y>V*v)){
          return state;
   }else{
      state++;
      if(x< h*H&&y< v*V){
            return judge(H*h,v*V,h,v,x,y,state);
      }else{
         return judge(H*(1.0-h),V*(1.0-v),h,v,x-H*h,y-V*v,state);
      }
   }

 }
 public static void main(String[] args) {

  Scanner sc = new Scanner(System.in);
  double H,V,h,v,x,y;
  int n,state,count=1;
  H=sc.nextDouble();
  V=sc.nextDouble();
  h=sc.nextDouble();
  v=sc.nextDouble();
  while(H>1.0e-6){
    n=sc.nextInt();
    System.out.println("Case "+count+":");
    for(int i=1;i<=n;i++){
       x=sc.nextDouble();
       y=sc.nextDouble();
       state=judge(H,V,h,v,x,y,0);

       if(state%2==0)
          System.out.println("black");
       else
          System.out.println("white");


    }
    count++;

    H=sc.nextDouble();
    V=sc.nextDouble();
    h=sc.nextDouble();
    v=sc.nextDouble();
   }
 }
}

