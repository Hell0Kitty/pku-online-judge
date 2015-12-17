import java.io.PrintWriter;
import java.util.Scanner;
public class Main {

  public static void main(String[] args) {
   Scanner scn = new Scanner(System.in);
   //Scanner scn = new Scanner(Main.class.getResourceAsStream("in.dat"));
   PrintWriter out = new PrintWriter(System.out);
   int[][] table;
   String[] input;
   int n = 0;
   while(true){
    n = scn.nextInt();
    if(n == 0){
     break;
    }
    input = new String[n];
   table = new int[n][n];
    for(int i = 0; i < n; i++){
     input[i] = scn.next();
    }
    //初始化数据
    for(int i = 0; i < n; i++){
     for(int j = 0; j < n; j++){
      int disc = (i == j)?0:getDisc(input[i], input[j]);
      table[i][j] = disc == 0? Integer.MAX_VALUE: Math.abs(disc);
     }
    }
    //out.format("The highest possible quality is 1/%d.\n", prim(table,n));
    out.println("The highest possible quality is 1/" + prim(table, n) + ".");

   }
   out.flush();
  }
  public static int prim(int[][] table,int n){
   int[] lowcost = new int[n];
   boolean[] s = new boolean[n];
   int sum = 0;
   s[0] = true;//从第一个位置开始
  for(int i = 1; i < n; i++){
    lowcost[i] = table[0][i];
    s[i] = false;
   }
   //找到 j - s 中的最小权边
   for(int i = 1; i < n; i++){
    int min = Integer.MAX_VALUE;
    int j = 1;
    for(int k = 1; k < n; k++){
     if((lowcost[k] < min) && (!s[k])){
      min = lowcost[k];
      j = k;
     }
    }
    s[j] = true;//加入到j 加入到 s 集合中来
    //sum += min;
    for(int k = 1; k < n; k++){
     if(table[j][k] < lowcost[k] && (!s[k])){
      lowcost[k] = table[j][k];
     }
    }
   }
   for(int i = 0; i < n; i++){
    sum += lowcost[i];
   }
   return sum;
  }
  /**
   * 计算出当前行有几个元素不为a
   * @param next
   * @return
   */
  private static int getDisc(String str1,String str2) {
  int num = 0;
   for(int i = 0; i < 7; i++){
    if(str1.charAt(i) != str2.charAt(i)){
     num++;
    }
   }
   return num;
  }
 }