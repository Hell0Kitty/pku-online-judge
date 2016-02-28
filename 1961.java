import java.util.Scanner;

public class Main {
    static int next[]=new int[1000010];

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n;
        String input = "";
        int j=0;
        int k=0;
        while(scn.hasNext()){
            n=scn.nextInt();
            input = scn.next();
             if(n==0){
                break;
             }
           getNext(input,n);
           System.out.printf("Test case #%d\n",++k);


           /* 挨个试验 */
          for (int i = 2; i <= n; i++){
            /* 计算首尾重复子串的长度 */
            j = i - next[i];
            /* 串满足重复性质且重复子串不为本身 */
             if (i % j == 0 && i / j > 1){
                System.out.printf("%d %d\n", i, i / j);
              }
           }
           System.out.printf("\n");
        }


    }

   public static void getNext(String T,int len) {//建立模式串T的next[]表
    int i = 0;
    int j = next[0] = -1;

    while (i< len)
     if (0 > j || T.charAt(i) == T.charAt(j)) {//匹配
        j++; i++;
        next[i] = j;
     }else//失配
       j = next[j];
  }
}

