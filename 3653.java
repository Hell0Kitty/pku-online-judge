//* @author: SmilingWang
import java.util.*;
import java.io.*;

public class Main {
 static final int INF = 100000000;
 public static void main(String[] args){
   Scanner in = new Scanner(new BufferedInputStream(System.in));
   int x = in.nextInt();
   int y = in.nextInt();
   while(x != 0 || y != 0){
    int w[][] = new int[(x+1)*(y+1)+1][(x+1)*(y+1)+1];
    //int num = 1;
    int row = 1;
    for(int i = 1; i <= 2*x+1; i++){
        if(i % 2 == 1){
       //num = (row-1)*(y+1) + 1;
       for(int j = 1; j <= y; j++){
        int tm = in.nextInt();
        String tms = in.next();

        if(tms.equals("*")){
          w[(row-1)*(y+1)+j][(row-1)*(y+1)+j+1] = tm;
          w[(row-1)*(y+1)+j + 1][(row-1)*(y+1)+j] = tm;
        }
        else if(tms.equals("< ")){
          w[(row-1)*(y+1)+j + 1][(row-1)*(y+1)+j] = tm;
        }
        else if(tms.equals(">")){
          w[(row-1)*(y+1)+j][(row-1)*(y+1)+j+1] = tm;
        }
        }
        row++;
      }
     else{
       for(int j = 1; j <= y + 1; j++){
        int tm = in.nextInt();
        String tms = in.next();

          if(tms.equals("*")){
        w[(row-2)*(y+1) + j][(row-1)*(y+1) + j] = tm;
        w[(row-1)*(y+1) + j][(row-2)*(y+1) + j] = tm;
       }
      else if(tms.equals("^")){
        w[(row-1)*(y+1) + j][(row-2)*(y+1) + j] = tm;
      }
      else if(tms.equals("v")){
        w[(row-2)*(y+1) + j][(row-1)*(y+1) + j] = tm;
      }
    }
    }
   }
  for(int p = 1; p <= (x+1)*(y+1); p++){
   for(int q = 1; q <= (x+1)*(y+1); q++){
    if(p == q){
         continue;
    }
    if(w[p][q] > 0){
      w[p][q] = 2520/w[p][q];
      continue;
    }
    w[p][q] = INF;
     }
   }

   dijkstra(w, (x+1)*(y+1));
   x = in.nextInt();
   y = in.nextInt();
 }
}

public static void dijkstra(int w[][], int v){
  int i, vnear = 0;
  int touch[] = new int[v+1];
  int length[] = new int[v+1];
  boolean y[] = new boolean[v+1];
  int map[] = new int[v+1];
  PriorityQueue< Item> heap = new PriorityQueue< Item>(v, new ItemCompare());

  for(i = 2; i <= v; i++){
   length[i] = w[1][i];
   if(length[i] < INF){
    heap.add(new Item(1, i, w[1][i]));
   }
  }
  //System.out.println(heap);
  while(!heap.isEmpty()){
    Item temp = heap.remove();

    for(i = 1; i <= v; i++){
        if(i == temp.sv){
        continue;
      }
      else if(w[temp.ev][i] == INF){
        continue;
      }
      if(length[temp.ev] + w[temp.ev][i] < length[i]){
       length[i] = length[temp.ev] + w[temp.ev][i];
       heap.add(new Item(temp.ev, i, length[i]));
      }
     }
    }
    if(length[v] < INF){
      System.out.println(length[v] + " blips");
    }
    else{
      System.out.println("Holiday");
    }
    }

}

class Item{
 int sv;
 int ev;
 int w;

 Item(int sv, int ev, int w){
    this.sv = sv;
    this.ev = ev;
    this.w  = w;
   }

  public String toString(){
    return this.sv + " " + this.ev +" " + this.w;
  }
}

class ItemCompare implements Comparator< Item>{
    public int compare(Item i1, Item i2){
        return (i1.w - i2.w);
    }
}

