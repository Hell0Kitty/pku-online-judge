import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int n,m,c;
     while(sc.hasNext()){
        n=sc.nextInt();
        if(n==0) break;
        m=sc.nextInt();
        c=sc.nextInt();
       int t=(m-7)*(n-7);
    int t1=(t+1)/2;
    if (c==0) System.out.printf("%d\n",t-t1);
    else System.out.printf("%d\n",t1);

  }
}

