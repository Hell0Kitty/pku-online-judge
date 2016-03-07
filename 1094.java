import java.io.BufferedInputStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        int n;
        int m;
        int flag = 0;
        while (true) {
            int i = 0;
            String printString = null;
            String[] s = scanner.nextLine().split(" ");
            n = Integer.parseInt(s[0]);
            m = Integer.parseInt(s[1]);
            if (m == 0 && n == 0) {
                break;
            }
            Graph graph = new Graph(n);
            for (i = 0; i < m; i++) {
                flag = 0;
                s = scanner.nextLine().split(" <");
                char a = s[0].charAt(0);
                char b = s[1].charAt(0);
                graph.addCurrentNumberOfVertex(a, b);
                graph.addArcNode(a, b);
                printString = topologicalOrder(graph, i + 1);
                if (printString.startsWith("*")) {
                    if (printString.length() - 1 == graph.getNumberOfVertex()) {
                        flag = 2;
                        break;
                    }
                    if (i == m - 1) {
                        printString = "Sorted sequence cannot be determined.";
                        flag = 1;
                        break;
                    }
                }
                if (printString.equals("Sorted sequence cannot be determined.")) {
                    if (graph.hasLoop()) {
                        printString = "Inconsistency found after " + (i + 1) + " relations.";
                        flag = 1;
                        break;
                    } else if (i == m - 1) {
                        flag = 1;
                        break;
                    }
                }
                if (printString.startsWith("Inconsistency")) {
                    flag = 1;
                    break;
                }
                recoverGraph(graph);
            }
            int j;
            if (i == m) {
                j = i;
            } else {
                j = i + 1;
                i++;
            }
            while (i < m) {
                scanner.nextLine();
                i++;
            }
            if (flag == 1) {
                System.out.println(printString);
            } else if (flag == 2) {
                String ss = "Sorted sequence determined after "
                        + j + " relations: "
                        + printString.substring(1, printString.length());
                System.out.println(ss + ".");
            }
        }
    }

    static String topologicalOrder(Graph graph, int m) {
        int index = graph.judge0InDegree();
        String print = "";
        while (index >= 0) {
            print += graph.deleteNode(index);
            graph.deleteSide(index);
            index = graph.judge0InDegree();
        }
        if (print.length() < graph.getCurrentNumberOfVertex()) {
            String s = null;
            if (index == -2)
            {
                s = "Sorted sequence cannot be determined.";
            }
            if (index == -1)
            {
                s = "Inconsistency found after " + m + " relations.";
            }
            return s;
        } else {
            String s = "*";
            return s + print;
        }
    }

    static void recoverGraph(Graph graph) {
        ArrayList< Vertex> al = graph.getVertexes();
        for (Vertex v : al) {
            if (v.isVisited()) {
                v.setVisited(false);
                v.setExisted(true);
                LinkedList< Vertex> lk = v.getArcNode();
                if (lk != null) {
                    int in = (lk.getFirst()).getInDegree();
                    for (Vertex vv : lk) {
                        graph.getVertexes().get(vv.getData() - 'A').addInDegree();
                    }
                }
            }
        }
    }
}

class Vertex {

    private boolean existed;
    private boolean visited;
    private int inDegree;
    private char data;
    private LinkedList< Vertex> arcNode;

    public boolean isExisted() {
        return existed;
    }

    public void setExisted(boolean existed) {
        this.existed = existed;
    }

    public boolean isVisited() {
        return visited;
    }

    public void setVisited(boolean visited) {
        this.visited = visited;
    }

    public Vertex(int inDegree, char data, LinkedList arcNode,
            boolean visited, boolean existed) {
        this.inDegree = inDegree;
        this.data = data;
        this.arcNode = arcNode;
        this.visited = visited;
        this.existed = existed;
    }

    public LinkedList< Vertex> getArcNode() {
        return arcNode;
    }

    public void setArcNode(LinkedList arcNode) {
        this.arcNode = arcNode;
    }

    public char getData() {
        return data;
    }

    public void setData(char data) {
        this.data = data;
    }

    public int getInDegree() {
        return inDegree;
    }

    public void setInDegree(int inDegree) {
        this.inDegree = inDegree;
    }

