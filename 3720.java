import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * @author Administrator 循环小数+循环节
 */
public class Main {
    /**
     *分子
     */
    private int numerator;
    /**
     *分母
     */
    private int denominator;
    /**
     * 循环节不会超过100的情况
     */
    private static int MAX_NUM = 101;

    /**
     * @return获取小数形式，算到循环节+循环节大小 不考虑numerator>=denominator的情况;只考虑真分数
     */
    private class Node {
        private boolean RemainFlag[];

        private int RemainPreFlag[];

        public boolean[] getRemainFlag() {
            return RemainFlag;
        }

        public void setRemainFlag(boolean[] remainFlag) {
            RemainFlag = remainFlag;
        }

        public int[] getRemainPreFlag() {
            return RemainPreFlag;
        }

        public void setRemainPreFlag(int[] remainPreFlag) {
            RemainPreFlag = remainPreFlag;
        }

    }

    private class Result {

        private int result[];

        private int size;

        public int[] getResult() {
            return result;
        }

        public void setResult(int[] result) {
            this.result = result;
        }

        public int getSize() {
            return size;
        }

        public void setSize(int size) {
            this.size = size;
        }

    }

    public Result getRepeatingPresentation(int numerator, int denominator) {

        int gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd; // 化成最简形式
        Result res = new Result();
        res.result = new int[MAX_NUM];
        int remain;
        Node node = new Node();
        node.RemainFlag = new boolean[MAX_NUM];
        node.RemainPreFlag = new int[MAX_NUM];
        for (int i = 0; i < MAX_NUM; i++) {
            node.RemainFlag[i] = false;
            node.RemainPreFlag[i] = 0;
        }
        remain = numerator;
        int i = 0;
        while (true) {
            int tmp = remain * 10 % denominator; // 余数
            if (true == node.RemainFlag[tmp]
                    && node.RemainPreFlag[tmp] == remain) {
                break;
            }
            node.RemainFlag[tmp] = true;
            node.RemainPreFlag[tmp] = remain;
            res.result[i] = remain * 10 / denominator; // 商
            remain = remain * 10 % denominator; // 余数
            //System.out.print(res.result[i]);
            res.size = i;
            i++;
            if (tmp == 0)
                break;

        }
        return res;

    }

    /**
     * @param a
     * @param b
     * @return 最大公约数+辗转相除法
     */
    public int getGCD(int a, int b) {
        if (a % b == 0)
            return b;
        else
            return getGCD(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        Main t = new Main();
        // t.getRepeatingPresentation(1,6);
        BufferedReader stdin = new BufferedReader(new InputStreamReader(
                System.in));

        while (true) {
            String line = stdin.readLine();
            if(line==null) break;
            StringTokenizer st = new StringTokenizer(line);
            String a1 = st.nextToken();
            String b1 = st.nextToken();
            int a = Integer.parseInt(a1);
            int b = Integer.parseInt(b1);
            Result res[] = new Result[a + 1];
            for (int i = 2; i <= a; i++) {
                res[i] = t.getRepeatingPresentation(1, i);
                //System.out.println();
            }
            int sum = 0;
            for (int i = 2; i <= a; i++) {
                for (int j = 0; j <= res[i].size; j++) {
                    if (res[i].result[j] == b)
                        sum++;
                }
            }
            System.out.println(sum);
        }

    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) {
        this.denominator = denominator;
    }

}

