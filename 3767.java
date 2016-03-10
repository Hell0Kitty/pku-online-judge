import java.util.Scanner;

public class Main{

 public static void dijkstra(int[][] GA, int[] leader, int road) {

  if (road == 0)
   System.out.println(-1);
  else {

   int size = GA.length;
   // System.out.println(size);
   int[] dist = new int[size];
   int[] isUsed = new int[size];
   isUsed[1] = 1;
   dist[1] = Integer.MAX_VALUE;
   for (int i = 2; i < size; i++) {
    dist[i] = GA[1][i];
   }

   for (int i = 1; i < size - 2; i++) {
    int min = Integer.MAX_VALUE;
    int m = 0;
    for (int j = 1; j < size; ++j) {
     if (isUsed[j] == 0 && dist[j] < min) {
      min = dist[j];
      m = j;
     }
    }

    if (m != 0)
     isUsed[m] = 1;
    else
     break;

    for (int j = 1; j < size; ++j) {
     if (isUsed[j] == 0
       && (leader[m] == leader[j] || leader[j] == 2)
       && GA[m][j] != Integer.MAX_VALUE
       && dist[m] + GA[m][j] < dist[j]) {
      dist[j] = dist[m] + GA[m][j];
     }
    }
   }
   System.out.println(dist[2] == Integer.MAX_VALUE ? -1 : dist[2]);
  }
 }

 public static void main(String[] args) {
  Scanner sc = new Scanner(System.in);
  while (sc.hasNextInt()) {
   int countCity = sc.nextInt();

   if (countCity == 0)
    break;

   int road = sc.nextInt();

   int[][] GA = new int[countCity + 1][countCity + 1];

   for (int i = 1; i <= countCity; ++i) {
    for (int j = 1; j <= countCity; ++j) {
     GA[i][j] = Integer.MAX_VALUE;
    }
   }

   for (int i = 0; i < road; ++i) {
    int c1 = sc.nextInt();
    int c2 = sc.nextInt();
    GA[c1][c2] = sc.nextInt();
    GA[c2][c1] = GA[c1][c2];
   }
   int[] leader = new int[countCity + 1];
   for (int i = 1; i < countCity + 1; ++i)
    leader[i] = sc.nextInt();
   dijkstra(GA, leader, road);

  }
 }

}

