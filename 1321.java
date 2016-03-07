import java.util.Scanner;   
  
public class Main {   
  
 private static int n;   
 private static int k;   
 private static int ans;   
 private static int[] column;   
 private static String[] chessboard;   
  
 public static void main(String[] args) {   
  
  Scanner sc = new Scanner(System.in);   
  
  while (sc.hasNext()) {   
   n = sc.nextInt();   
   k = sc.nextInt();   
   if (n == -1 && k == -1)   
    break;   
   sc.nextLine();   
   chessboard = new String[n];   
   column = new int[n];   
   for (int i = 0; i < n; i++) {   
    chessboard[i] = sc.nextLine();   
   }   
   ans = 0;   
   dfs(0, 0);// 从第一行开始   
   System.out.println(ans);   
  }   
 }   
  
 private static void dfs(int pos, int i) {   
  
  if (pos == k) {   
   ans++;   
   return;   
  }   
  if (i >= n)   
   return;   
  for (int j = 0; j < n; j++) {   
   char ch = chessboard[i].charAt(j);   
   if (ch == '#' && column[j] == 0) {   
    column[j] = 1;   
    pos++;   
    dfs(pos, i + 1);   
    column[j] = 0;   
    pos--;   
   }   
  }   
  dfs(pos, i + 1);   
 }   
  
}  
