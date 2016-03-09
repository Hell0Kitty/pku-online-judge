import java.io.*;
import java.util.*;
import java.util.Map.Entry;
public class Main
{
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  HashMap< Integer,Integer> ts=new HashMap< Integer,Integer>();
  while(true)
  {
   String[] ss=in.readLine().split(" ");
   int x=Integer.parseInt(ss[0]);
   int y=Integer.parseInt(ss[1]);
   if(x==0&&y==0)break;
   for(int i=0;i< x;i++)
   {
    ss=in.readLine().split(" ");
    for(int j=0;j< y;j++)
    {
      int u=Integer.parseInt(ss[j]);
      ts.put(u, ts.containsKey(u)?ts.get(u)+1:1);
    }
    }
    List< Map.Entry< Integer, Integer>> ww=
           new ArrayList< Map.Entry< Integer, Integer>>(ts.entrySet());
    Collections.sort(ww,new Comparator< Map.Entry< Integer, Integer>>(){

    @Override
    public int compare(Entry< Integer, Integer> arg0,
    Entry< Integer, Integer> arg1) {
      int r1=arg1.getValue();
      int r0=arg0.getValue();
      if(r1!=r0) return r1-r0;
      else return arg0.getKey()-arg1.getKey();
        }
     });
    int k=ww.get(1).getValue();
    System.out.print(ww.get(1).getKey());
    for(int i=2;i< ww.size();i++)
    {
      if(ww.get(i).getValue()==k) System.out.print(" "+ww.get(i).getKey());
      else break;
    }
    System.out.println();
    ts.clear();
  }
 }
}

