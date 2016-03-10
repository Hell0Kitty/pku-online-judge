//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
    public static int step;
    public static int[] h;
    public static void main(String[] args){
     Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n,m;
        while (scanner.hasNext()){
            n=scanner.nextInt();
            m=scanner.nextInt();
            step=0;
            h=new int[n];
            for (int i=0;i< n ;i++ ){
                h[i]=scanner.nextInt();
            }
            step=getStep(h.length-1,m);
            System.out.println(step%m);
        }
    }

    public static int getStep(int moved,int m){
        if (moved==0){
            return 2*h[moved]-1;
        }
        int total=h[0];
        for (int i=1;i< moved ;i++ ){
            total=(total*2+h[i])%m;
        }
        if (h[moved]==1){
            return total*2+1;
        }
        else{
            return 2*total+2*h[moved]+getStep(moved-1,m);
        }
    }
}

