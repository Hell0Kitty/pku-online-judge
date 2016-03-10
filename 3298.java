// author:M.J
import java.util.*;
import java.io.*;
public class Main{
 public static void main(String[] args){
  Scanner in = new Scanner(new BufferedInputStream(System.in));
    int T = in.nextInt();
    while(T > 0){
        T--;
        int n = in.nextInt();
        int k = in.nextInt();
        n--;
        int curr = k;
        int flag = 0;
        int ans = 1;
        while(n > 0){
            n--;
            k = in.nextInt();
            if(flag%2==0 && curr < k)
                curr = k;
            else if(flag%2==1 && curr > k)
                curr = k;
            if(flag%2==0 && k < curr){
                flag ++;
                ans ++;
                curr = k;
            }
            else if(flag%2==1 && k > curr){
                flag ++;
                ans ++;
                curr = k;
            }
        }
        System.out.println(ans);
    }
   }
}

