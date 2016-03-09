import java.util.Scanner;

public class Main {

    private static int[][] matrix = new int[1001][1001];
    private static int n;

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        for (int i = 0; i < testNum; ++i) {
            matrix = new int[1001][1001];
            n = sc.nextInt();
            int t = sc.nextInt();
            for (int j = 0; j < t; ++j) {
                String c = sc.next();
                if (c.equals("C")) {
                    int x1 = sc.nextInt();
                    int y1 = sc.nextInt();
                    int x2 = sc.nextInt();
                    int y2 = sc.nextInt();
                    change(x1 , y1 , 1);
                    change(x1 , y2+1 , -1);
                    change(x2+1 , y2+1 , 1);
                    change(x2+1 , y1 , -1);
                } else if (c.equals("Q")) {
                    int x = sc.nextInt();
                    int y = sc.nextInt();
                    int v = getSum(x, y) & 1;
                    // System.out.println(getSum(x , y));
                    if (v == 0)
                        System.out.println(0);
                    if (v == 1)
                        System.out.println(1);
                }
            }
            System.out.println();
        }
    }

    public static void change(int x1, int y1, int x2, int y2) {

        for (int i = x1; i <= x2; ++i) {
            change(i, y1, 1);
            change(i, y2 + 1, -1);
        }
        // for (int i = x1; i <= x2; ++i) {
        // for (int j = y1; j <= y2; ++j) {
        //
        // if (matrix[i][j] == 0)
        // matrix[i][j] = 1;
        // else
        // matrix[i][j] = 0;
        // }
        // }
    }

    public static int lowbit(int i) {
        return i & -i;
    }

    public static void change(int i, int j, int value) {
        while (i <= n) {
            int temp = j;
            while (temp <= n) {
                matrix[i][temp] += value;
                temp += lowbit(temp);
            }
            i += lowbit(i);
        }
    }

    public static int getSum(int i, int j) {
        int sum = 0;
        while (i > 0) {
            int tmp = j;
            while (tmp > 0) {
                sum += matrix[i][tmp];
                tmp -= lowbit(tmp);
            }
            i -= lowbit(i);
        }
        return sum;
    }

}

