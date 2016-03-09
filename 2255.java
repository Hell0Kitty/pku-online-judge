import java.util.Scanner;

public class Main {

    private static char[] seq = new char[100];
    private static int s = -1;

    public static void getPostOrder(String pre, String in) {
        if (pre.length() == 1 && in.length() == 1) {
            seq[++s] = in.charAt(0);
            // seq[++s] = pre.charAt(0);
            return;
        }

        char root = pre.charAt(0);
        seq[++s] = root;

        int rootIndex = in.indexOf(root);
        if (rootIndex == 0) {
            getPostOrder(pre.substring(1), in.substring(1));
            return;
        } else if (rootIndex == in.length() - 1) {
            getPostOrder(pre.substring(1), in.substring(0, in.length() - 1));
            return;
        } else {
            String in_Left = in.substring(0, rootIndex);
            String in_Right = in.substring(rootIndex + 1);

            int indexLeft = -1;
            for (int i = 0; i < in_Left.length(); i++) {
                int temp = pre.indexOf(in_Left.charAt(i));
                if (temp > indexLeft)
                    indexLeft = temp;
            }

            if (in_Right.length() == 1) {
                seq[++s] = in_Right.charAt(0);
                // return;
            } else {
                String pre_Right = null;
                pre_Right = pre.substring(indexLeft + 1);
                getPostOrder(pre_Right, in_Right);
            }

            if (in_Left.length() == 1) {
                seq[++s] = in_Left.charAt(0);
                return;
            } else {
                String pre_Left = null;
                pre_Left = pre.substring(1, indexLeft + 1);
                getPostOrder(pre_Left, in_Left);
            }

        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext()) {
            s = -1;

            String pre = sc.next();
            String in = sc.next();

            seq = new char[pre.length() + 1];
            getPostOrder(pre.trim(), in.trim());

            while (s >= 0) {
                System.out.print(seq[s--]);
            }
            System.out.println();
        }
    }

}

