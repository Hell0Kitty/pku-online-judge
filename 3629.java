import java.util.Arrays;
import java.util.Scanner;

public class Main {
    int queue[], head, tail;//记录队列，队列头和尾

    void enque(int x) {
        queue[tail] = x;
        tail++;
        if (tail == k)
            tail = 0;
    }
    int deque() {
        int ans = queue[head];
        head++;
        if (head == k)
            head = 0;
        return ans;
    }

    int n, m, k, p;
    int res[];
    Scanner scan = new Scanner(System.in);

        //队列初始化
    void init() {
        n = scan.nextInt();
        k = scan.nextInt();
        p = scan.nextInt();
        queue = new int[k];
        m = k / n;
        res = new int[m];
        for (int i = 1; i <= k; i++)
            enque(i);
    }

    void run() {
        init();

        //模拟发牌过程
        for (int x = 0; x< m; x++)
            for (int i = 1; i <= n; i++) {
                if (i == n)
                    res[x] = deque();
                else
                    deque();
                for (int j = 0; j < p; j++)
                    enque(deque());
            }
        Arrays.sort(res);
        for (int i = 0; i < m; i++)
            System.out.println(res[i]);
    }

    public static void main(String[] args)  {
        new Main().run();
    }
}

