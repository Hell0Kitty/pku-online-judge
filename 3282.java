//* @author:
import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);

    int sl,sr,left,right;
    int nn=sc.nextInt();
    while((nn--)!=0)
    {
      int l=sc.nextInt();
      int n=sc.nextInt();
        l*=100;sl=0;sr=0;left=0;right=0;
        for (int i=1;i<=n;i++) {
         int  t=sc.nextInt();
         char s[]=sc.next().toCharArray();
            if (s[0]=='l') {
                 if (sl+t>l) {sl=t;left++;}
                 else sl+=t;
            }
            else {
                 if (sr+t>l) {sr=t;right++;}
                 else sr+=t;
            }
        }
        if (sl!=0) left++;
        if (sr!=0) right++;
        System.out.printf("%d\n",left>right?left+left-1:right+right);
    }
  }
}

