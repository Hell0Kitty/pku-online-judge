//* @author:
import java.util.Scanner;
import java.util.Arrays;
public class Main{
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    String  s[]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    int n,y,m,d,t;
    y=sc.nextInt();
    m=sc.nextInt();
    d=sc.nextInt();
    t=(y-1)*365;
    for (int i=1;i< y;i++) if ((i%4==0&&i%100!=0)||(i%400==0)) t++;
    if ((y%4==0&&y%100!=0)||(y%400==0)) a[2]++;
    for (int i=1;i< m;i++) t+=a[i];
    t+=d+6;
    System.out.println(s[t%7]);
 }
}

