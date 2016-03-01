import java.io.*;
import java.util.*;
import java.util.Map.Entry;
public class Main
{
 public static void main(String[] args) throws NumberFormatException, IOException
 {
  InputStreamReader is=new InputStreamReader(System.in);
  BufferedReader in=new BufferedReader(is);
  HashMap< String,Integer> ts=new HashMap< String,Integer>();
  while(true)
  {
   int a=Integer.parseInt(in.readLine());
   if(a==0)break;
   String k="";
   int t=0;
   for(int i=0;i< a;i++)
   {
	String s=k+in.readLine();
	for(int j=1;j< s.length();j++)
	{
          t++;
	  String w=s.substring(j-1,j+1);
	  ts.put(w, ts.containsKey(w)?ts.get(w)+1:1);
        }
	k=s.substring(s.length()-1);
    }
    List< Map.Entry< String, Integer>> ww=new ArrayList< Map.Entry< String, Integer>>(ts.entrySet());
    Collections.sort(ww,new Comparator< Map.Entry< String, Integer>>(){

    @Override
    public int compare(Entry< String, Integer> arg0,
	Entry< String, Integer> arg1) {
	int r1=arg1.getValue();
	int r0=arg0.getValue();
	if(r1!=r0)return r1-r0;
	else return arg0.getKey().compareTo(arg1.getKey());
    }
    });
   for(int i=0;i< 5;i++)
   {
	int u=ww.get(i).getValue();
	System.out.print(ww.get(i).getKey()+" "+u+" ");
	System.out.printf("%.6f\n",(double)u/(double)t);
   }
   System.out.println();
   ts.clear();
  }
 }
}

