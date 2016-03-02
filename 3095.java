import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(
                System.in));
        String s;
        while (!(s = read.readLine()).equals("#")) {
            char[] c = s.toCharArray();
            int[] p = new int[c.length];
            for (int i = 0; i < c.length; i++) {
                if (c[i] == '.') {
                    p[i] = 100;
                } else if (c[i] == '_') {
                    p[i] = 0;
                } else if (c[i] == '|') {
                    int k = 1;
                    while (true) {
                        if (i - k < 0) {
                            p[i] += 50;
                            break;
                        }
                        if (c[i - k] == '_') {
                            k++;
                            continue;
                        } else if (c[i - k] == '.' || c[i - k] == '/') {
                            p[i] += 50;
                            break;
                        } else if (c[i - k] == '|' || c[i - k] == '\\') {
                            break;
                        }
                    }
                    k = 1;
                    while (true) {
                        if (i + k == c.length) {
                            p[i] += 50;
                            break;
                        }
                        if (c[i + k] == '_') {
                            k++;
                            continue;
                        } else if (c[i + k] == '.' || c[i + k] == '\\') {
                            p[i] += 50;
                            break;
                        } else if (c[i + k] == '|' || c[i + k] == '/') {
                            break;
                        }
                    }
                } else if (c[i] == '/') {
                    int k = 1;
                    while (true) {
                        if (i - k < 0) {
                            p[i] = 100;
                            break;
                        }
                        if (c[i - k] == '_') {
                            k++;
                            continue;
                        } else if (c[i - k] == '.' || c[i - k] == '/') {
                            p[i] = 100;
                            break;
                        } else if (c[i - k] == '|' || c[i - k] == '\\') {
                            break;
                        }
                    }
                } else if (c[i] == '\\') {
                    int k = 1;
                    while (true) {
                        if (i + k == c.length) {
                            p[i] = 100;
                            break;
                        }
                        if (c[i + k] == '_') {
                            k++;
                            continue;
                        } else if (c[i + k] == '.' || c[i + k] == '\\') {
                            p[i] = 100;
                            break;
                        } else if (c[i + k] == '|' || c[i + k] == '/') {
                            break;
                        }
                    }
                }
            }
            int sum = 0;
            for (int i = 0; i < p.length; i++) {
                sum += p[i];
            }
            System.out.println(sum / p.length);
        }
    }
}

