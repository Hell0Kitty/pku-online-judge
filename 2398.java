import java.io.*;
import java.util.Map;
import java.util.TreeMap;

public class Main {

 public static void main(String[] args) throws Exception{
   BufferedReader br = new BufferedReader(new
                InputStreamReader(System.in));
   int n, m, y1, y2, i, t;
   String s;
   String[] ss;
   Point p,p2;
   while((s=br.readLine())!=null&&!s.equals("0")){
        ss = s.split(" ",6);
        n=parseInt(ss[0]);
        m=parseInt(ss[1]);
        y1=parseInt(ss[3]);
        y2=parseInt(ss[5]);
        LineSet ls = new LineSet(n);
        Statistics st = new Statistics();
        for(i=0;i< n;i++){
          s=br.readLine();
	   ss=s.split(" ",2);
	   t=parseInt(ss[0]);
	   p=new Point(t,y1);
	   p2=new Point(parseInt(ss[1]),y2);
	   ls.add(t,new Line(p,p2));
	 }
	 for(i=0;i< m;i++){
	   s=br.readLine();
	   ss=s.split(" ",2);
	   t=ls.binFind(new Point(parseInt(ss[0]),parseInt(ss[1])));
	   st.register(t);
	}
	    st.printFre();
        }
        br.close();
	}

  static int parseInt(String s){
   if(s.startsWith("-"))
      return -parseInt(s.substring(1));
   int t = 0;
   for(char ch: s.toCharArray()){
      t *= 10;
      t += ch-'0';
   }
   return t;
  }
}

class Statistics{
 Map< Integer,Integer> map=new TreeMap< Integer,Integer>();
 Map< Integer,Integer> fre=new TreeMap< Integer,Integer>();
 void register(int x){
   Integer t = map.get(x);
   if(t==null){
	map.put(x, 1);
	Integer t2 = fre.get(1);
	if(t2==null){
         fre.put(1, 1);
	}
	else{
	  fre.put(1, t2+1);
	}
    }
    else{
	map.put(x, t+1);
	Integer t2 = fre.get(t);
	fre.put(t, t2-1);
	t2 = fre.get(t+1);
	if(t2==null){
	  fre.put(t+1, 1);
	}
	else{
	  fre.put(t+1, t2+1);
	}
    }
  }

void printFre(){
  System.out.println("Box");
  int t;
  for(Map.Entry< Integer, Integer> me: fre.entrySet()){
	if((t=me.getValue())>0)
         System.out.println(me.getKey()+": "+t);
  }
 }
}
class LineSet{
  Map< Integer,Line> mil;
  Object[] lines;
  LineSet(int n){
	mil = new TreeMap< Integer,Line>();
  }

  void add(int key, Line line){
	mil.put(key, line);
  }
	//Binary search method
  int binFind(Point p){
    lines=mil.values().toArray();
    int i=binFind0(p,0,lines.length-1);
    return i;
  }

 private int binFind0(Point p, int left, int right){
   if(p.compareTo((Line)lines[left])< 0)
	return left;
   if(p.compareTo((Line)lines[right])>0)
	return right+1;
  int mid = (left+right)/2;
  if(p.compareTo((Line)lines[mid])< 0)
	return binFind0(p,left,mid-1);
  else return binFind0(p,mid+1,right);
 }
}

class Point implements Comparable< Line>{

 int x;
 int y;
 Point(int x,int y){
   this.x=x;
   this.y=y;
  }
  @Override
  public int compareTo(Line line) {
	return x*line.x0+y*line.y0+line.c;
  }
}

class Line{
  //x0 must be positive
  int x0;
  int y0;
  int c;
  //p must be up, p2 must be down
  Line(Point p, Point p2){
    x0=p.y-p2.y;
    y0=p2.x-p.x;
    c=-(p.x*x0+p.y*y0);
  }

  @Override
   public String toString(){
	return "Line: "+x0+"x+"+y0+"y+"+c+"=0.";

  }
}

