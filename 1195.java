import java.util.Scanner;
 public class Main{
  //static  int Max = 1030;   
  int n;
  int[][] C;   
  
  public Main(){
   }
   private int lowbit(int t){  
       return t&(-t);   
    }  
 
    
    int Sum(int i, int j){
      int result = 0;
      for(int x = i; x > 0; x -= lowbit(x)) {
        for(int y = j; y > 0; y -= lowbit(y)) {
            result += C[x][y];
        }
      }
     return result;
   }

     private void Modify(int i, int j, int delta){
         
       // A[i][j]+=delta;
     
       for(int x = i; x<=n; x += lowbit(x))
        for(int y = j; y <=n; y += lowbit(y)){
          C[x][y] += delta;
        
        }
     }
   
     public static void  main(String[] args){   
       Main ma=new Main();
        ma.go();
     }

     private void go(){
      int k,a,b,cc,x,y;   
      Scanner in=new Scanner(System.in);
       while(true){
         k=in.nextInt();
         if(k==3) break;
         if(k==0){
             n=in.nextInt();
             C=new int[n+1][n+1];
         }else if(k==1){
             a=in.nextInt();
             b=in.nextInt();
             cc=in.nextInt();
             a++;
             b++;
             Modify(a,b,cc);
          }else{
             x=in.nextInt();
             y=in.nextInt();
             a=in.nextInt();
             b=in.nextInt();
             x++;
             y++;
             a++;
             b++;
                 
             System.out.printf("%d\n",Sum(a,b)+Sum(x-1,y-1)-Sum(a,y-1)-Sum(x-1,b));
          }
       }
     }
 }
   