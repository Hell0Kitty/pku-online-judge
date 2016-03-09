import java.util.Scanner;

public class Main {

    /**
     * @param args
     */
    public static int row;
    public static int column;

    public static int replace(int i, int j, int[][] array) {
        int temp = 0;
        if (array[i][j] == 'R')
            temp = 'P';
        else if (array[i][j] == 'S')
            temp = 'R';
        else if (array[i][j] == 'P')
            temp = 'S';

        if (i + 1 < row && array[i + 1][j] == temp)
            return temp;
        if (j + 1 < column && array[i][j + 1] == temp)
            return temp;
        if (i > 0 && array[i - 1][j] == temp)
            return temp;
        if (j > 0 && array[i][j - 1] == temp)
            return temp;
        return array[i][j];
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        for (int i = 0; i < n; i++) {
            row = in.nextInt();
            column = in.nextInt();
            int day = in.nextInt();
            String s = in.nextLine();
            int[][] array = new int[row][column];
            int[][] temp = new int[row][column];
            for (int j = 0; j < row; j++) {
               String line = in.nextLine();
               //System.out.println(line);
               for (int k = 0; k < column; k++) {
                array[j][k] = line.charAt(k);
               }
            }

         for (int m = 0; m < day; m++) {
          for (int j = 0; j < row; j++) {
            for (int k = 0; k < column; k++) {
                temp[j][k] = replace(j, k, array);
            }
          }
         int count = 0;
         for (int j = 0; j < row; j++) {
            for (int k = 0; k < column; k++) {
                if (temp[j][k] == temp[0][0])
                    count++;
                array[j][k] = temp[j][k];
            }
        }
        if (count == row * column) {
            break;
        }
    }
    for (int j = 0; j < row; j++) {
        // String line = in.nextLine();
        for (int k = 0; k < column; k++) {
            System.out.print((char) array[j][k]);
        }

            System.out.println();
    }
    if(i!=n-1)
        System.out.println();
     }

  }

}

