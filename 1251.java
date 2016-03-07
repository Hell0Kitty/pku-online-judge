import java.io.BufferedInputStream;   
import java.util.Collections;   
import java.util.HashMap;   
import java.util.Iterator;   
import java.util.LinkedList;   
import java.util.Map.Entry;   
import java.util.Scanner;   
  
  
/*  
 * To change this template, choose Tools | Templates  
 * and open the template in the editor.  
 */  
/**  
 * poj1251  
 * 终于过了，以后还是不要用nextLine了，用这个再去spilt很容易就错了的。  
 * 之前做过一道题，出错是因为nextLine和nextInt混用了。  
 * 我把它拿到zoj去上交时，却编译不过。最后才去掉所有注释才过了。  
 * @author NC  
 */  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));   
        while (scanner.hasNext()) {   
            int n = scanner.nextInt();   
            if (n == 0) {   
                break;   
            }   
            String a;   
            LinkedList<Edge> graph = new LinkedList();   
            for (int i = 0; i < n - 1; i++) {   
                a = scanner.next("[A-Z]");   
                int m = scanner.nextInt();   
                int j = 0;   
                while (j < m) {   
                    String b = scanner.next("[A-Z]");   
                    int value = scanner.nextInt();   
                    graph.add(new Edge(a, b, value));   
                    j++;   
                }   
            }   
            LinkedList<Edge> l = Kruskal(graph);   
            Iterator<Edge> ite = l.iterator();   
            Integer sum = 0;   
            while (ite.hasNext()) {   
                Edge e = ite.next();   
                sum = sum + e.getValue();   
            }   
            System.out.println(sum);   
        }   
    }   
  
    static LinkedList<Edge> Kruskal(LinkedList graph) {   
        Collections.sort(graph);   
        LinkedList<Edge> g = new LinkedList();   
        HashMap<String, Integer> vertexes = new HashMap<String, Integer>();   
        Iterator<Edge> it = graph.iterator();   
        Integer tree = 0;   
        while (it.hasNext()) {   
            Edge e = it.next();   
            if (g.size() == 0) {   
                g.add(e);   
                vertexes.put(e.getVertex1(), tree);   
                vertexes.put(e.getVertex2(), tree);   
            } else {   
                if (!vertexes.containsKey(e.getVertex1()) && vertexes.containsKey(e.getVertex2())) {   
                    //有一个顶点已经添加过，直接把边加进去   
                    g.add(e);   
                    vertexes.put(e.getVertex1(), vertexes.get(e.getVertex2()));   
  
                } else if (vertexes.containsKey(e.getVertex1()) && !vertexes.containsKey(e.getVertex2())) {   
                    //有一个顶点已经添加过，直接把边加进去   
                    g.add(e);   
                    vertexes.put(e.getVertex2(), vertexes.get(e.getVertex1()));   
                } else if (!vertexes.containsKey(e.getVertex1()) && !vertexes.containsKey(e.getVertex2())) {   
                    //两个顶点都没有增加过，故增加一棵树   
                    g.add(e);   
                    tree++;   
                    vertexes.put(e.getVertex1(), tree);   
                    vertexes.put(e.getVertex2(), tree);   
                } else if (vertexes.get(e.getVertex1()) != vertexes.get(e.getVertex2())) {   
                    //两个顶点都加过了，如果不是同一棵树的话   
                    g.add(e);   
                    //合并两棵树   
                    vertexes = MergeTwoTrees(vertexes, e.getVertex1(), e.getVertex2());   
                }   
            }   
        }   
        return g;   
    }   
  
    static HashMap<String, Integer> MergeTwoTrees(HashMap<String, Integer> vertexes, String v1, String v2) {   
        HashMap<String, Integer> hm = new HashMap<String, Integer>();   
        Integer a = vertexes.get(v1);   
        Integer b = vertexes.get(v2);   
        Iterator it = vertexes.entrySet().iterator();   
        while (it.hasNext()) {   
            Entry entry = (Entry) it.next();   
            String key = (String) entry.getKey();   
            Integer value = (Integer) entry.getValue();   
            if (b == value) {   
                value = a;   
            }   
            hm.put(key, value);   
        }   
        return hm;   
    }   
}   
  
class Edge implements Comparable {   
  
    private String vertex1;   
    private String vertex2;   
    private Integer value;   
  
    public Edge(String vertex1, String vertex2, Integer value) {   
        this.vertex1 = vertex1;   
        this.vertex2 = vertex2;   
        this.value = value;   
    }   
  
    public int getValue() {   
        return value;   
    }   
  
    public void setValue(int value) {   
        this.value = value;   
    }   
  
    public String getVertex1() {   
        return vertex1;   
    }   
  
    public void setVertex1(String vertex1) {   
        this.vertex1 = vertex1;   
    }   
  
    public String getVertex2() {   
        return vertex2;   
    }   
  
    public void setVertex2(String vertex2) {   
        this.vertex2 = vertex2;   
    }   
  
    public int compareTo(Object o) {   
        Edge e = (Edge) o;   
        return this.value - e.getValue();   
    }   
}  
