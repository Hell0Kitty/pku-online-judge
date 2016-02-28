import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Main {
 public static void main(String[] args) throws NumberFormatException, IOException {
  BufferedReader re=new  BufferedReader(new InputStreamReader(System.in) );
  int T=Integer.parseInt(re.readLine());
  for(int i=1;i<=T;i++)
  {   int n=0,last=0;
    boolean[] use=new boolean[300010];
    Set strset=new TreeSet();
      for(int p=0;p<3;p++)
      {
   String str=re.readLine().toLowerCase();
   str=str.replaceAll("[^a-zA-Z]+"," ").trim();//"[^a-zA-Z]+"匹配非字母字符串
   String[] sa=str.split(" ");
   for(int j=0;j<sa.length&&strset.size()<=3;j++,n++)
   {
    String te=sa[j];
    if(p==0||p==1&&use[n])
    {
     int next=n+te.length();
     use[next]=true;
     last=Math.max(last,next);
    }
    if(p==2&&use[n])
    {
     strset.add(te);
    }
   }
      }
      System.out.println("Scenario #"+i+":");
   if(last>=n)
    strset.add("-outside-");
   if(strset.size()>3)
    System.out.println("-too many-");
   else
   {
    Iterator it=strset.iterator();
    while(it.hasNext())
    
     System.out.println(it.next());
    
   }
   System.out.println();
      }
 
 }

}
