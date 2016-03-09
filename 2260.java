import java.util.Scanner;

public class Main {

/**
 * @param args
 */
public static void main(String[] args) {
 // TODO Auto-generated method stub
    Scanner in = new Scanner(System.in);
    while (true) {
        int n = in.nextInt();
        if (n == 0)
            break;
        Byte[][] matrix = new Byte[n][n];
        int row = 0;
        int sign1 = 0;
        int column = 0;
        int sign2 = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
              matrix[i][j] = in.nextByte();
              sum += matrix[i][j];
            }
            if (sum % 2 == 1) {
                sign1 = i + 1;
                row++;
            }
        }
        if (row > 1) {
           System.out.println("Corrupt");
           continue;
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                        sum += matrix[j][i];
            }
            if (sum % 2 == 1) {
                sign2 = i + 1;
                column++;
            }
        }
        if (column > 1) {
            System.out.println("Corrupt");
            continue;
        }
        if (column == 1 && row == 1)
         System.out.println("Change bit (" + sign1 + "," + sign2 + ")");
        if ((column | row) == 0)
            System.out.println("OK");
        }
    }

}

