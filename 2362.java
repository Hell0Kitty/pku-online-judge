import java.io.*;
import java.util.*;

public class Main {

//记录数字的总长度。
int totalNum;
//记录各个数字的值的数组。
int[] numArr;
//记录每个小短棒是否被使用过。
boolean[] used;

public static void main(String args[]) throws Exception {
   Main m=new Main();
   m.begin();
}

private void begin() throws Exception {
   Scanner cin = new Scanner(System.in);
   int totalLine = cin.nextInt();
   for(int i=0; i< totalLine; i++){
    totalNum = cin.nextInt();
    numArr = new int[totalNum];
    //总长度。
    int sumLen = 0;
    for(int j=0; j< totalNum; j++){
     numArr[j] = cin.nextInt();
     sumLen += numArr[j];
    }
    //初始化每个小短棒都没被使用过。
    used = new boolean[totalNum];
    for(int j=0; j< totalNum; j++)
     used[j] = false;
    //和必须时 4 的倍数。
    if(sumLen%4==0){
     //排序，逆序。
     Arrays.sort(numArr);
     int temp;
     for(int k=0; k< totalNum/2; k++){
      temp = numArr[k];
      numArr[k] = numArr[totalNum-1-k];
      numArr[totalNum-1-k] = temp;
     }
     //获得最大值。
     int maxNum = numArr[0];
     //重置已经拼好的边数为 0。
     passNum = 0;
     //最大值不能大于总长的 1/4。
     if(maxNum <= sumLen/4){
      //开始深度优先搜索。
      if(DFS(0, sumLen/4, 0))
       System.out.println("yes");
      else
       System.out.println("no");
     }else
      System.out.println("no");
    }else
     System.out.println("no");
   }
}

//记录已经拼出的符合长度的边的个数，最多 4 个。
int passNum = 0;
//参数分别是当前循环的标识符、要测试的长度、需要加上的底数。
private boolean DFS(int f_num, int f_len, int f_sum){
   //当底数和需要的长度相等时。
   if(f_len == f_sum){
    //增加一条通过的边数。
    passNum++;
    //重置底数和开始时标识符。
    f_sum = 0;
    f_num = 0;
    //当通过的边数和 4 相等就说明成功。
    if(passNum == 4)
     return true;
   }
   //开始遍历下一层。
   for(int i=f_num; i< totalNum; i++){
    //当底数加上本数小于等于需要的长度时，并且本数没被使用。
    if(f_sum+numArr[i]<=f_len && !used[i]){
     //暂时记录为已经使用。
     used[i] = true;
     //进行下一次的递归。
     DFS(i+1, f_len, f_sum+numArr[i]);
     //边数达到 4 后即可跳出循环。
     if(passNum == 4)
      break;
     //通过了上面的脚本，说明边数没有达到 4，而又能拼出一条边，取消掉这条边，以便测试其他的组合。
     if(f_sum+numArr[i] == f_len)
      passNum--;
     //取消本数的记录。
     used[i] = false;
    }
   }
   //退出时检查一次是否拼好正方形。
   if(passNum == 4)
    return true;
   //返回失败。
   return false;
}
}

