 import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    class Point {
        int x;
        int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        Main main = new Main();
        BufferedReader read = new BufferedReader(new InputStreamReader(
                System.in));
        String[] s;
        s = read.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int l = Integer.parseInt(s[1]);
        int x, y;
        Point[] p = new Point[n];
        for (int i = 0; i < n; i++) {
            s = read.readLine().split(" ");
            x = Integer.parseInt(s[0]);
            y = Integer.parseInt(s[1]);
            p[i] = main.new Point(x, y);
        }
        Point[] ch = new Point[n];
        int len = 0;
        if (n >= 3) {
            len = Graham_scan(p, ch, n);
        }
        double sum = 0;
        for (int i = 0; i < len - 1; i++) {
            sum += distance(ch[i], ch[i + 1]);
        }
        if (len > 1) {
            sum += distance(ch[len - 1], ch[0]);
        }
        sum += 2 * l * Math.PI;
        System.out.println(Math.round(sum));

    }

    public static double multiply(Point p1, Point p2, Point p0) {
        return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
    }

    public static double distance(Point p1, Point p2) {
        return (Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)
                * (p1.y - p2.y)));
    }

    public static int Graham_scan(Point[] PointSet, Point[] ch, int n) {
        int i, j, k = 0, top = 2;
        Point tmp;
        for (i = 1; i < n; i++)
            if ((PointSet[i].y < PointSet[k].y)
                    || ((PointSet[i].y == PointSet[k].y) && (PointSet[i].x < PointSet[k].x)))
                k = i;
        tmp = PointSet[0];
        PointSet[0] = PointSet[k];
        PointSet[k] = tmp;
        for (i = 1; i < n - 1; i++) {
            k = i;
            for (j = i + 1; j < n; j++)
                if ((multiply(PointSet[j], PointSet[k], PointSet[0]) > 0)
                        || ((multiply(PointSet[j], PointSet[k], PointSet[0]) == 0) && (distance(
                                PointSet[0], PointSet[j]) < distance(
                                PointSet[0], PointSet[k]))))
                    k = j;
            tmp = PointSet[i];
            PointSet[i] = PointSet[k];
            PointSet[k] = tmp;
        }
        ch[0] = PointSet[0];
        ch[1] = PointSet[1];
        ch[2] = PointSet[2];
        for (i = 3; i < n; i++) {
            while (top > 0 && multiply(PointSet[i], ch[top], ch[top - 1]) >= 0)
                top--;
            ch[++top] = PointSet[i];
        }
        return top + 1;
    }
}

