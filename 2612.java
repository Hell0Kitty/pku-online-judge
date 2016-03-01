import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    static char[][] table,touchTable,showTable;
    static int[][] counts;
    static int[] X = {0,-1,-1,-1,0,1,1,1};
    static int[] Y = {-1,-1,0,1,1,1,0,-1};
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        //Scanner scn = new Scanner(Main.class.getResourceAsStream("in.dat"));
        PrintWriter out = new PrintWriter(System.out);
        int n;
        n = scn.nextInt();
        table = new char[n][n];
        touchTable = new char[n][n];
        showTable = new char[n][n];
        counts = new int[n][n];
        boolean touched = false;
        for(int i = 0; i < n; i++){
            table[i] = scn.next().toCharArray();
        }
        for(int i = 0; i < n; i++){
            touchTable[i] = scn.next().toCharArray();
        }
        int xi = 0 ,yj = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(table[i][j] == '*'){
                    for(int k = 0; k < 8; k ++){
                        xi = i + X[k];
                        yj = j + Y[k];
                        if((xi < n && xi >= 0) && (yj < n && yj >= 0) && table[xi][yj] != 'x'){
                            counts[xi][yj]++;
                        }
                    }

                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n; j++){
                showTable[i][j] = '.';
                if(touchTable[i][j] == 'x' && table[i][j] == '.'){//没有猜到雷的情况
                    showTable[i][j] = (char)(counts[i][j] + 48);
                }else if(touchTable[i][j] == 'x' && table[i][j] == '*'){
                    touched = true;
                }
            }
        }
        if(touched){
            for(int i = 0 ; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(table[i][j] == '*'){
                        showTable[i][j] = '*';
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j ++){
                out.print(showTable[i][j]);
            }
            out.println();
        }
        out.flush();
    }
}

