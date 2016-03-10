import java.util.*;
import java.math.BigInteger;
public class Main {

 static String doAdd(String a, String b) { //两个大数相加的方法。
        String str = "";
        int lenA = a.length();
        int lenB = b.length();
        int maxLen = (lenA > lenB) ? lenA : lenB;
        int minLen = (lenA < lenB) ? lenA : lenB;
        String strTmp = "";
        for (int i = maxLen - minLen; i > 0; i--) {
            strTmp += "0";
        }
        // 把长度调整到相同
        if (maxLen == lenA) {
            b = strTmp + b;
        } else
            a = strTmp + a;
        int JW = 0;// 进位
        for (int i = maxLen - 1; i >= 0; i--) {
            int tempA = Integer.parseInt(String.valueOf(a.charAt(i)));
            int tempB = Integer.parseInt(String.valueOf(b.charAt(i)));

            int temp;
            if (tempA + tempB + JW >= 10 && i != 0) {
                temp = tempA + tempB + JW - 10;
                JW = 1;
            } else {
                temp = tempA + tempB + JW;
                JW = 0;
            }
            str = String.valueOf(temp) + str;
        }
        return str;
    }



  public static void main(String[] args) {
  Scanner in=new Scanner(System.in);

  String a[]=new String [100];
  while(in.hasNext()){
  a[0]=Integer.toString(in.nextInt());
  a[1]=Integer.toString(in.nextInt());
  a[2]=Integer.toString(in.nextInt());
  for(int i=3;i< 100;i++){
     String temp=doAdd(a[i-1],a[i-2]);
     a[i]=doAdd(temp,a[i-3]);
   }

   System.out.println(a[99]);
  }
 }
}

