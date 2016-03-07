import java.util.*;

/**
 *
 * @author yeming
 */
public class Main {

    static int n;
    static int[][] matrix;
    static int[] result;
    static boolean[] state;
    static int[] gender;//male-1, famale-1, no set-0
    static int ans;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()) {
            init(sc);
            labelGender();
            for(int i = 0; i < n; i++) {
                if(gender[i] == 1) {
                    Arrays.fill(state, false);
                    if(find(i)) {
                        ans++;
                    }
                }
            }
            System.out.println(n-ans);
        }
    }

    private static boolean find(int i) {
        for(int j = 0; j < matrix[i].length; j++) {
            if(!state[matrix[i][j]]) {
                state[matrix[i][j]] = true;
                if(result[matrix[i][j]] == -1
                        || find(result[matrix[i][j]])) {
                    result[matrix[i][j]] = i;
                    return true;
                }
            }
        }
        return false;
    }

    private static void labelGender() {
        gender = new int[n];
        Arrays.fill(gender, 0);
        LinkedList<Integer>
                queue = new LinkedList<Integer>();
        for(int i = 0; i < n; i++) {
            if(gender[i] == 0) {
                gender[i] = 1;
                queue.add(i);
            }
            while(!queue.isEmpty()) {
                int t = queue.pop();
                for(int j = 0; j < matrix[t].length; j++) {
                    if(gender[matrix[t][j]] == 0) {
                        gender[matrix[t][j]] = - gender[t];
                        queue.add(matrix[t][j]);
                    }
                }
            }
        }
    }

    private static void init(Scanner sc) {
        ans = 0;
        n = sc.nextInt();
        matrix = new int[n][];
        for(int i = 0; i < n; i++) {
            sc.next();//id, the same as i
            String str = sc.next();
            String numStr = str.substring(1, str.length()-1);
            int num = Integer.parseInt(numStr);
            matrix[i] = new int[num];
            for(int j = 0; j < num; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }
        state = new boolean[n];
        Arrays.fill(state, false);
        result = new int[n];
        Arrays.fill(result, -1);
    }
}
