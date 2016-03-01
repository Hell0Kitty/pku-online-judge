import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


/**
 * Accepted.
 *
 * @author Administrator
 *
 */
public class Main {

    private static Set< Long> set = new HashSet< Long>();

    private static Map< Long, List< String>> map = new HashMap< Long, List< String>>();

    private static Set< Long> sumSet = new HashSet< Long>();

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        while (true) {
            int n = cin.nextInt();

            if (n == 0) {
                break;
            }

            set.clear();
            sumSet.clear();

            map = new HashMap< Long, List< String>>();

            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = cin.nextInt();

                set.add(new Long(a[i]));
            }

            Arrays.sort(a);

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (a[i] != a[j]) {
                        long temp = a[i];
                        temp += a[j];
                        sumSet.add(temp);
                    }
                }
            }


            for (int i = n - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {

                    if (a[i] == a[j]) {
                        continue;
                    }

                    long v = a[i];
                    v -= a[j];

                    if (!sumSet.contains(v)) {
                        // System.out.println("v=" + v);
                        continue;
                    }

                    List list = map.get(v);

                    if (list == null) {
                        list = new ArrayList();
                        list.add("" + a[i] + " " + a[j]);
                    } else {

                        list.add("" + a[i] + " " + a[j]);
                    }

                    map.put(v, list);
                }
            }
            int ans = 0;
            boolean find = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i] == a[j]) {
                        continue;
                    }

                    long sum = a[i];
                    sum += a[j];
                    List< String> list = map.get(sum);
                    // System.out.println("list=" + list);

                    if (list != null) {
                        for (String s : list) {

                            String[] ss = s.split("[ ]+");

                            int d = Integer.parseInt(ss[0]);
                            int c = Integer.parseInt(ss[1]);

                            if (d != a[i] && d != a[j] && c != a[i] && c != a[j]) {
                                find = true;
                                ans = Math.max(ans, d);
                            }
                        }
                    }
                }
            }

            if (find) {
                System.out.println(ans);
            } else {
                System.out.println("no solution");
            }
        }
    }
}

