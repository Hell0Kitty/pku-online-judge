import java.io.PrintWriter; 
import java.math.BigInteger;
 import java.util.Collections; 
import java.util.Comparator; 
import java.util.HashMap; 
import java.util.HashSet; 
import java.util.Map; 
import java.util.PriorityQueue;
 import java.util.Scanner; 
import java.util.Set; 
import java.util.regex.Matcher;
 import java.util.regex.Pattern;
 public class Main { 
 Scanner cin = new Scanner(System.in);
 PrintWriter out=new PrintWriter(System.out,true);
 public void solve() {
int maxCost,removeLen; 
String op; 
while(cin.hasNext()) {
 maxCost=cin.nextInt();
 removeLen=cin.nextInt(); 
int [] list=new int[removeLen];
 for(int i=0; i<removeLen; i++) 
list[i]=cin.nextInt();
 PriorityQueue<Integer> minQ=new PriorityQueue<Integer>();
 PriorityQueue<Integer> maxQ=new PriorityQueue<Integer>(1000,Collections.reverseOrder());
 int state=1,cost,step=1,flagRemove=0,temp; op=cin.next();
 while(!op.equals("e")) {
 if(op.equals("a")) {
 cost=cin.nextInt();
 maxQ.add(cost);
 minQ.add(cost);
 } else if(op.equals("r")) {
   if(maxQ.isEmpty()) //empty 
    out.println("-1");
 else //not empty 
 { 
  if(state==1){
 temp=minQ.poll(); 
maxQ.remove(temp);  
} else {
 temp=maxQ.poll();
 minQ.remove(temp); 
} 
if(flagRemove<removeLen&&step==list[flagRemove]) //show 
{ 
out.println(temp); 
flagRemove++; 
} 
} step++; 
} else // op==p 
{ 
state=cin.nextInt();
 } 
op=cin.next();
 } 
out.println("");
 } 
out.close();
 }
 public static void main(String[] args) {
 Main m = new Main(); 
m.solve();
 }
 } 