//* @author:
import java.util.*;
public class Main{
  static final int  MAX=400001;
  static int next[]=new int[MAX];
  static int a[]=new int[MAX];

  public static void main(String args[]){
    int i, j, len, sum;
    Scanner sc=new Scanner(System.in);

    while(sc.hasNext())
    {
        String s=sc.next();
         len=s.length();
         getNext(s);
         sum = 0;
         j = len;
        while(j != 0)
        {
            a[++sum] = j;
            j = next[j];
        }
        for (i = sum; i > 0; i--) System.out.printf("%d ",a[i]);
        System.out.printf("\n");
    }

   }
    public static void getNext(String T) {//建立模式串T的next[]表
    int i = 0;
    int j = next[0] = -1;

    while (i< T.length())
     if (0 > j || T.charAt(i) == T.charAt(j)) {//匹配
        j++; i++;
        next[i] = j;
     }else//失配
       j = next[j];
  }

}

