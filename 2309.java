//* @author  mekarlos@gmail.com
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        long n=scan.nextInt();
        long k=0,j,v,temp,l,r;
        for(int i=0;i< n;i++){
            k=scan.nextInt();
            if(k%2==1)System.out.println(k+" "+k);
            else{
                j=(int)Math.floor(Math.log(k)/Math.log(2));
                v=1<< j;
                while(v!=k){
                    j--;
                    if(v>k)v-=(1<< j);
                    else v+=(1<< j);
                }
                l=k;
                r=k;
                l-=(1<< j)-1;
                r+=(1<< j)-1;
                System.out.println(l+" "+r);
            }
        }
    }
}

