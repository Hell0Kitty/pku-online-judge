import java.math.*;  
import java.util.*;  
import java.io.*;  
import java.util.*;  
  
public class Main {  
    int M = 110;  
    int CD;  
    int fail[] = new int[M];  
    int Q[] = new int[M];  
    int ch[][] = new int[M][55];  
    int ID[] = new int[256];  
    int sz;  
    int flag[] = new int[M];  
    String DIC;  
    BigInteger dp[][] = new BigInteger[55][M];  
    BigInteger ans;  
    PrintStream out = System.out;  
    int m;  
      
    public void Init() {  
        fail[0] = 0;  
        flag[0] = 0;  
        Arrays.fill(ch[0], 0);  
        sz = 1;  
        for (int i = 0; i < DIC.length(); i++)  
            ID[DIC.charAt(i)] = i;  
        CD = DIC.length();  
    }  
  
    public void Insert(String s) {  
        int p = 0;  
        for (int i = 0; i < s.length(); i++) {  
            int c = ID[s.charAt(i)];  
            if (ch[p][c] == 0) {  
                Arrays.fill(ch[sz], 0);  
                flag[sz] = 0;  
                ch[p][c] = sz++;  
            }  
            p = ch[p][c];  
        }  
        flag[p] = 1;  
    }  
  
    void Construct() {  
        int head = 0, tail = 0;  
        for (int i = 0; i < CD; i++) {  
            if (ch[0][i] != 0) {  
                fail[ch[0][i]] = 0;  
                Q[tail++] = ch[0][i];  
            }  
        }  
        while (head != tail) {  
            int u = Q[head++];  
            for (int i = 0; i < CD; i++) {  
                int v = ch[u][i];  
                if (v != 0) {  
                    Q[tail++] = v;  
                    fail[v] = ch[fail[u]][i];  
                    flag[v] += flag[fail[v]];  
                } else {  
                    ch[u][i] = ch[fail[u]][i];  
                }  
            }  
        }  
    }  
    public void DP(){  
        for (int i = 0; i <= m; i++) {  
            for (int j = 0; j <= sz; j++) {  
                dp[i][j] = BigInteger.ZERO;  
            }  
        }  
        dp[0][0] = BigInteger.ONE;  
        for (int i = 0; i < m; i++) {  
            for (int j = 0; j < sz; j++)  
                if (dp[i][j].compareTo(BigInteger.valueOf(0)) == 1) {  
                    for (int k = 0; k < CD; k++) {  
                        if (flag[ch[j][k]] > 0 || flag[j] > 0)  
                            continue;  
                        dp[i + 1][ch[j][k]] = dp[i + 1][ch[j][k]].add(dp[i][j]);  
                    }  
                }  
        }  
        ans = BigInteger.ZERO;  
        for (int i = 0; i < sz; i++)  
            ans = ans.add(dp[m][i]);  
        out.println(ans);  
    }  
    public void solve() {  
        int n, p ;  
        try {  
            BufferedReader cin = new BufferedReader(new InputStreamReader(System.in, "ISO-8859-1"));  
            String[] args = cin.readLine().split(" ");  
            n = Integer.parseInt(args[0]);  
            m = Integer.parseInt(args[1]);  
            p = Integer.parseInt(args[2]);            
            DIC = cin.readLine();  
            Init();  
            for (int i = 0; i < p; i++) {  
                String s=cin.readLine();  
                Insert(s);  
            }     
            Construct();  
            DP();  
        } catch(IOException e){  
        }  
    }  
  
    public static void main(String args[]) {  
        new Main().solve();  
    }  
}  
