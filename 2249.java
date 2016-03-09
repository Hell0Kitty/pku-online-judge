//* @author  mekarlos@gmail.com
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
    static long[][] M=new long[2000][2000];
    public static long comb(int n,int k){
        if(k>(n/2))k=n-k;
        if(n< 2000&&k< 2000) return M[n][k];
        else if(k==n||k==0) return 1;
        else if(k==1) return n;
        else return comb(n-1,k)+comb(n-1,k-1);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer token;
        int n=0,k=0;
        for(int i=0;i< 2000;i++){
            M[i][i]=1;
            M[i][0]=1;
            M[i][1]=i;
            M[0][i]=0;
        }
        for(int i=1;i< 2000;i++){
            for(int j=2;j< 2000;j++){
                if(i!=j){
                    M[i][j]=M[i-1][j-1]+M[i-1][j];
                }
            }
        }
        while(true){
          token=new StringTokenizer(stdin.readLine());
           n=Integer.parseInt(token.nextToken());
           k=Integer.parseInt(token.nextToken());
           if(k==0&&n==0) break;
           System.out.println(comb(n,k));
        }
    }
}

