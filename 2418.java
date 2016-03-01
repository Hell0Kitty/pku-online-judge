import java.io.*;
import java.text.DecimalFormat;

class Trie{
    Trie next[] = new Trie[128];
    int cnt;
    public Trie(){
        cnt = 0;
    }
}

public class Main{
    Trie root = new Trie();
    String res;
    int all = 0;
    DecimalFormat a = new DecimalFormat("0.0000");
    void solve() throws IOException{
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        //BufferedReader cin = new BufferedReader(new FileReader(new File("in")));

        String input;
        while((input = cin.readLine()) != null){
            insert(input.toCharArray());
        }
        res = "";
        dfs(root);
    }
    void insert(char[] str){
        int len = str.length;
        int k = 0, t;
        Trie p = root;
        while(k!=len){
            t = str[k++];
            if(p.next[t] == null)p.next[t] = new Trie();
            p = p.next[t];
        }
        p.cnt++;
        all++;
    }

    void dfs(Trie p){
        if(p.cnt!=0)System.out.println(res + " " + a.format(p.cnt*100.0/all));
        for(int i=0;i< 128;i++){
            if(p.next[i] != null){
                res+=(char)i;
                dfs(p.next[i]);
                res = res.substring(0, res.length()-1);
            }
        }
    }
    public static void main(String[] args) throws IOException{
        Main test = new Main();
         test.solve();
    }
}

