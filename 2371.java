import java.util.Arrays;
import java.util.Scanner;
public class Main {

    public static void quickSort(int[] data, int s, int t) {
        int i = s+1;
        int j = t;
        int x = data[s];
        while (i <= j) {
            while (i <= j && data[j] >= x)
                --j;
            while (i <= j && x >= data[i])
                ++i;
            if (i <= j) {
                data[i] = data[j] + ((data[j] = data[i]) & 0);
                i++;
                j--;
            }
        }

        if (j != s) {
            data[s] = data[j];
            data[j] = x;
        }
        if (s < j - 1)
            quickSort(data, s, j - 1);
        if (j + 1 < t)
            quickSort(data, j + 1, t);
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int sum = sc.nextInt();
        int[] database = new int[sum];
        for (int i = 0; i < sum; ++i) {
            database[i] = sc.nextInt();
        }
        // Arrays.sort(database);
        quickSort(database, 0, database.length-1);
        sc.nextLine();
        sc.nextLine();
        int queryCount = sc.nextInt();
        for (int i = 0; i < queryCount; ++i) {
            int queryNum = sc.nextInt();
            System.out.println(database[queryNum - 1]);
        }
//      for(int i = 0 ; i < database.length ;++i)
//          System.out.print(database[i]+" ");
    }

}

