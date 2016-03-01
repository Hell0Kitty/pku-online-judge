import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 *
 * poj2685
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        if (scan.hasNext()) {
            int n = scan.nextInt();
            scan.nextLine();
            for (int i = 0; i < n; i++) {
                String[] ss = scan.nextLine().trim().split(" ");
                char[] a = ss[0].toCharArray();
                char[] b = ss[1].toCharArray();
                int[] va = {0, 0, 0, 0};
                int[] vb = {0, 0, 0, 0};
                int[] vc = new int[4];
                for (int j = 0; j < a.length; j++) {
                    if (a[j] - '0' <= 9 && a[j] - '0' >= 2) {
                        j++;
                        va[getIndex(a[j])] = a[j - 1] - '0';
                    } else {
                        va[getIndex(a[j])] = 1;
                    }
                }
                for (int j = 0; j < b.length; j++) {
                    if (b[j] - '0' <= 9 && b[j] - '0' >= 2) {
                        j++;
                        vb[getIndex(b[j])] = b[j - 1] - '0';
                    } else {
                        vb[getIndex(b[j])] = 1;
                    }
                }
                for (int j = vc.length - 1; j >= 0; j--) {
                    vc[j] = vc[j] + va[j] + vb[j];
                    if (vc[j] >= 10) {
                        vc[j] = vc[j] - 10;
                        if (j - 1 >= 0) {
                            vc[j - 1] = vc[j - 1] + 1;
                        }
                    }
                }
                print(vc);
            }
        }
    }

    static void print(int[] c) {
        for (int i = 0; i < c.length; i++) {
            if (c[i] == 0) {
                continue;
            }
            if (c[i] == 1) {
                System.out.print(""+getChar(i));
            } else {
                System.out.print(c[i]+(getChar(i)+""));
            }
        }
        System.out.println();
    }

    static int getIndex(char c) {
        switch (c) {
            case 'm':
                return 0;
            case 'c':
                return 1;
            case 'x':
                return 2;
            case 'i':
                return 3;
            default:
                return -1;
        }
    }

    static char getChar(int i) {
        switch (i) {
            case 0:
                return 'm';
            case 1:
                return 'c';
            case 2:
                return 'x';
            case 3:
                return 'i';
            default:
                return '0';
        }
    }
}

