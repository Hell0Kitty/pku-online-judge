import java.util.*;
public class Main implements Comparator<Integer> { 
  static class Edge{  
   int e,c;
   Edge next;
   Edge rev;  
  public void dec(int f){
   c-=f;
   rev.c+=f;
  }
 }

 int n,m,src,tag;
 final Edge[] g=new Edge[200];
 final int[] h=new int[200];  final int[] ex=new int[200];
 final Scanner sc=new Scanner(System.in);
 final PriorityQueue<Integer> pq=new PriorityQueue<Integer>(200,this);

 boolean init(){ 
   if(!sc.hasNext()) return false;
   m=sc.nextInt();
   n=sc.nextInt();
   src=0;   tag=n-1;
  for(int i=0;i!=n;++i){
   g[i]=null;
   h[i]=0;
   ex[i]=0;
   }

  h[src]=n;
  for(int i=0;i!=m;++i){
   int a=sc.nextInt()-1,b=sc.nextInt()-1,c=sc.nextInt();
   Edge e0=addEdge(a, b, c),e1=addEdge(b,a,0);
   e0.rev=e1;e1.rev=e0;
  }    return true; 
 }

  private Edge addEdge(int s, int e, int c) {
   Edge n=new Edge();
   n.c=c;
   n.e=e;
   n.next=g[s];
   g[s]=n;
  return n;
  }

  int work(){
   for(Edge e=g[src];e!=null;e=e.next){
    ex[e.e]+=e.c;
    e.dec(e.c);
    if(e.e!=src&&e.e!=tag){
     pq.add(e.e);
   }
  }
  while(pq.size()>0){
   int v=pq.poll();
   int exv=ex[v],hv=h[v];
   for(Edge e=g[v]; exv>0&&e!=null; e=e.next){        if(e.c<=0 || hv !=h[e.e]+ 1 ) continue;
    int f=Math.min( exv , e.c);
    ex[e.e]+=f;
    exv-=f;
    e.dec(f);
    if(ex[e.e]==f&&e.e!=tag&&e.e!=src){
     pq.add(e.e);
    }
   }
   if(exv>0){
    for(Edge e=g[v];e!=null;e=e.next){
     if(e.c > 0 && hv>h[e.e]){
      hv=h[e.e];
     }
    }
    ++hv;
    pq.add(v);
   }
   ex[v]=exv;
   h[v]=hv;
  }
  return ex[tag];
 }

  void go(){     while(init()){
    System.out.println( work());
  }
  }

  public static void main(String[] args) {
    new Main().go();
  }

  public int compare(Integer o1, Integer o2) {
   return h[o2]-h[o1];
  }
}