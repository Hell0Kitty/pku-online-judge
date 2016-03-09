import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);

        int kase = 0;
        while (true) {

            int n = cin.nextInt();

            if (n == 0) {
                break;
            }

            kase++;

            List list = new ArrayList();

            for (int i = 1; i <= n; i++) {
                int x = cin.nextInt();
                int y = cin.nextInt();
                int z = cin.nextInt();

                list.add(new T(x, y, z));
                list.add(new T(y, x, z));

                list.add(new T(x, z, y));
                list.add(new T(z, x, y));

                list.add(new T(y, z, x));
                list.add(new T(z, y, x));

            }

            Collections.sort(list, new Comparator() {

                public int compare(Object arg0, Object arg1) {
                    T t1 = (T) arg0;
                    T t2 = (T) arg1;

                    if (t2.x > t1.x) {
                        return t2.x - t1.x;
                    } else if (t2.x == t1.x && t2.y > t1.y) {
                        return t2.y - t1.y;
                    } else if (t2.x == t1.x && t2.y == t1.y && t2.z > t1.z) {
                        return t2.z - t1.z;
                    }

                    return -1;
                }
            });

            int[] f = new int[list.size() + 1];
            for (int i = 0; i < f.length; i++) {
                f[i] = 0;
            }

            f[0] = list.get(0).z;

            int max = f[0];

            for (int i = 1; i < list.size(); i++) {
                int m = list.get(i).z;

                for (int k = 0; k < i; k++) {

                    if (list.get(k).x > list.get(i).x && list.get(k).y > list.get(i).y) {
                        m = Math.max(m, f[k] + list.get(i).z);
                    }
                }

                max = Math.max(max, m);

                f[i] = m;
            }
            System.out.println("Case " + kase + ": maximum height = " + max);
        }
    }

    static class T {

        int x;
        int y;
        int z;

        public T(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

}

