import java.io.*; 
import java.util.*; 

public class Main 
{ 
    static HashMap<String,String> codeMap = new HashMap<String,String>(); 
    static HashMap<String,String> ref = new HashMap<String,String>(); 

    public static void main(String[] args) throws Exception 
    { 
        initMap(); 
        readFile(); 
    } 
    static void readFile() throws Exception 
    { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int n = Integer.valueOf(br.readLine()); 
        int count = 0; 
        while(count<n) 
        { 
            process(br.readLine()); 
            count++; 
        } 
    } 
    static void initMap() 
    { 
        codeMap.put("A",".-"); 
        codeMap.put("B","-..."); 
        codeMap.put("C","-.-."); 
        codeMap.put("D","-.."); 
        codeMap.put("E","."); 
        codeMap.put("F","..-."); 
        codeMap.put("G","--."); 
        codeMap.put("H","...."); 
        codeMap.put("I",".."); 
        codeMap.put("J",".---"); 
        codeMap.put("K","-.-"); 
        codeMap.put("L",".-.."); 
        codeMap.put("M","--"); 
        codeMap.put("N","-."); 
        codeMap.put("O","---"); 
        codeMap.put("P",".--."); 
        codeMap.put("Q","--.-"); 
        codeMap.put("R",".-."); 
        codeMap.put("S","..."); 
        codeMap.put("T","-"); 
        codeMap.put("U","..-"); 
        codeMap.put("V","...-"); 
        codeMap.put("W",".--"); 
        codeMap.put("X","-..-"); 
        codeMap.put("Y","-.--"); 
        codeMap.put("Z","--.."); 
        codeMap.put("_","..--"); 
        codeMap.put(".","---."); 
        codeMap.put(",",".-.-"); 
        codeMap.put("?","----"); 

        ref.put(".-","A"); 
        ref.put("-...","B"); 
        ref.put("-.-.","C"); 
        ref.put("-..","D"); 
        ref.put(".","E"); 
        ref.put("..-.","F"); 
        ref.put("--.","G"); 
        ref.put("....","H"); 
        ref.put("..","I"); 
        ref.put(".---","J"); 
        ref.put("-.-","K"); 
        ref.put(".-..","L"); 
        ref.put("--","M"); 
        ref.put("-.","N"); 
        ref.put("---","O"); 
        ref.put(".--.","P"); 
        ref.put("--.-","Q"); 
        ref.put(".-.","R"); 
        ref.put("...","S"); 
        ref.put("-","T"); 
        ref.put("..-","U"); 
        ref.put("...-","V"); 
        ref.put(".--","W"); 
        ref.put("-..-","X"); 
        ref.put("-.--","Y"); 
        ref.put("--..","Z"); 
        ref.put("..--","_"); 
        ref.put("---.","."); 
        ref.put(".-.-",","); 
        ref.put("----","?"); 
    } 
    static void process(String str) 
    { 
        StringBuffer strCode = new StringBuffer(str); 
        StringBuffer lengthCode = new StringBuffer(); 
        StringBuffer currentCode = new StringBuffer(); 
        int index = 0; 
        while(index<strCode.length()) 
        { 
            String code = codeMap.get(strCode.charAt(index++)+""); 
            currentCode.append(code); 
            lengthCode.append(code.length()); 
        } 
        index = lengthCode.length()-1; 
        int start = 0; 
        int end = 0; 
        StringBuffer result = new StringBuffer(); 
        while(index>=0) 
        { 
            end = Integer.valueOf(lengthCode.charAt(index--)+"")+start; 
            String ttt = currentCode.substring(start,end); 
            result.append(ref.get(ttt)); 
            start = end; 
        } 
        if(flag!=0) 
            System.out.println(); 
        flag++; 
        System.out.print(flag+": " + result.toString()); 
    } 
    static int flag = 0; 
}