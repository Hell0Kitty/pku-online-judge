/* @author: */
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Main{
  static final int  MAX=50001;
 public static void main(String args[]) throws IOException{
  BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
 // Scanner sc = new Scanner (System.in);//这样居然超时
  int h[]=new int[MAX];
  int max=0;
  int result[]=new int[MAX];

    int j=0;
    int n=Integer.parseInt(buff.readLine());
    //int n=sc.nextInt();
    for(int i=0;i< n;i++)
      h[i]=Integer.parseInt(buff.readLine());
    //  h[i]=sc.nextInt();
    max=h[0];
    if(h[0]>h[1]) result[j++]=1;//处理序列的第一个数
    for(int i=1;i< n;i++){//依次处理序列的其它各项
       if(h[i]>=max&&h[i+1]<=h[i]){
           max=h[i];
           result[j++]=i+1;//记录满足条件的项的下标.
       }
       else max=h[i];
    }
    for(int m=0;m< j;m++)
      System.out.printf("%d\n",result[m]);
  }
}

