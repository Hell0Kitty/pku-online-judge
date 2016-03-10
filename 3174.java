//* @author: ccQ.SuperSupper
import java.io.*;
import java.util.*;
class point{
    int x,y;
}

public class Main {
 static final int N = 770+10;
 static int n;
 static point way[] = new point[N];
 static void start(){
    int i;
    for(i=0;i< N;++i)
        way[i] = new point();
 }

public static void main(String[]args) throws Exception{

  start();
  int i,j,k,sum;
  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
  PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
  cin.nextToken();
  n = (int) cin.nval;
  for(i=0;i< n;++i){
    cin.nextToken();
    way[i].x = (int)cin.nval;
    cin.nextToken();
    way[i].y = (int)cin.nval;
  }
  sum = 0;
  for(i=0;i< n;++i) for(j=i+1;j< n;++j) for(k=j+1;k< n;++k){

    if((way[i].y-way[j].y)*(way[j].x-way[k].x)==(way[i].x-way[j].x)*(way[j].y-way[k].y)){
        sum++;
        out.println((i+1)+" "+(j+1)+" "+(k+1));
    }
   }
        System.out.println(sum);
        out.flush();

 }
}

