import java.util.Scanner;

public class Main {
    private static Trie trie = new Trie();
    private static boolean isConsistent = true;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = sc.nextInt();
            sc.nextLine();
            trie = new Trie();
            isConsistent = true;
            for (int j = 0; j < n; ++j) {
                String phone = sc.nextLine();
                if (isConsistent)
                    buildTrie(phone);
            }
            if (isConsistent)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }

    static void buildTrie(String s) {
        // char[] c = s.toCharArray();
        int len = s.length();
        Trie tmpTrie = trie;
        for (int i = 0; i < len; ++i) {
            int ch = Integer.parseInt(s.substring(i, i + 1));
            // System.out.println(ch+"---"+(int)ch);
            Trie tmp = tmpTrie.next[ch];
            if (tmp == null) {
                tmp = new Trie();
                tmp.node = 1;
                if (i == len - 1)
                    tmp.isDispear = true;// 表示这是一个电话的结尾
                tmpTrie.next[ch] = tmp;
                tmpTrie = tmp;
            } else {
                if (tmp.isDispear) {
                    isConsistent = false;
                    break;
                }

                if (i == len - 1) {
                    isConsistent = false;
                    break;
                }
                tmpTrie = tmp;
            }
        }
    }

    private static class Trie {
        int node = 0;
        boolean isDispear = false;//是否是某个电话号码的最后一个
        Trie[] next = new Trie[10];
    }
}


