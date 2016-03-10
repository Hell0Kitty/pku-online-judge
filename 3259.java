//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
class edge{
    int s,t,l;
    public void set(int _s,int _t,int _l){
        this.s = _s;
        this.t = _t;
        this.l = _l;
    }
}
public class Main {
    static int M = 6000,N = 500+20,Inf = 1000000000+10;
    static edge e[] =  new edge[M];
    static void start(){
        for(int i=0;i< M;++i)
            e[i] = new edge();
    }

static boolean Bellman_Ford(int n,int m,int d[],int s,edge e[]){
  int i,j;
  boolean flag;
  for(i=0;i<=n;++i) d[i] = Inf;
  d[s] = 0;
  for(i=0;i<=n;++i){
    flag = false;
    for(j=0;j< m;++j){
        if(d[e[j].t]>d[e[j].s]+e[j].l){
            d[e[j].t] = d[e[j].s]+e[j].l;
            flag = true;
        }
    }
    if(!flag) break;
   }
   for(i=0;i< m;++i)
    if(d[e[i].t]>d[e[i].s]+e[i].l) return false;
   return true;
}

public static void main(String[]args) throws Exception{
  int d[] = new int[N];
  int n,m,w,i,s,t,l,top,F;
  start();
  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));

  F = Get_Num(cin);
  while(F--!=0){
    top = 0;
    n = Get_Num(cin);
    m = Get_Num(cin);
    w = Get_Num(cin);
    for(i=0;i< m;++i){
        s = Get_Num(cin);
        t = Get_Num(cin);
        l = Get_Num(cin);

        e[top++].set(s, t, l);
        e[top++].set(t, s, l);
    }
    for(i=0;i< w;++i){
        s = Get_Num(cin);
        t = Get_Num(cin);
        l = Get_Num(cin);
        e[top++].set(s, t, -l);
    }
    for(i=1;i<=n;++i){
        e[top++].set(0,i,0);
    }
    if(Bellman_Ford(n,top,d,0,e))
        System.out.println("NO");
    else System.out.println("YES");
   }

  }
    static int Get_Num(StreamTokenizer cin)throws Exception{
        cin.nextToken();
        return (int)cin.nval;
    }
}

