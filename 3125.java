import java.io.BufferedInputStream;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * @author NC
 * poj3125
 */
public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(new BufferedInputStream(System.in));
        int cas = scan.nextInt();
        for (int i = 1; i <= cas; i++) {
            int n = scan.nextInt();
            int position = scan.nextInt();
            LinkedList queue = new LinkedList();
            int[] priority = new int[n];
            for (int j = 0; j < n; j++) {
                priority[j] = scan.nextInt();
                queue.addLast(new Job(j + 1, priority[j]));
            }
            Arrays.sort(priority);//非递减的
            int time = 0;
            int count = priority.length - 1;
            Job current = null;
            do {
                current = queue.getFirst();
                if (current.priority < priority[count]) {
                    current = queue.removeFirst();
                    queue.addLast(current);
                } else if (current.priority == priority[count]) {
                    time++;
                    count--;
                    queue.removeFirst();
                    if (current.number == position + 1) {
                        break;
                    }
                } else {
                    System.out.println("error");
                }
            } while (true);
            System.out.println(time);
        }
    }
}

class Job {

    int priority;
    int number;

    Job(int n, int p) {
        this.priority = p;
        this.number = n;
    }
}

