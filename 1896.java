//* @author:alpc12
import java.util.*;
import java.io.*;

public class Main {
 public static void main(String[] args) throws Exception {
  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
  String line;
  StringBuffer sb = new StringBuffer();
  while ((line = in.readLine()) != null) {
	for (int i = 0; i < line.length(); i++) {
         char ch = line.charAt(i);
	  if (ch != ' ' && ch != 9)
		sb.append(ch);
	}
   }
  in.close();

  int indent = 1;
  boolean needws = true;
  System.out.println("{");
  for (int i = 1; i < sb.length(); i++) {
        char ch = sb.charAt(i);
	if (needws && ch != '}') {
		printws(indent);
		needws = false;
	}
      switch (ch) {
        case '{':
           System.out.println(" {");
           indent++;
           needws = true;
	    break;
	case '}':
	   needws = false;
	   indent--;
	   printws(indent);
	  System.out.print("}");
	  break;
      case ';':
	  System.out.println(";");
	  needws = true;
	  break;
      case ',':
	  System.out.print(", ");
	  break;
      default:
	  System.out.print(ch);
     }
  }
}

private static void printws(int indent) {
 for (int i = indent; --i >= 0;)
	System.out.print("    ");
 }
}

