import java.io.BufferedInputStream;   
import java.util.Arrays;   
import java.util.Scanner;   
  
/**  
 * poj1723  
 * 借鉴了别人的代码和思路  
 * 一 士兵有多种移动方式  
 * 通过适当的移动顺序和移动路线可以使得同一时刻不会有两名士兵站在同一点  
 * 二 题目要求最佳移动方式（即求移动的最少步数）  
 * 题目要求转化为求士兵站立的“最终位置”，即如何取“最终位置”使得士兵移动的步数最少（最优）  
 * 因为移动步数可以分解为移动到同一直线,再移动到相邻位置,因此可以分开求  
 * Y轴方向上的考虑(移动直线的时候)  
 * 设目标坐标为M，即n个士兵最终需要移动到的Y轴的坐标值为M  
 * n个士兵的Y轴坐标分别为：  
 * Y0，Y1，Y2 …… …… Yn-1  
 * 则最优步数S=|Y0-M|+|Y1-M|+|Y2-M|+ …… …… +|Yn-1-M|  
 * 结论：M取中间点的值使得S为最少（最优）  
 * X轴方向上的考虑  
 * 首先需要对所有士兵的X轴坐标值进行排序  
 * 然后，按从左至右的顺序依次移动到每个士兵所对应的“最终位置”（最优），所移动的步数总和就是X轴方向上需要移动的步数  
 * 例，最左的士兵移动到“最终位置”的最左那位，第二个士兵移动到“最终位置”的第二位(好好理解下)  
 * 则总的步数为：士兵一移动步数+士兵二移动步数+ …… +士兵n移动步数  
 * 如何确定X轴方向上的最佳的“最终位置”？  
 * 共n个士兵  
 * 他们相应的X轴坐标为：X0，X1，X2 …… …… Xn-1  
 * 设，士兵需要移动到的“最终位置”的X轴坐标值为：k，k+1，k+2 …… …… k+（n-1）  
 * 则所求最优步数S=|X0-k|+|X1- （k+1） |+|X2-（k+2）|+ …… +|Xn-1-（k+（n-1））|  
 * 经过变形S=|X0-k|+|（X1-1）-k|+|（X2-2）-k|+ …… …… +|（Xn-1-（n-1））-k|  
 * 注意到公式的形式与Y轴方向上的考虑一样，同样是n个已知数分别减去一个待定数后取绝对值，然后求和  
 * 因此还是采用取中位数的办法求得k值，最后算出最优解  
 * @author NC  
 */  
public class Main {   
  
    static int x[];   
    static int y[];   
  
    public static void main(String[] args) {   
        Scanner scan = new Scanner(new BufferedInputStream(System.in));   
        if (scan.hasNext()) {   
            int n = scan.nextInt();   
            x = new int[n];   
            y = new int[n];   
            for (int i = 0; i < n; i++) {   
                x[i] = scan.nextInt();   
                y[i] = scan.nextInt();   
            }   
            Arrays.sort(x);   
            Arrays.sort(y);   
            for (int i = 0; i < n; i++) {   
                x[i] -= i;   
            }   
            Arrays.sort(x);   
            int midX = x[(n + 1) / 2 - 1];   
            int midY = y[(n + 1) / 2 - 1];   
            int num = 0;   
            for (int i = 0; i < n; i++) {   
                num += Math.abs(x[i] - midX) + Math.abs(y[i] - midY);   
            }   
            System.out.println(num);   
  
        }   
    }   
}  