    public void addInDegree() {
        this.inDegree++;
    }

    public void reduceInDegree() {
        this.inDegree--;
    }
}

class Graph {

    private ArrayList vertexes;
    private int numberOfVertex;
    private int currentNumberOfVertex;

    public Graph(int n) {
        this.numberOfVertex = n;
        this.vertexes = new ArrayList(n);
        this.currentNumberOfVertex = 0;
        init();
    }

    public int getCurrentNumberOfVertex() {
        return currentNumberOfVertex;
    }

    public void addCurrentNumberOfVertex(char a, char b) {
        if (!this.vertexes.get(a - 'A').isExisted()) {
            this.currentNumberOfVertex++;
            this.vertexes.get(a - 'A').setExisted(true);
        }
        if (!this.vertexes.get(b - 'A').isExisted()) {
            this.currentNumberOfVertex++;
            this.vertexes.get(b - 'A').setExisted(true);
        }
    }

    public int getNumberOfVertex() {
        return numberOfVertex;
    }

    public void setNumberOfVertex(int numberOfVertex) {
        this.numberOfVertex = numberOfVertex;
    }

    public ArrayList getVertexes() {
        return vertexes;
    }

    public void setVertexes(ArrayList vertexes) {
        this.vertexes = vertexes;
    }

    void init() {
        for (int i = 0; i < this.numberOfVertex; i++) {
            char c = (char) ('A' + i);
            Vertex v = new Vertex(0, c, null, false, false);
            vertexes.add(v);
        }
    }

    public void addArcNode(char end, char head) {
        boolean isAdd = true;
        LinkedList< Vertex> lk = this.vertexes.get(end - 'A').getArcNode();
        if (lk != null) {
            for (Vertex v : lk) {
                if (v.getData() == head) {
                    isAdd = false;
                }
            }
        }

        if (isAdd) {
            this.vertexes.get(head - 'A').addInDegree();
            Vertex v = new Vertex(this.vertexes.get(head - 'A').getInDegree(),
                    head, null, false, true);
            LinkedList firstArcNode = this.vertexes.get(end - 'A').getArcNode();
            if (firstArcNode == null) {
                firstArcNode = new LinkedList();
            }
            firstArcNode.addLast(v);
            this.vertexes.get(end - 'A').setArcNode(firstArcNode);
        }
    }

    public int judge0InDegree() {
        int flag = 0;
        int index = 0;
        for (int i = 0; i < this.numberOfVertex; i++) {
            if (this.vertexes.get(i).isExisted() == true
                    && this.vertexes.get(i).isVisited() == false
                    && this.vertexes.get(i).getInDegree() == 0) {
                flag++;
                index = i;
            }
        }
        switch (flag) {
            case 0:
                return -1;
            case 1:
                return index;
            default:
                return -2;
        }
    }

    public int getNext0InDegree() {
        boolean hasVertex = false;
        int i;
        for (i = 0; i < this.numberOfVertex; i++) {
            if (this.vertexes.get(i).isExisted() == true) {
                hasVertex = true;
                if (this.vertexes.get(i).isVisited() == false
                        && this.vertexes.get(i).getInDegree() == 0) {
                    return i;
                }
            }
        }
        if (hasVertex && this.numberOfVertex == i) {
            return -1;
        } else {
            return -2;
        }
    }

    public boolean hasLoop() {
        int ind;
        int i = this.getCurrentNumberOfVertex();
        while (i > 0) {
            ind = this.getNext0InDegree();
            if (ind == -1) {
                return true;
            }
            if (ind == -2) {
                return false;
            }
            this.deleteNode(ind);
            this.deleteSide(ind);
            i--;
        }
        return false;
    }

    public void deleteSide(int index) {
        LinkedList< Vertex> lk = this.vertexes.get(index).getArcNode();
        if (lk != null) {
            for (Vertex arcV : lk) {
                this.vertexes.get(arcV.getData() - 'A').reduceInDegree();
            }
        }
    }

    public char deleteNode(int index) {
        char c = 0;
        this.vertexes.get(index).setExisted(false);
        this.vertexes.get(index).setVisited(true);
        c = this.vertexes.get(index).getData();
        return c;
    }
}


