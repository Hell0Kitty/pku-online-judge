import java.io.PrintWriter;

 import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
   Scanner scn = new Scanner(System.in);
   PrintWriter out = new PrintWriter(System.out);
  int s,d,result;
   while(scn.hasNext()){
    result = 0;
    s = scn.nextInt();
    d = scn.nextInt();
    if(d > 4 * s){
     result = 10*s - 2*d;
    }else if( 2*d > 3*s){
     result = 8*s - 4*d;
    }else if( 3*d > 2*s){
     result = 6*s - 6*d;
    }else if( 4*d > s){
     result = 3*s - 9*d;
    }
   out.println("" + (result >0 ?result:"Deficit"));
  }
  out.flush();
 }

}


