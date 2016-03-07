import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 

public class Main { 

    public static void main(String[] args) throws IOException { 
        BufferedReader read = new BufferedReader(new InputStreamReader( 
                System.in)); 
        String[] s; 
        int[] marbles; 
        int sum; 
        int part; 
        int times = 0; 
        while (true) { 
            marbles = new int[6]; 
            sum = 0; 
            s = read.readLine().split(" "); 
            for (int i = 0; i < 6; i++) { 
                marbles[i] = Integer.parseInt(s[i]); 
            } 
            if (marbles[5] > 5) { 
                marbles[5] = 4 + marbles[5] % 2; 
            } 
            if (marbles[4] > 6) { 
                marbles[4] = 6 - marbles[4] % 2; 
            } 
            if (marbles[3] > 5) { 
                marbles[3] = 4 + marbles[3] % 2; 
            } 
            if (marbles[2] > 5) { 
                marbles[2] = 4 + marbles[2] % 2; 
            } 
            if (marbles[1] > 4) { 
                marbles[1] = 4 - marbles[1] % 2; 
            } 
            for (int i = 0; i < 6; i++) { 
                sum += marbles[i] * (i + 1); 
            } 
            if (sum == 0) { 
                break; 
            } 
            times++; 
            System.out.printf("Collection #%d:\n", times); 
            if (sum % 2 != 0) { 
                System.out.println("Can't be divided."); 
                System.out.println(); 
                continue; 
            } 
            part = sum / 2; 
            if (search(part, marbles)) { 
                System.out.println("Can be divided."); 
            } else { 
                System.out.println("Can't be divided."); 
            } 
            System.out.println(); 
        } 
    } 

    public static boolean search(int part, int[] marbles) { 
        int[] flg = new int[part + 1]; 
        flg[0] = 1; 
        for (int i = 0; i < 6; i++) { 
            for (int j = 1; j <= marbles[i]; j++) { 
                int base = j * (i + 1); 
                if (base > part) { 
                    break; 
                } 
                for (int k = part - (i + 1); k >= base - i - 1; k--) { 
                    if (flg[k] != 0) { 
                        flg[k + i + 1] = 1; 
                    } 
                    if (flg[part] != 0) { 
                        return true; 
                    } 
                } 
            } 
        } 
        return flg[part] != 0; 
    } 

} 