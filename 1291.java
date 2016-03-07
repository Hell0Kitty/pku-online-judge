import java.util.*;
import java.io.BufferedInputStream;

public class Main
{
    public static Node[] nodes;
    
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(new BufferedInputStream(System.in));
        while(true)
        {
            int n = sc.nextInt();
            if(n == 0)
            {
                break;
            }
            boolean consistent = true;
            nodes = new Node[n+1];
            for(int i = 1; i <= n; i++)//make set;
            {
                nodes[i] = new Node(i);
            }
            for(int i = 1; i <=n; i++)
            {
                sc.next();
                int j = sc.nextInt();
                sc.next();
                String falsehood = sc.next();
                falsehood = falsehood.substring(0,falsehood.length()-1);
                if(consistent)
                {
                    boolean unionOk = unionOne(i,j,Boolean.parseBoolean(falsehood));
                    if(!unionOk)
                    {
                        consistent = false;
                    }
                }
            }
            if(consistent)
            {
                int result = 0;
                for(int i = 1; i <= n; i++)
                {
                    if(nodes[i].parent == -1)
                    {
                        if(nodes[i].numOfTrue >= nodes[i].numOfFalse)
                        {
                            result += nodes[i].numOfTrue;
                        }else
                        {
                            result += nodes[i].numOfFalse;
                        }
                    }
                }
                System.out.println(result);
            }else
            {
                System.out.println("Inconsistent");
            }
        }
    }
    
    public static boolean unionOne(int i, int j, boolean falsehood)
    {
        int t1 = find(i);
        int t2 = find(j);
        boolean unionOk = true;
        if(t1 == t2)
        {
            if( (nodes[i].falsehood == true) != (nodes[j].falsehood == falsehood) )
            {
                unionOk = false;
            }
        }else
        {
            if(nodes[t2].num <= nodes[t1].num)
            {
                nodes[t2].parent = t1;
                /*for(int k : nodes[t2].nodes)
                {
                    nodes[k].parent = t1;
                }*/
                nodes[t1].num += nodes[t2].num;
                if( (nodes[i].falsehood == true) != (nodes[j].falsehood == falsehood) )
                {
                    for(int k : nodes[t2].nodes)
                    {
                        nodes[k].falsehood = !nodes[k].falsehood;
                    }
                    nodes[t1].numOfTrue += nodes[t2].numOfFalse;
                    nodes[t1].numOfFalse += nodes[t2].numOfTrue;
                }else
                {
                    nodes[t1].numOfTrue += nodes[t2].numOfTrue;
                    nodes[t1].numOfFalse += nodes[t2].numOfFalse;
                }
                
                nodes[t1].nodes.addAll(nodes[t2].nodes);
            }else
            {
                nodes[t1].parent = t2;
                /*for(int k : nodes[t1].nodes)
                {
                    nodes[k].parent = t2;
                }*/
                nodes[t2].num += nodes[t1].num;
                if( (nodes[i].falsehood == true) != (nodes[j].falsehood == falsehood) )
                {
                    for(int k : nodes[t1].nodes)
                    {
                        nodes[k].falsehood = !nodes[k].falsehood;
                    }
                    nodes[t2].numOfTrue += nodes[t1].numOfFalse;
                    nodes[t2].numOfFalse += nodes[t1].numOfTrue;
                }else
                {
                    nodes[t2].numOfTrue += nodes[t1].numOfTrue;
                    nodes[t2].numOfFalse += nodes[t1].numOfFalse;
                }
                nodes[t2].nodes.addAll(nodes[t1].nodes);
            }
        }
        return unionOk;
    }
    
    public static int find(int x)
    {
        Node r = nodes[x];
        while(r.parent != -1)
        {
            r = nodes[r.parent];
        }
        while(nodes[x].position != r.position)
        {
            int q = nodes[x].parent;
            nodes[x].parent = r.position;
            x = q;
        }
        return r.position;
    }
    
}

class Node
{
    int position;
    boolean falsehood;
    int parent;
    int num;
    int numOfTrue;
    int numOfFalse;
    LinkedList<Integer> nodes;
    
    public Node(int position)
    {
        this.position = position;
        this.falsehood = true;
        this.parent = -1;
        this.num = 1;
        this.numOfTrue = 1;
        this.numOfFalse = 0;
        this.nodes = new LinkedList<Integer>();
        this.nodes.add(position);
    }
}
