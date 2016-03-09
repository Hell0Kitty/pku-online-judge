/* @author: */
import java.util.*;
/**
 *
 * @author Leo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void recurse(int [] digit,int n,int count){
        if(n<=0) return;
        int oneNo=n%10,tenNo;
        int m=n/10;
        tenNo=m;
        for(int i=0;i<=oneNo;i++){
            digit[i]+=count;
        }
        while(tenNo!=0){
            digit[tenNo%10]+=(oneNo+1)*count;
            tenNo/=10;
        }
        for(int i=0;i< 10;i++){
            digit[i]+=count*m;
        }
        digit[0]-=count;
        recurse(digit,m-1,10*count);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        while(true){
            int [] digita=new int[10];
            int [] digitb=new int[10];
            int a=sc.nextInt();
            int b=sc.nextInt();
            if(a==b&&b==0) break;
            if(a>b){
                int t=b;
                b=a;
                a=t;
            }
            recurse(digita,a-1,1);
            recurse(digitb,b,1);
            for(int i=0;i< 10;i++){
                System.out.print(Math.abs(digitb[i]-digita[i])+" ");
            }
            System.out.println();
        }
    }

}

