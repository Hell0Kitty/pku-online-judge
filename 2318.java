/* @author:zeropinzuo */
import java.io.*;
import java.util.*;

public class Main{
 static Scanner cin;
 public static void main(String args[]){
  cin = new Scanner(System.in);
  while(run() != false)
    ;
  }

static boolean run(){
   int n = cin.nextInt();
   if(n==0)
    return false;
   Box box = new Box(n, cin);
   System.out.println();
   return true;
 }
}

class Box{
  int n,m;
  int X1,Y1,X2,Y2;

  PartitionList pList;

  public Box(int n, Scanner cin){
    this.n = n;
    m = cin.nextInt();
    X1 = cin.nextInt();
    Y1 = cin.nextInt();
    X2 = cin.nextInt();
    Y2 = cin.nextInt();

    int[] map = new int[n+1];
    Partition.setBound(Y1, Y2);
    pList = new PartitionList(n);

    for(int i=0;i< n;i++){
    pList.add(new Partition(cin.nextInt(), cin.nextInt()));
    map[i] = 0;
    }
    map[n] = 0;

    for(int i=0;i< m;i++)
    map[pList.search(cin.nextInt(), cin.nextInt())]++;
    for(int i=0;i<=n;i++)
    System.out.println(i+": "+map[i]);
  }


}

class Partition{
  static int Y1, Y2;
  int U,L;

  public Partition(int U, int L){
    this.U = U;
    this.L = L;
  }

  static void setBound(int y1, int y2){
    Y1 = y1;
    Y2 = y2;
  }

 int compareTo(int X, int Y){
   double position = L+(double)(Y-Y2)*(U-L)/(Y1-Y2);
   if(X > position)
    return -1;
   else
    return 1;
 }
}

class PartitionList{
  Partition[] list;

  private int count=0;

  public PartitionList(int n){
    list = new Partition[n];
  }

  void add(Partition p){
    list[count++] = p;
  }

  int search(int X, int Y){
    if(list[0].compareTo(X, Y) == 1)
    return 0;
    else if(list[list.length-1].compareTo(X, Y) == -1)
    return list.length;
    else
    return find(0, list.length-1, X, Y);
   }


 private int find(int start, int end, int X, int Y){
   if((start+1)==end)
    return end;

   int mid = (start+end)/2;

   if(list[mid].compareTo(X, Y) == 1)
    return find(start, mid, X, Y);
   else
    return find(mid, end, X, Y);
 }
}

