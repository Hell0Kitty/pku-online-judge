import java.io.*;
import java.util.*;

public class Main {
    static final int N = 20+10;
    static int sum[] = new int[N],catana[] = new int[N];
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    public static void main(String[]args) throws Exception{
        int n;
        init();
        Scanner cin = new Scanner(System.in);
        while(true){
            n = cin.nextInt();
            if(n==0) break;
            solve(n);
            out.println();
            out.flush();
        }
    }
    static void solve(int n){
        int i,j,t;
        if(n==0) return ;
        if(n==1) {out.print("X");return;}
        for(j=1;;++j){
            if(sum[j]>=n) break;
        }
        n = n-sum[j-1];
        for(i=0;i< j;++i){
            t = catana[i]*catana[j-i-1];
            if(n>t) n = n-t;
            else break;
        }
        if(i!=0){
            out.print("(");
            solve(sum[i-1]+1+(n-1)/catana[j-i-1]);
            out.print(")");
        }
        out.print("X");
        if(i!=j-1){
            out.print("(");
            solve(sum[j-2-i]+1+(n-1)%catana[j-i-1]);
            out.print(")");
        }
    }
    static void init(){
        int i,j;
        catana[0] = catana[1] = 1;
        for(i=2;i< N;++i){
            catana[i] = 0;
            for(j=0;j< i;++j){
                catana[i] += catana[j]*catana[i-j-1];
            }
        }
        sum[0] = 0;
        sum[1] = 1;
        for(i=2;i< N;++i)
            sum[i] = sum[i-1]+catana[i];
    }
}

