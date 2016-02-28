import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Node{
    int v, dis, cost, next;
}

public class Main{
    int MAX = 1<<15;
    Node edge[] = new Node[MAX];
    int head[] = new int[MAX];
    int n, k, len, ans;
    boolean vis[] = new boolean[10000];
   
    void dfs(int v, int dis, int money){
        if(dis>ans)return;
        if(v == n){
            if(money>=0&&dis<ans)
                ans = dis;
        }
        for(int i = head[v];i!=0;i = edge[i].next){
            if(!vis[edge[i].v] && money-edge[i].cost>=0){
                vis[edge[i].v] = true;
                dfs(edge[i].v, dis + edge[i].dis, money - edge[i].cost);
                vis[edge[i].v] = false;
            }
        }
    }
   
    void solve() throws IOException{
       // BufferedReader cin = new BufferedReader(new FileReader(new File("in")));
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        String read;
        k = Integer.parseInt(cin.readLine());
        n = Integer.parseInt(cin.readLine());
        int r = Integer.parseInt(cin.readLine());
        len = 0;
        Arrays.fill(vis, false);
        for(int i=0;i<r;i++){
            read = cin.readLine();
            int s = Integer.parseInt(read.split(" ")[0]);
            int t = Integer.parseInt(read.split(" ")[1]);
            int l = Integer.parseInt(read.split(" ")[2]);
            int c = Integer.parseInt(read.split(" ")[3]);
            if(edge[++len] == null)edge[len] = new Node();
            edge[len].v = t;
            edge[len].cost = c;
            edge[len].dis = l;
            edge[len].next = head[s];
            head[s] = len;
        }
        ans = 1<<29;
        dfs(1, 0, k);
        if(ans == 1<<29)System.out.println("-1");
        else System.out.println(ans);
    }
   
    public static void main(String[] args) throws IOException{
        Main test = new Main();
        test.solve();
    }
}