import java.util.*;
import java.io.*;

public class Main {
 static Scanner in = new Scanner(System.in);
 static class Node extends LinkedList< Node> {
    final int[] dp = new int[]{-1, -1};
    int query(int b) {
        if(dp[b]< 0) init(null);
        return dp[b];
    }
    void init(Node father) {
         dp[0] = dp[1] = 0;
     if(this.size()==1) return;
     int f = 0;
     int[] deta = new int[]{Integer.MAX_VALUE, Integer.MAX_VALUE};
     for(Node v: this) {
        if(v == father) continue;
        v.init(this);
        dp[0] += v.dp[1]+1;
        deta[f] = Math.min(deta[f], v.dp[0]-v.dp[1]);
        if(deta[f]< deta[f^1]) f^=1;
    }
    dp[0] += deta[f^1] - 1;
    dp[1] = dp[0]+Math.min(0, deta[f]-1);
       }
   }

  public static void main(String[] args) {
   int n = in.nextInt();
   Node[] nodes = new Node[n];
   for(int i=0; i!=n; ++i)
    nodes[i] = new Node();
   for(int i=1; i!=n; ++i) {
    int x = in.nextInt()-1;
    int y = in.nextInt()-1;
    nodes[x].add(nodes[y]);
    nodes[y].add(nodes[x]);
   }
   System.out.println(nodes[0].query(1)+1);
 }
}

