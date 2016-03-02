//* @author: SmilingWang
import java.util.*;
public class Main {

 public static void main(String[] args) {
   int n;
   Scanner in = new Scanner(System.in);

   while(true){
     n = in.nextInt();
     Planet[] d = new Planet[n+1];
     if(n == 0){
	return;
     }
     for(int i = 1; i <= n; i++){
	int id = in.nextInt();
	int x = in.nextInt();
	int y = in.nextInt();
	int z = in.nextInt();
	d[i] = new Planet(id, x, y, z);
     }
     f(n, d);
   }
  }

  public static void f(int n, Planet[] d){
    int[][] con = new int[n+1][n+1];
    for(int i = 1; i <= n; i++){
	con[i][i] = 0;
    }
    for(int i = 2; i <= n; i++){
	int min = Integer.MAX_VALUE;
	int mid = 1;
	//display(n, con);
	//System.out.println();
	for(int j = 1; j < i; j++){
	   int dis = dis(d[i], d[j]);
	   //System.out.println(dis + " " + i + " " + j);
	   if(dis < min){
		min = dis;
		mid = j;
	   }
	}
	con[i][mid] = 1;
	con[mid][i] = 1;
	for(int j = 1; j < i; j++){
	   if(j == mid){
		continue;
	   }
	   con[i][j] = con[mid][j] + 1;
	   con[j][i] = con[i][j];
	}
	//display(n, con);
	//System.out.println();
     }

     int max[] = new int[n+1];
     for(int i = 1; i <= n; i++){
	for(int j = 1; j <= n; j++){
	  if(con[i][j] > max[i]){
	    max[i] = con[i][j];
	   }
	}
     }
     int min = Integer.MAX_VALUE;
     int min2 = Integer.MAX_VALUE;
     int mid = 1;
     int mid2 = 1;
     for(int i = 1; i <= n; i++){
	if(max[i] < min){
	  min = max[i];
	  mid = i;
	 }
      }
      for(int i = 1; i <= n; i++){
	 if(i == mid){
	   continue;
	  }
     if(max[i] < min2){
	min2 = max[i];
	mid2 = i;
      }
     }
    if(min != min2){
	System.out.println(d[mid].id);
    }
    else{
	if(d[mid].id > d[mid2].id){
		int temp = d[mid2].id;
		d[mid2].id = d[mid].id;
		d[mid].id = temp;
	}
	System.out.println(d[mid].id + " " + d[mid2].id);
     }
   }

   public static int dis(Planet d1, Planet d2){
	return (int)(Math.pow(d1.x - d2.x, 2) + Math.pow(d1.y-d2.y, 2) + Math.pow(d1.z-d2.z, 2));
   }

   public static void display(int n, int d[][]){
	for(int i = 1; i <= n; i++){
         for(int j = 1; j <= n; j++){
		System.out.print(d[i][j] + " ");
	   }
	   System.out.println(" ");
	 }
    }
}

class Planet{
	int id;
	int x;
	int y;
	int z;

	public Planet(int id, int x, int y, int z){
		this.id = id;
		this.x = x;
		this.y = y;
		this.z = z;
	}
}



