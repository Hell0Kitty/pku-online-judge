import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static boolean isSubsequence(String s1, String s2) {
        int len = s2.length();
        int index = -1;
        int i = 0;
        for (i = 0; i < len; i++) {
            index = s1.indexOf(s2.charAt(i), index + 1);
            if (index == -1) {
                break;
            }
        }
        if (i == len && index != -1)
            return true;
        index = -1;
        for (i = len; i > 0; i--) {
            index = s1.indexOf(s2.charAt(i - 1), index + 1);
            if (index == -1)
                break;
        }
        if (i == 0 && index != -1)
            return true;
        return false;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        for (int i = 0; i < num; i++) {
            String s1 = in.next();
            String s2 = in.next();
            if (isSubsequence(s1, s2)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }

}

