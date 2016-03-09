// author:M.J
import java.text.DecimalFormat;
import java.util.*;
import java.util.concurrent.CountDownLatch;
import java.io.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int[] t = new int[1002];
        int[] king = new int[1002];
        int ans = 0;
        while(cin.hasNextInt()) {
            ans = 0;
            int n = cin.nextInt();
            if(n == 0) break;
            for(int i = 0;i < n; i++)
                t[i] = cin.nextInt();
            for(int i = 0;i < n; i++)
                king[i] = cin.nextInt();
            Arrays.sort(t,0,n);
            Arrays.sort(king,0,n);
            int et = n-1,ek = n-1,st = 0,sk = 0;
            for(int i = 0;i < n; i++){
                    if(t[et] > king[ek]){
                            ans ++;
                            et --;
                            ek --;
                    }
                    else if(t[et] < king[ek]){
                            ans --;
                            ek --;
                            st ++;
                    }
                    else{
                            if(t[st] > king[sk]){
                                ans ++;
                                st ++;
                                sk ++;
                            }
                            else if(t[st] > king[sk]){
                                    ans --;
                                    st ++;
                                    ek --;
                            }
                            else{
                               if(t[st] < king[ek])
                                 ans --;
                                 st ++;
                                 ek --;
                            }
                    }
            }
            ans *= 200;
            System.out.println(ans);
        }
    }
}

