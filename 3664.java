import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static class vote {
        int first;
        int second;
        int index;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int K = in.nextInt();
        // vote[] voters = new vote[N];
        ArrayList< vote> voters = new ArrayList< vote>();
        for (int i = 0; i < N; i++) {
            vote temp = new vote();
            temp.first = in.nextInt();
            temp.second = in.nextInt();
            temp.index = i + 1;
            voters.add(temp);
        }
        Collections.sort(voters, new Comparator< Object>() {
            public int compare(Object o1, Object o2) {
                vote a = (vote) o1;
                vote b = (vote) o2;
                return b.first - a.first;
            }

        });

        int result = 0;
        for (int i = 1; i < K; i++) {
            if (voters.get(result).second < voters.get(i).second) {

                result = i;
            }
        }
        System.out.println(voters.get(result).index);
    }
}

