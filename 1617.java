
rt java.io.*;
import java.util.*;
public class Main {

 public static void main(String[] args)throws IOException{

  BufferedReader br = new BufferedReader(new
                InputStreamReader(System.in));
  String s;
  String ciphertext;
  int codesize;
  int textrow;
  int colnum;
  StringBuilder sb;
  while((s=br.readLine())!=null&&!s.equals("THEEND")){

    //length of the code
    codesize = s.length();
    char[] code = compile(s);
    ciphertext = br.readLine();
    //rows of the text
    textrow = ciphertext.length()/codesize;
    sb = new StringBuilder(ciphertext);
    for(int i=0;i< codesize;i++){
      colnum = code[i]-'0';
      for(int j=0;j< textrow;j++){
         sb.setCharAt(j*codesize+colnum, ciphertext.charAt(i*textrow+j));
      }
    }
    System.out.println(sb.toString());
  }
  br.close();
 }

 static char[] compile(String code){

  char[] array = code.toCharArray();
  StringBuilder sb = new StringBuilder(array.length);
  for(char c='A';c<='Z';c++){
   for(int i=0;i< array.length;i++){
     if(c==array[i]){
         sb.append(i);
     }
   }
 }
 return sb.toString().toCharArray();
}
}

