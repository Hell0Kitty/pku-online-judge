//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;

class node implements Comparable{
    int v,next,disten;
    node(){
        v = next = disten = -1;
    }
    node(int v,int next,int disten){
        this.v = v;
        this.next = next;
        this.disten = disten;
    }
    void set_node(int v,int next,int disten){
        this.v = v;
        this.next = next;
        this.disten = disten;
    }
    void copy(node obj){
        this.v = obj.v;
        this.next = obj.next;
        this.disten = obj.disten;
    }
    public int compareTo(Object obj){

        node cnt = (node)obj;
        if(cnt.disten< disten) return 1;
        return -1;
    }
}
class binary_Heap{
    node tree[];
    int n,p,c;
    binary_Heap(){};
    binary_Heap(int cap){
        n = 0;
        tree = new node[40000];
        for(int i=0;i< 40000;++i) tree[i] = new node();
    }
    void push(node temp){
        for(p=++n;p>1 && tree[p>>1].compareTo(temp)>0;p>>=1){
            tree[p].copy(tree[p>>1]);
        }
        tree[p].copy(temp);

    }
    node front(){return tree[1];}
    void pop(){
        for(p=1,c=2;c< n && tree[c+=(c< n-1 && tree[c+1].compareTo(tree[c])>0)?1:0].
                  compareTo(tree[n])>0;tree[p].copy(tree[c]),p=c,c<<=1);

        tree[p].copy(tree[n--]);
    }
}
class Graph{
    int n,top;
    node Map[];
    Graph(){}
    Graph(int n){
        top = n+1;
        this.n = n;
        Map = new node[200000];
        for(int i=0;i< 200000;++i){
            Map[i] = new node();
        }
    }
    void add_edge(int u,int v,int disten){
        Map[top].set_node(v, Map[u].next,disten);
        Map[u].next = top;
        ++top;
    }


int get_Dijkstra(int s,int t){
 node temp = new node();
 int BIG = 1000000000;
 int meat[] = new int[n+10];
 //binary_Heap heap = new binary_Heap(n);
 Queue que = new PriorityQueue< node>();

 Arrays.fill(meat, BIG);

 meat[s] = 0;
 for(int i=Map[s].next;i>=0;i=Map[i].next){
    meat[Map[i].v] = Map[i].disten;

    //heap.push(Map[i]);
    que.add(Map[i]);
  }
  //while(heap.n>0){
  while(!que.isEmpty()){
    //temp.copy(heap.front());
    temp.copy((node)que.element());
    que.remove();
    //  heap.pop();

    if(meat[temp.v]==temp.disten){
        for(int i=Map[temp.v].next;i>=0;i=Map[i].next){
            if(meat[Map[i].v]>temp.disten+Map[i].disten){
                meat[Map[i].v] = temp.disten+Map[i].disten;
        //heap.push(new node(Map[i].v,-1,meat[Map[i].v]));
                que.add(new node(Map[i].v,-1,meat[Map[i].v]));
            }
        }
    }
  }

    return meat[t];
 }
}

public class Main {

 static public void main(String[]args)throws Exception{

 StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

 int n,m,u,v,disten;
 Graph obj;

 n = Get_Num(cin);
 m = Get_Num(cin);

 obj = new Graph(n);

  for(int i=0;i< m;++i){
    u = Get_Num(cin);
    v = Get_Num(cin);
    disten = Get_Num(cin);
    obj.add_edge(u, v, disten);
  }

    System.out.println(obj.get_Dijkstra(1,n));
 }

    static int Get_Num(StreamTokenizer cin)throws Exception{
        cin.nextToken();
        return (int) cin.nval;
    }
}
