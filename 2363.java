//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
  int c=scanner.nextInt();
    int n,sm;
    for (int l=0;l< c ;l++ ){
       n=scanner.nextInt();
        sm=4*n+2;
        for (int i=1;i<=n ;i++ ){
            for (int j=1;j*i<=n ;j++ ){
                for (int k=0;k*j*k<=n ;k++ ){
                    if (i*j*k==n){
                        if (2*(i*j+j*k+k*i)< sm){
                            sm=2*(i*j+j*k+k*i);
                        }
                    }
                }
            }
        }
        System.out.println(sm);
    }
  }
}

