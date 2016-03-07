import java.util.*;

public class Main {

public static void main(String[] args) {
   Scanner cin = new Scanner(System.in);
   List<String> s1 = new ArrayList<String>();
   List<String> s2 = new ArrayList<String>();
   int indexS1 = 0;
   int indexS2 = 0;
   s1.add(cin.nextLine());
   while(s1.get(indexS1).charAt(0) != 'X') {
    indexS1++;
    s1.add(cin.nextLine());
   }
   s1.remove(indexS1);
   Collections.sort(s1);
  
   s2.add(cin.nextLine());
   while(s2.get(indexS2).charAt(0) != 'X') {
    indexS2++;
    s2.add(cin.nextLine());
   }
   s2.remove(indexS2);
  
   for(int i=0; i<s2.size(); i++) {
    boolean out = false;
    for(int j=0; j<s1.size(); j++) {
     if(isSame(s2.get(i), s1.get(j))) {
      System.out.println(s1.get(j));
      out = true;
     }
    }
    if(!out) {
     System.out.println("NOT A VALID WORD");
    }
     System.out.println("******");
   }
  
}

private static boolean isSame(String n1, String n2) {
   if(n1.length() != n2.length())
    return false;
   char[] first = n1.toCharArray();
   char[] secound = n2.toCharArray();
   Arrays.sort(first);
   Arrays.sort(secound);
   for(int i=0; i<first.length; i++) {
    if(first[i] != secound[i])
     return false;
   }
   return true;
}

}
