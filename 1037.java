import java.util.*;
public class Main{
 static final int MAX=21;//最多20根木条
 static long w[][];//w型排列的个数
 static long m[][];//m型排列的个数，m[x][n]为由n个长度不同的木条组成的栅栏中，以其中第x根木条开始的“M”型排列的个数
 
 private int n;//木条的根数
 private long c;//编号

 private boolean flag[];
 private boolean print;
 
  static {//初始化静态变量
    w=new long[MAX][MAX];
    m=new long[MAX][MAX];
    w[1][1] = 1; m[1][1] = 1;
    w[1][2] = 0; m[1][2] = 1;
    w[2][2] = 1; m[2][2] = 0;
    for (int i = 3; i < MAX; i++)
      for (int j = 1; j < MAX; j++){
        for (int k = 1; k < j; k++) 
          w[j][i] += m[k][i - 1];
        for (int k = j; k < i; k++) 
          m[j][i] += w[k][i - 1];
    }
  }

  public Main(int n,long c){
    this.n=n;
    this.c=c;
    flag=new boolean[MAX];
    print=false;
   }

  private void fand(int k, int m){
    for (int i = 1; i <= m; i++) 
     if (flag[i] && i <= k){
        k++; m++;
     }
    flag[k] = true;
    if (print) System.out.print(" "+k);
    else{
        System.out.print(k);
        print = true;
    }
}

 private void doIt(){
   int k = 1;//从排在最前面的木条找起
        print = false;
        boolean direct = true, first = true;
        while(n!=0){
            if (direct)
                if (c > w[k][n]){//如果编号大于以第k根木条开始的“w”型排列的个数，说明所求排列在这些排列之后
                    c -= w[k++][n];//更新编号，同时换一根木条
                    if (first) {direct = false; k--;}//如果是查找第一根木条，还要试"m"型排列
                }else{
                    fand(k, n--);//找到k,输出并将木条总数减1
                    first = false;
                    direct = false;
                    k = 1;
                }
            else
                if (c > m[k][n]){//如果编号大于以第k根木条开始的“m”型排列的个数，说明所求排列在这些排列之后
                    c -= m[k++][n];//更新编号，同时换一根木条
                    if (first) direct = true;//查找第一根木条结束
                }else{
                    fand(k, n--);
                    first = false;
                    direct = true;
                }
        }
        System.out.println();
    }

public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int t, n;
     long c;
     t=sc.nextInt();;
    while((t--)!=0){
        n=sc.nextInt();
        c=sc.nextLong();
        Main m=new Main(n,c);
        m.doIt();
    }
}

 
}
