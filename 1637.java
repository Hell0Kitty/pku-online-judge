import java.util.*; 
import java.util.concurrent.ArrayBlockingQueue; 


public class Main { 
    static int N = 205; 
    static int [] degin, degout, deg, pre; 
    static int [][] cap; 

    private static int maxflow(int s, int t, int size) { 
        Queue<Integer> que = new ArrayBlockingQueue<Integer>(N); 
        int flow = 0, i, ext; 

        while(true) { 
            for(i = 0;i < size;++ i) 
                pre[i] = -1; 
            pre[s] = s; 
            que.clear(); 
            que.add(s); 
            while(!que.isEmpty()) { 
                int k = que.poll(); 
                for(i = 0;i < size;++ i) { 
                    if(pre[i] == -1 && cap[k][i] > 0) { 
                        pre[i] = k; 
                        if(i == t) break; 
                        que.add(i); 
                    } 
                } 
            } 

            if(pre[t] == -1) break; 

            ext = cap[pre[t]][t]; 
            for(i = t;i != s;i = pre[i]) { 
                if(ext > cap[pre[i]][i]) 
                    ext = cap[pre[i]][i]; 
            } 
            flow += ext; 
            for(i = t;i != s;i = pre[i]) { 
                cap[pre[i]][i] -= ext; 
                cap[i][pre[i]] += ext; 
            } 
        } 
        return flow; 
    } 

    public static void main(String [] args) { 
        Scanner cin = new Scanner(System.in); 
        int n, m, s, a, b, d, i, j, p; 
        degin = new int [N]; 
        degout = new int [N]; 
        deg = new int [N]; 
        pre = new int [N]; 
        cap = new int [N][N]; 

        n = cin.nextInt(); 
        while(n -- > 0) { 
            m = cin.nextInt(); 
            s = cin.nextInt(); 
            for(i = 0;i < m + 2;++ i) { 
                degin[i] = degout[i] = deg[i] = 0; 
                for(j = 0;j < m + 2;++ j) 
                    cap[i][j] = 0; 
            } 
            p = 0; 

            for(i = 0;i < s;++ i) { 
                a = cin.nextInt(); 
                b = cin.nextInt(); 
                d = cin.nextInt(); 
                if(d == 0) { 
                    deg[a]++; 
                    deg[b]++; 
                    cap[0][a]++; 
                    cap[a][b]++; 
                    ++p; 
                } 
                else { 
                    degout[a]++; 
                    degin[b]++; 
                } 
            } 

            Boolean flag = true; 
            for(i = 1;i <= m;++ i) { 
                int k = degin[i] + degout[i] + deg[i]; 
                if(k % 2 == 1 || k / 2 < degin[i] || k / 2 < degout[i]) { 
                    flag = false; 
                    break; 
                } 
                cap[i][m + 1] = k / 2 - degin[i]; 
            } 

            if(flag && maxflow(0, m + 1, m + 2) == p) 
                System.out.println("possible"); 
            else 
                System.out.println("impossible"); 
        } 
    } 
}