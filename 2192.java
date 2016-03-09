import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main{

  public static void main(String[] args) throws Exception{

    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(in.readLine());
    for(int a=1;a<=n;a++){
        String strTemp = in.readLine();
        StringTokenizer toke = new StringTokenizer(strTemp);
        String str1 = toke.nextToken();
        String str2 = toke.nextToken();
        String str = toke.nextToken();
        int length1 = str1.length();
        int length2 = str2.length();
        //array[i][j]表示str1[i]和str2[j]能否组成str[i+j]
        boolean array[][] = new boolean[length2+1][length1+1];
        for(int i=1;i<=length1;i++){
            if(str1.substring(0, i).equals(str.substring(0,i)))
                array[0][i] = true;
            else
                array[0][i] = false;
        }
        for(int i=1;i<=length1;i++){
            if(str2.substring(0, i).equals(str.substring(0,i)))
                array[i][0] = true;
            else
                array[i][0] = false;
        }

        for(int i=1;i<=length2;i++){
            for(int j=1;j<=length1;j++){
    if(array[i][j-1]&&str1.charAt(j-1)==str.charAt(i+j-1)||array[i-1][j]&&str2.charAt(i-1)==str.charAt(i+j-1))
                    array[i][j] = true;
                else
                    array[i][j] = false;
            }
        }
        if(array[length2][length1])
            System.out.println("Data set "+a+": yes");
        else
            System.out.println("Data set "+a+": no");
    }
  }
}

