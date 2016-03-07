import java.util.*;

public class Main{
  public static void main(String[] args){
   Scanner in = new Scanner(System.in);
   int n;
   n = in.nextInt();
  Interval intervals[] = new Interval[n];
  for(int i = 0; i < n; i++){
    int x = in.nextInt();
    int y = in.nextInt();
    intervals[i] = new Interval(x, y);
   }
   qsort(intervals, 0, n-1);
   //Arrays.sort(intervals);
   //System.out.println(Arrays.toString(intervals));
   int st = intervals[0].s;
   int ed = intervals[0].e;
  for(int i = 0; i < n; i++){
	if(st >= intervals[i].s && st <= intervals[i].e){
         st = intervals[i].s;
	}
	if(ed >= intervals[i].s && ed <= intervals[i].e){
	  ed = intervals[i].e;
	}
	else if(ed < intervals[i].s){
	  System.out.println(st + " " + ed);
	  st = intervals[i].s;
	  ed = intervals[i].e;
	}
   }
   System.out.println(st + " " + ed);
 }

 public static void qsort(Interval arr[], int l0, int h0){
   int l = l0;
   int h = h0;
  Interval mid = arr[(l+h)/2];
		
  while(l<=h){
    while(l< h0 && arr[l].compareTo(mid) < 0)
	l++;
    while(h>l0 && arr[h].compareTo(mid) > 0)
	--h;
    if(l <= h){
	Interval temp = new Interval(arr[l].s, arr[l].e);
	arr[l].s = arr[h].s;
	arr[l].e = arr[h].e;
	arr[h].s = temp.s;
	arr[h].e = temp.e;
	l++;
	h--;
     }
    }
   if(l < h0)
	qsort(arr, l, h0);
		
   if(h > l0)
	qsort(arr, l0, h);
  }
}

class Interval implements Comparable{
  int s;
  int e;
  public Interval(int s, int e){
	this.s = s;
	this.e = e;
  }

  public int compareTo(Interval rhs){
    if(s == rhs.s){
	return e - rhs.e;
    }
    else{
	return s - rhs.s;
     }
   }

   public String toString(){
	return s + " " + e;
  }
}

