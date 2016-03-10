//* @author: SmilingWang
import java.util.*;

public class Main {
 static LinkedList< Integer> set = new LinkedList< Integer>();
 static TreeSet< Integer> tmset = new TreeSet< Integer>();
 static int[][] path;
 static boolean[][] use;
 static ArrayList[] table;
 public static void main(String[] args){
   Scanner in = new Scanner(System.in);
   int k, m, n;
   k = in.nextInt();
   n = in.nextInt();
   m = in.nextInt();
   int g[] = new int[k];
   for(int i = 0; i < k; i++){
    g[i] = in.nextInt();
   }
   path = new int[n+1][n+1];
   table = new ArrayList[n+1];
   for(int i = 1; i <= n; i++){
    path[i][i] = 1;
    table[i] = new ArrayList< Integer>();
    table[i].add(i);
   }
   for(int i = 0; i < m; i++){
    int a = in.nextInt();
    int b = in.nextInt();
    path[a][b] = 1;
    table[a].add(b);
   }

   for(int i = 0; i < k; i++){
     use = new boolean[n+1][n+1];
     search(g[i],n);
     set.addAll(tmset);
     tmset.clear();
    }
    Iterator< Integer> iter = set.iterator();
    int[] count= new int[n+1];
    int   ncount = 0;
    while(iter.hasNext()){
    int tm = iter.next();
    count[tm]++;
    if(count[tm] >= k){
        ncount++;
    }
    }
     System.out.println(ncount);
   }

  public static void search(int start, int n){
   for(int i = 0; i < table[start].size(); i++){
    int j = (Integer)table[start].get(i);
    if(path[start][j] > 0  && !use[start][j]){
        tmset.add(j);
        use[start][j] = true;
        search(j, n);
    }
   }
 }
}

