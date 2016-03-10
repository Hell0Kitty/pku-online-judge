//* @author
import java.util.*;
import java.io.*;

class Main
{
 static int armor[];
 final static int MAX = 1000000;
 static class Node
 {
    Node l = null, r = null;
    int flag, step, value;
    Node(int k, int v)
    {
         flag = 0;
     step = MAX;
     value = v;
     if(k>=0&&v<=30)
     {
        l = new Node(k, v+armor[k]);
        r = new Node(k-1, v);
     }
    }


  int update(int f, int v, int s)
  {
    if(value>v||l==null&&r==null)return MAX;
    if(f==flag)step = Math.min(s, step);
    else step = s;
    s = step;
    flag = f+1;
    //System.err.println(value+":"+s);
    if(value==v)return s;
    return step = Math.min(l.update(f, v, s+1)+1, r.update(f, v, s));
  }
  int query(int v)
  {
    if(l==null&&r==null)return MAX;
    if(value==v)return step;
    return Math.min(l.query(v), r.query(v));
  }
 }

 public static void main(String[] args) throws IOException
 {
  Scanner in = new Scanner(System.in);
  for(int T = in.nextInt(); T!=0; --T)
  {
    int n = in.nextInt();
    armor = new int[n];
    for(int i=0; i!=n; ++i)
        armor[i] = in.nextInt();
    Arrays.sort(armor);
    int cnt=0;
    Node root = new Node(n-1, 0);
    root.step = 0;
    int k = 0, m = in.nextInt();
    for(int i=0; i!=m; ++i)
        root.update(cnt++, k=in.nextInt(), MAX);
    k = root.query(k);
    if(k==MAX)System.out.println(-1);
    else System.out.println(k);
    }
  }
}

