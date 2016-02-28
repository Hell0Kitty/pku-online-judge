import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 *poj1979
 * 这道题是数据结构的第一道,刚开始是用c语言做的,但后来其他题目我都用了java去写,
 * 所以现在只是简单把c语法转化为java法,统一一下编码而已
 * @author NC
 */
public class Main {

    private final static int MAXCOL = 22;
    private final static int MAXROW = 22;
    private static int[][] floor = new int[MAXROW][MAXCOL]; //最多是20行，20列，再加两行两列作为边界
    private static int[][] visited = new int[MAXROW][MAXCOL]; //标记是否访问过，默认没有访问过

    public static void main(String[] args) {

        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        while (scan.hasNext()) {
            int col = scan.nextInt();
            int row = scan.nextInt();
            int i = 0, j = 0, k = 0;
            int count = 0;
            int flag = 0;
            char c;
            //读取数据
            if (col == 0 && row == 0) {
                break;
            }
            //因为是循环输入，所以每一次都得初始化
            for (i = 0; i < MAXROW; i++) {
                for (j = 0; j < MAXCOL; j++) {
                    floor[i][j] = 0;
                    visited[i][j] = 0;
                }
            }
            scan.nextLine();
            //一个一个读取字符，将符号转换为数字
            for (i = 1; i <= row; i++) {
                char[] ss = scan.nextLine().trim().toCharArray();
                for (j = 1; j <= col; j++) {
                    while (true) {
                        c = ss[j-1];
                        if (c == '.' || c == '#' || c == '@') {
                            break;
                        }
                    }
                    if (c == '.') {
                        floor[i][j] = 1;
                    } else if (c == '#') {
                        floor[i][j] = 2;
                    } else if (c == '@') {
                        floor[i][j] = 3;
                    }
                }
            }
            //找出人所站的位置
            flag = 0;
            for (i = 1; i <= row; i++) {
                for (j = 1; j <= col; j++) {
                    if (floor[i][j] == 3) {
                        flag = 1;
                        break; //要跳出两层
                    }
                }
                if (flag == 1) {
                    break;
                }
            }
            //深度遍历
            if (floor[i][j] == 3) {
                DFS(i, j);
            }
            //count the number of tiles he can reach from the initial tile
            count = 0;
            for (i = 1; i <= row; i++) {
                for (j = 1; j <= col; j++) {
                    if (visited[i][j] == 1) {
                        count++;
                    }
                }
            }
            //print the number of tiles he can reach from the initial tile
            System.out.println(count);
        }
    }

    static void DFS(int i, int j) {
        //标记访问过
        visited[i][j] = 1;
        //四个方向都要遍历，不能用else if
        if (floor[i][j + 1] == 1 && visited[i][j + 1] == 0) {
            DFS(i, j + 1);
        }
        if (floor[i][j - 1] == 1 && visited[i][j - 1] == 0) {
            DFS(i, j - 1);
        }
        if (floor[i + 1][j] == 1 && visited[i + 1][j] == 0) {
            DFS(i + 1, j);
        }
        if (floor[i - 1][j] == 1 && visited[i - 1][j] == 0) {
            DFS(i - 1, j);
        }
    }
}

