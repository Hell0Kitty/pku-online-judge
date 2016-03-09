import java.util.Scanner;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Main{
    public static void main(String args[]) throws Exception {
        int a[]=new int[500001];
        a[0]=0;
        HashMap< Integer,Boolean> ha=new HashMap< Integer,Boolean>();
        Scanner in=new Scanner(System.in);
       for(int i=1;i<=500000;i++){
        if(a[i-1]-i>0&&ha.get(a[i-1]-i)==null){
             a[i] = a[i-1]-i;
             ha.put(a[i],true);
         }else{
             a[i] = a[i-1]+i;
             ha.put(a[i],true);
          }
     }



        String input = new String();
        while(!(input=in.nextLine()).equals("-1")) {
          int n = Integer.parseInt(input);
          System.out.println(a[n]);
        }
      }

}

