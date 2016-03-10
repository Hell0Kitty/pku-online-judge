//* @author:
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Node{
    int a, b, c, p, r;
}

public class Main{

    Node edge[] = new Node[11];
    int n, k, tot, ans;
    int use[] = new int[11];

    void dfs(int i, int money, int dp){
        if(edge[i].b == n){
            if(money< tot)tot = money;
            return;
        }
        for(int j = 1;j<=k;j++){
            if(edge[j]. a == edge[i].b && use[j]<=1){
                use[j]++;
                int min = edge[j].r;
                int b = 1<< (edge[j].b - 1);
                int c = 1<< (edge[j].c - 1);
                if((dp|c) == dp && edge[j].p < edge[j].r)
                    min = edge[j].p;
                dfs(j, money+min, (dp|b));
                use[j]--;
            }
        }
    }
    void solve() throws IOException{
       // BufferedReader cin = new BufferedReader(new FileReader(new File("in")));
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        int i, a, b;
        String read;
        read = cin.readLine();
        n = Integer.parseInt(read.split(" ")[0]);
        k = Integer.parseInt(read.split(" ")[1]);
        for(i=1;i<=k;i++){
            read = cin.readLine();
            if(edge[i] == null)edge[i] = new Node();
            edge[i].a = Integer.parseInt(read.split(" ")[0]);
            edge[i].b = Integer.parseInt(read.split(" ")[1]);
            edge[i].c = Integer.parseInt(read.split(" ")[2]);
            edge[i].p = Integer.parseInt(read.split(" ")[3]);
            edge[i].r = Integer.parseInt(read.split(" ")[4]);
        }
        if(n == 1){
            System.out.println("0");
            return;
        }
        ans = 1<< 29;
        for(i=1;i<=k;i++){
            tot = 1<< 29;
            if(edge[i].a == 1){
                use[i]++;
                b = 1<< (edge[i].b - 1);
                a = 1<< (edge[i].a - 1);
                dfs(i, edge[i].r, a|b);
                use[i]--;
            }
            if(tot< ans)ans = tot;
        }
        if(ans == 1<< 29)System.out.println("impossible");
        else System.out.println(ans);

    }

    public static void main(String[] args) throws IOException{
        Main test = new Main();
        test.solve();
    }
}

