import java.util.*;
public class Main {
    static int c=0;
    static String[] str;
    static double[][] map;
    static double[] v;
    static int n,m;
    static boolean[] visited;

    public static void main(String[] args){
        Main p=new Main();
        Scanner cin=new Scanner(System.in);
        while(true){
            c++;
            n=cin.nextInt();
            if(n==0) return;
            str=new String[n];
            map=new double[n][n];
            v=new double[n];
            visited=new boolean[n];
            for(int i=0;i< n;i++){
                str[i]=cin.next();
                map[i][i]=1;
            }
            m=cin.nextInt();
            for(int i=0;i< m;i++){
                String a=cin.next();
                double r=cin.nextDouble();
                String b=cin.next();
                map[p.find(a)][p.find(b)]=r;

            }
            p.solve();
        }
    }
    void solve(){
            floyd(map);
            for(int i=0;i< n;i++){
                if(map[i][i]>1){
                    System.out.println("Case " + c +  ": Yes");
                    return;
                }
            }
            System.out.println("Case " + c +  ": No");
    }
    void floyd(double[][] map){
        for(int k=0;k < n;k++)
            for(int i=0;i< n;i++)
                for(int j=0;j< n;j++)
                    if(map[i][j]< map[i][k]*map[k][j])
                        map[i][j]=map[i][k]*map[k][j];
    }
    int find(String a){
        for(int i=0;i< n;i++)
            if(a.equals(str[i]))
                return i;
        return 0;
    }
}

