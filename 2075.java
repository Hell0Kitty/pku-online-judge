//* @author: SmilingWang
import java.util.*;
public class Main {
  public static final int BLOCK = Integer.MAX_VALUE;
  public static final double zero = 1e-6;
  public static double cl;
  public static void main(String[] args){
    Scanner in = new Scanner(System.in);
    cl = in.nextDouble();
    int pn = in.nextInt();
    double w[][] = new double[pn+1][pn+1];
    for(int i = 1; i <= pn; i++){
        for(int j = 1; j <= pn; j++){
            if(j == i){
                continue;
            }
            w[i][j] = BLOCK;
        }
    }
    Map< String, Integer> map = new HashMap< String, Integer>();
    for(int i = 1; i <= pn; i++){
        String s = in.next();
        map.put(s, i);
    }
    int en = in.nextInt();
    for(int i = 1; i <= en; i++){
        String s1 = in.next();
        String s2 = in.next();
        int i1 = map.get(s1);
        int i2 = map.get(s2);
        w[i1][i2] = in.nextDouble();
        w[i2][i1] = w[i1][i2];
    }
    prim(w, pn);
   }

   public static void prim(double[][] w, int n){
    int nearest[] = new int[n+1];
    double distance[] = new double[n+1];
    int vnear = 0;

    Set< Edge> set = new HashSet< Edge>();
    for(int i = 2; i <= n; i++){
        nearest[i] = 1;
        distance[i] = w[1][i];
    }
    for(int v = 2; v <= n; v++){
        double min = BLOCK;
        for(int i = 2; i <= n; i++){
          if(distance[i] >= zero && distance[i] < min){
            vnear = i;
            min = distance[i];
          }
        }
        Edge edge  = new Edge(nearest[vnear], vnear, w[vnear][nearest[vnear]]);
        set.add(edge);
        distance[vnear] = -1;
        for(int i = 2; i <= n; i++){
           if(w[i][vnear] < distance[i]){
            distance[i] = w[i][vnear];
            nearest[i] = vnear;
           }
        }
    }
    //System.out.println(set);
    Iterator< Edge> itr = set.iterator();
    double cost = 0;
    String out = "";
    while(itr.hasNext()){
        cost += (itr.next().weight);

    }
    //System.out.println(out);
    if(cost - cl <= zero){
        System.out.printf("Need %.1f miles of cable\n",cost);
    }
    else{
        System.out.println("Not enough cable");
    }
   }
}

class Edge{
    int sv;
    int ev;
    double weight;

    public Edge(int sv, int ev, double w){
        this.sv = sv;
        this.ev = ev;
        this.weight = w;
    }
    public String toString(){
        return sv + " " + ev + " " + weight + " ";
    }
}


