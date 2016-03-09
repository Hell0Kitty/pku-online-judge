//* @author:
import java.util.*;

class Edge{
    int v, next;
    boolean vis;
    Edge(int v,int next){
        this.v = v;
        this.next = next;
        this.vis = false;
    }
}
class Graph{
    static int MAXN = 10010;
    static int n, m, size;
    static int[] ans = new int[MAXN*3];
    static int[] head = new int[MAXN];
    static Edge[] edge = new Edge[MAXN*10];
    Graph(){
        Arrays.fill(head,-1);
        size = 0;
    }
    void add_edge(int u,int v){
        edge[size] = new Edge(v,head[u]);
        head[u] = size ++;
    }

    void Find_Euler(int u){
        for(int i = head[u];i != -1;i = edge[i].next){
            if(!edge[i].vis){
                edge[i].vis = true;
                Find_Euler(edge[i].v);
            }
        }
        System.out.println(u);
    }

}
public class Main{
    public static void main(String []args){
        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            Graph a = new Graph();
            a.n = in.nextInt();
            a.m = in.nextInt();
            for(int i = 1;i <= a.m; ++i){
                int u = in.nextInt();
                int v = in.nextInt();
                a.add_edge(u,v);
                a.add_edge(v,u);
            }
            a.Find_Euler(1);
        }
    }
}

