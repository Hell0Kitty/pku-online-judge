import java.io.*; 
import java.util.*; 

public class Main 
{ 
    static Room[][] matrix; 
    static int row; 
    static int col; 
    public static void main(String[] args) throws Exception 
    { 
        readFile(); 
        for(int i=0; i<row; i++) 
        { 
            for(int j=0; j<col; j++) 
            { 
                if(!matrix[i][j].bFlag) 
                { 
                    process(i,j); 
                    sumCount++; 
                    if(maxCount>INF) 
                    { 
                        INF = maxCount; 
                    } 
                    maxCount=0; 
                } 
            } 
        } 
        System.out.print(sumCount); 
        System.out.print("\n"+INF); 
    } 

    public static void readFile() throws Exception 
    { 
        BufferedReader br = new BufferedReader( 
            new InputStreamReader(System.in)); 
        StringTokenizer st = null; 
        row = Integer.valueOf(br.readLine()); 
        col = Integer.valueOf(br.readLine()); 
        matrix = new Room[row][col]; 
        int count = 0; 
        while(count<row) 
        { 
            st = new StringTokenizer(br.readLine()," "); 
            int j = 0; 
            Room room = null; 
            while(st.hasMoreTokens()) 
            { 
                room = new Room(Integer.valueOf(st.nextToken())); 
                matrix[count][j] = room; 
                j++; 
            } 
            count++; 
        } 
    } 

    static void displayRoom() 
    { 
        for(int i=0; i<row; i++) 
        { 
            for(int j=0; j<col; j++) 
                System.out.println(matrix[i][j]); 
            System.out.println(); 
        } 
    } 


    static int sumCount = 0; 
    static int maxCount = 0; 
    static int INF = 0; 
    static void process(int i,int j) 
    { 
        if(i<0 || j<0 || i>=row || j>=col) 
            return; 
        if(matrix[i][j].bFlag) 
            return; 
        maxCount++; 
        matrix[i][j].bFlag = true; 
        if(matrix[i][j].states[0][1]==2) 
        { 
            process(i-1,j); 
        } 
        if(matrix[i][j].states[1][2]==2) 
        { 
            process(i,j+1); 
        } 
        if(matrix[i][j].states[2][1]==2) 
        { 
            process(i+1,j); 
        } 
        if(matrix[i][j].states[1][0]==2) 
        { 
            process(i,j-1); 
        } 
         
         
    } 

     
    static class Room 
    { 
        int[][] states = new int[3][3]; 
        boolean bFlag = false; 
        Room(int flag) 
        { 
            states[1][1] = 1; 
            switch(flag) 
            { 
            case 0: 
                states[0][1] = 2; 
                states[1][2] = 2; 
                states[1][0] = 2; 
                states[2][1] = 2; 
                break; 
            case 1: 
                states[0][1] = 2; 
                states[1][2] = 2; 
                states[2][1] = 2; 
                break; 
            case 2: 
                states[1][0] = 2; 
                states[1][2] = 2; 
                states[2][1] = 2; 
                break; 
            case 3: 
                states[1][2] = 2; 
                states[2][1] = 2; 
                break; 
            case 4: 
                states[0][1] = 2; 
                states[1][0] = 2; 
                states[2][1] = 2; 
                break; 
            case 5: 
                states[0][1] = 2; 
                states[2][1] = 2; 
                break; 
            case 6: 
                states[1][0] = 2; 
                states[2][1] = 2; 
                break; 
            case 7: 
                states[2][1] = 2; 
                break; 
            case 8: 
                states[0][1] = 2; 
                states[1][0] = 2; 
                states[1][2] = 2; 
                break; 
            case 9: 
                states[0][1] = 2; 
                states[1][2] = 2; 
                break; 
            case 10: 
                states[1][0] = 2; 
                states[1][2] = 2; 
                break; 
            case 11: 
                states[1][2] = 2; 
                break; 
            case 12: 
                states[0][1] = 2; 
                states[1][0] = 2; 
                break; 
            case 13: 
                states[0][1] = 2; 
                break; 
            case 14: 
                states[1][0] = 2; 
                break; 
            case 15: 
                break; 
            } 
        } 

        public String toString() 
        { 
            for(int i=0; i<3; i++) 
            { 
                for(int j=0; j<3; j++) 
                    System.out.print(states[i][j] + " "); 
                System.out.println(); 
            } 
            return ""; 
        } 
    } 
}