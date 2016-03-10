import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextInt()) {
            int n = sc.nextInt();
            if (n == 0)
                break;
            sc.nextLine();
            String[] template = new String[n];
            for (int i = 0; i < n; ++i) {
                String s = sc.nextLine();
                template[i] = new String(s);
            }
            // sc.nextLine();
            // sc.nextLine();
            int level = sc.nextInt();
            copy(template, template, level);
        }
    }

    private static void copy(String[] template1, String[] template2, int level) {
        --level;
        if (level > 0) {
            int n1 = template1.length;
            int n2 = template2.length;
            String[] tmpTemplate = new String[n1 * n2];
            int k = 0;
            String spaceS = spaceStr(n2);
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n1; ++j) {
                    k = i * n2;
                    if (template1[i].charAt(j) == ' ') {
                        for (int x = 0; x < n2; ++x) {
                            if (tmpTemplate[k] != null)
                                tmpTemplate[k] += (spaceS);
                            else
                                tmpTemplate[k] = new String(spaceS);
                            k++;
                        }
                    } else {
                        for (int x = 0; x < n2; ++x) {
                            if (tmpTemplate[k] != null)
                                tmpTemplate[k] += template2[x];
                            else
                                tmpTemplate[k] = template2[x];
                            k++;
                        }
                    }
                }
                // print(tmpTemplate);
            }
            copy(template1, tmpTemplate, level);
        } else
            print(template2);

    }

    private static String spaceStr(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; ++i) {
            sb.append(" ");
        }
        return sb.toString();
    }

    private static void print(String[] template) {
        int n = template.length;
        // System.out.println(n);
        for (int i = 0; i < n; ++i) {
            System.out.print(template[i]);
            System.out.println();
        }
    }
}

