//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args){
  Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n=scanner.nextInt();
        int t,total;
        int[] prs;
        for (int i=0;i< n ;i++ ){
            t=scanner.nextInt();
            prs=new int[t];
            for (int j=0;j< t ;j++ ){
                prs[j]=scanner.nextInt();
            }
            Arrays.sort(prs);
            total=0;
            for (int j=t-1;j>=0 ;j-- ){
                if ((t-j)%3==0){
                    total=total+prs[j];
                }
            }
            System.out.println(total);
        }
    }
}


