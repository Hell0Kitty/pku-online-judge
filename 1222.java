import java.util.Scanner; 

public class Main { 

    int times; 
    int[][] puzzle; 
    static final int length = 6; 
    static final int width = 5; 
    int[][] arr; 
    int temp; 
    int req; 

    public Main() { 
        Scanner scan = new Scanner(System.in); 
        times = scan.nextInt(); 
        for (int t = 0; t < times; t++) { 
            puzzle = new int[width][length]; 
            arr = new int[width][length]; 
            for (int i = 0; i < width; i++) { 
                for (int j = 0; j < length; j++) { 
                    puzzle[i][j] = scan.nextInt(); 
                } 
            } 
            force(); 
            System.out.println("PUZZLE #" + (t + 1)); 
            for (int i = 0; i < width; i++) { 
                for (int j = 0; j < length; j++) { 
                    System.out.print(arr[i][j] + " "); 
                } 
                System.out.println(); 
            } 
        } 
    } 

    //穷举第一行数据，推导下面的数据... 
    //判断最后一行是否符合要求 
    //6列需要最多计算2^6=64次 
    public void force() { 
        boolean result = false; 
        do { 
            result = search(); 
            if (result) { 
                return; 
            } 
        } while (plus(arr[0], 0)); 
    } 

    public boolean search() { 
        for (int i = 1; i < width; i++) { 
            for (int j = 0; j < length; j++) { 
                req = puzzle[i - 1][j]; 
                temp = 0; 
                if (j - 1 >= 0) { 
                    temp += arr[i - 1][j - 1]; 
                } 
                if (j + 1 < length) { 
                    temp += arr[i - 1][j + 1]; 
                } 
                if (i - 2 >= 0) { 
                    temp += arr[i - 2][j]; 
                } 
                temp += arr[i - 1][j]; 
                if (req != (temp % 2)) { 
                    arr[i][j] = 1; 
                } else { 
                    arr[i][j] = 0; 
                } 
            } 
        } 
        for (int i = 0; i < length; i++) { 
            req = puzzle[width - 1][i]; 
            temp = 0; 
            if (i - 1 >= 0) { 
                temp += arr[width - 1][i - 1]; 
            } 
            temp += arr[width - 2][i]; 
            temp += arr[width - 1][i]; 
            if (i + 1 < length) { 
                temp += arr[width - 1][i + 1]; 
            } 
            if (req != (temp % 2)) { 
                return false; 
            } 
        } 
        return true; 
    } 

    public boolean plus(int[] a, int b) { 
        if (b == length) { 
            return false; 
        } else if (a[b] == 0) { 
            a[b]++; 
            return true; 
        } else { 
            a[b] = 0; 
            return plus(a, ++b); 
        } 
    } 

    public static void main(String[] args) { 
        new Main(); 
    } 

} 