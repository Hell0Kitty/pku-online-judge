//* @author popop0p0popo
import java.util.*;
import java.io.*;

public class Main{
 public static void main(String[] args) throws Exception{
  BufferedReader scanner=new BufferedReader(new InputStreamReader(System.in));
  int n=Integer.parseInt(scanner.readLine());
  String f;
  String[] t;
  double a1,a2,b1,b2;
  for (int i=0;i< n ;i++ ){
    a1=0;
    a2=0;
    b1=0;
    b2=0;
    f=scanner.readLine();
    t=f.split("=");
    String e="";
    char oper='+';
    for (int j=0;j< t[0].length() ;j++ ){
        if (t[0].charAt(j)=='-'||t[0].charAt(j)=='+'){
            if (e.charAt(e.length()-1)=='x'){
                if (e.equals("x")){
                    e="1x";
                }
          a1=a1+Double.parseDouble(oper+e.substring(0,e.length()-1));
            }
            else{
                b1=b1+Double.parseDouble(oper+e);
            }
            oper=t[0].charAt(j);
            e="";
        }
        else{
            if (t[0].charAt(j)!=' '){
                e=e+t[0].charAt(j);
            }
        }
    }
    if (!e.equals("")){
        if (e.charAt(e.length()-1)=='x'){
            if (e.equals("x")){
                e="1x";
            }
      a1=a1+Double.parseDouble(oper+e.substring(0,e.length()-1));
        }
        else{
            b1=b1+Double.parseDouble(oper+e);
        }
    }
    e="";
    oper='+';
    for (int j=0;j< t[1].length() ;j++ ){
        if (t[1].charAt(j)=='-'||t[1].charAt(j)=='+'){
            if (e.charAt(e.length()-1)=='x'){
                if (e.equals("x")){
                    e="1x";
                }
              a2=a2+Double.parseDouble(oper+e.substring(0,e.length()-1));
            }
            else{
                b2=b2+Double.parseDouble(oper+e);
            }
            e="";
            oper=t[1].charAt(j);
        }
        else{
            if (t[1].charAt(j)!=' '){
                e=e+t[1].charAt(j);
            }
        }
    }
    if (!e.equals("")){
        if (e.charAt(e.length()-1)=='x'){
            if (e.equals("x")){
                e="1x";
            }
        a2=a2+Double.parseDouble(oper+e.substring(0,e.length()-1));
        }
        else{
            b2=b2+Double.parseDouble(oper+e);
        }
    }
    if (a1==a2){
        if (b1==b2){
            System.out.println("IDENTITY");
        }
        else{
            System.out.println("IMPOSSIBLE");
        }
    }
    else{
      System.out.println((int)Math.floor((b2-b1)/(a1-a2)));
    }
  }
 }
}


