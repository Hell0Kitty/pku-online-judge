/* @author:SmilingWang */
import java.util.*;

public class Main {
 static StringBuffer res = new StringBuffer();
 public static void main(String[] args){
  Scanner in = new Scanner(System.in);
  int m = in.nextInt();
  int n = in.nextInt();
  int k = in.nextInt();

  Map< String, String> symbol_table = new HashMap< String, String>();
  Map< String, Integer> symbol_pos_table = new HashMap< String,Integer>();
  for(int i = 0; i < m; i++){
   String name = in.next();
   String type = in.next();

   symbol_pos_table.put(name, i);
   symbol_table.put(name, type);
  }

  String[][] table = new String[n][m];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
    table[i][j] = in.next();
    }

  }

  for(int i = 0; i < k; i++){
   in.next();
   String cols = in.next();
   in.next();
   String op = in.next();
   StringTokenizer st = new StringTokenizer(cols, ",");

   ArrayList[] result = new ArrayList[st.countTokens()];
   int len = 0;
   String result_index_table[] = new String[st.countTokens()];

   while(st.hasMoreTokens()){
    result[len] = new ArrayList< String>();
    String col = st.nextToken();
    result_index_table[len] = col;

    int index = symbol_pos_table.get(col);
    int sp = -1;
    String op1="", op2="";
    char opt = 0;
    if((sp=op.indexOf(">")) > 0){
    op1 = op.substring(0, sp);
    op2 = op.substring(sp+1, op.length());
    opt = '>';
    }
    else if((sp=op.indexOf("=")) > 0){
    op1 = op.substring(0, sp);
    op2 = op.substring(sp+1, op.length());
    opt = '=';
    }
    else if((sp=op.indexOf("< ")) > 0){
    op1 = op.substring(0, sp);
    op2 = op.substring(sp+1, op.length());
    opt = '< ';
    }

    for(int r = 0; r < table.length; r++){
    String op_type = symbol_table.get(op1);
    int op_index = symbol_pos_table.get(op1);

    if(op_type.equals("INT")){
      if(opt=='>'){
       if(Integer.parseInt(table[r][op_index]) > Integer.parseInt(op2)){
        result[len].add(table[r][index]);
       }
     }
      else if(opt == '='){
    if(Integer.parseInt(table[r][op_index]) == Integer.parseInt(op2)){
      result[len].add(table[r][index]);
    }
      }
     else if(opt == '< '){
    if(Integer.parseInt(table[r][op_index]) < Integer.parseInt(op2)){
      result[len].add(table[r][index]);
    }
     }
   }
   else if(op_type.equals("STR")){
    if(table[r][op_index].equals(op2.replaceAll("\"", ""))){
        result[len].add(table[r][index]);
    }
   }
  }
  len++;
  }

  int table_len[] = new int[result_index_table.length];
  for(int x = 0; x < table_len.length; x++){
   int max = result_index_table[x].length();
   for(int y = 0; y < result[x].size(); y++){
    String item = result[x].get(y).toString();
    if(item.length() > max){
         max = item.length();
    }
   }
   table_len[x] = max+2;
   }

   int total_len = 0;
   for(int x = 0; x < table_len.length; x++){
    total_len += table_len[x];
   }

   total_len += (table_len.length + 1);
   for(int x = 1; x <= total_len; x++){
     if(x == 1 || x == total_len){
    //System.out.print("+");
    res.append("+");
     }
     else{
    //System.out.print("-");
    res.append("-");
     }
   }
   res.append("\n");

  for(int x = 0; x < result_index_table.length; x++){
    res.append("|");
    printCenter(result_index_table[x], table_len[x]);
    if(x == result_index_table.length-1){
         res.append("|");
    }
   }
   res.append("\n");

  for(int x = 0; x < table_len.length; x++){
    res.append("|");
    for(int y = 0; y < table_len[x]; y++){
    //System.out.print("-");
    res.append("-");
    }
    if(x == result_index_table.length-1){
    //System.out.print("|");
    res.append("|");
    }
  }

  res.append("\n");
  for(int y = 0; y < result[0].size(); y++){
   for(int x = 0; x < result.length; x++){
    //System.out.print("|");
    res.append("|");
    printCenter(result[x].get(y).toString(), table_len[x]);
    if(x == result.length-1){
         //System.out.print("|");
      res.append("|");
    }
    }
     //System.out.println();
     res.append("\n");
   }

  for(int x = 1; x <= total_len; x++){
    if(x == 1 || x == total_len){
    //System.out.print("+");
    res.append("+");
    }
    else{
    res.append("-");
    //System.out.print("-");
    }
   }
   res.append("\n");
   res.append("\n");
  }

  System.out.println(res);
  }

  public static void printCenter(String data, int space){
   int len = data.length();
   int left = (space - len)/2;
   int total_len = 0;

   for(int i = 0; i < left; i++){
    //System.out.print(" ");
    res.append(" ");
   }
  total_len += left;

  res.append(data);
  //System.out.print(data);
  total_len += data.length();

  for(int i = total_len; i < space; i++){
    //System.out.print(" ");
    res.append(" ");
   }
 }
}

