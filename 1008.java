 import java.util.Scanner;

 public class Main {

     public static void main(String[] args) {
         Scanner scan = new Scanner(System.in);
         int times = scan.nextInt();
         System.out.println(times);
         int day;
         int day2;
         int t_day = 0;
         int t_month;
         String month;
         String month2;
         int year;
         int year2;
         int day_num;
         int day_num2;
         for (int i = 0; i < times; i++) {
             String str_day = scan.next();
             day = Integer.parseInt(str_day.substring(0, str_day.length() - 1));
             month = scan.next();
             year = scan.nextInt();
             t_month = getHaabMonth(month);
             if(t_month<=18){
                 t_day = (t_month-1) * 20;
             }else{
                 t_day = 360;
             }
             day_num = 365 * year  +  t_day + (day + 1);
             year2 = day_num / 260;
             day_num2 = day_num % 260;
             if(day_num2 == 0){
                 year2--;
             }
             day2 = day_num2 % 13;
             if (day2 == 0) {
                 day2 = 13;
             }
             month2 = getTzolkinMonth(day_num2 % 20);
             System.out.println(day2 + " " + month2 + " " + year2);
         }
     }

     public static int getHaabMonth(String month) {
         if (month.equals("pop")) {
             return 1;
         } else if (month.equals("no")) {
             return 2;
         } else if (month.equals("zip")) {
             return 3;
         } else if (month.equals("zotz")) {
             return 4;
         } else if (month.equals("tzec")) {
             return 5;
         } else if (month.equals("xul")) {
             return 6;
         } else if (month.equals("yoxkin")) {
             return 7;
         } else if (month.equals("mol")) {
             return 8;
         } else if (month.equals("chen")) {
             return 9;
         } else if (month.equals("yax")) {
             return 10;
         } else if (month.equals("zac")) {
             return 11;
         } else if (month.equals("ceh")) {
             return 12;
         } else if (month.equals("mac")) {
             return 13;
         } else if (month.equals("kankin")) {
             return 14;
         } else if (month.equals("muan")) {
             return 15;
         } else if (month.equals("pax")) {
             return 16;
         } else if (month.equals("koyab")) {
             return 17;
         } else if (month.equals("cumhu")) {
             return 18;
         } else if (month.equals("uayet")) {
             return 19;
         } else {
             return 0;
         }
     }

     public static String getTzolkinMonth(int month) {
         if (month == 1) {
             return "imix";
         } else if (month == 2) {
             return "ik";
         } else if (month == 3) {
             return "akbal";
         } else if (month == 4) {
             return "kan";
         } else if (month == 5) {
             return "chicchan";
         } else if (month == 6) {
             return "cimi";
         } else if (month == 7) {
             return "manik";
         } else if (month == 8) {
             return "lamat";
         } else if (month == 9) {
             return "muluk";
         } else if (month == 10) {
             return "ok";
         } else if (month == 11) {
             return "chuen";
         } else if (month == 12) {
             return "eb";
         } else if (month == 13) {
             return "ben";
         } else if (month == 14) {
             return "ix";
         } else if (month == 15) {
             return "mem";
         } else if (month == 16) {
             return "cib";
         } else if (month == 17) {
             return "caban";
         } else if (month == 18) {
             return "eznab";
         } else if (month == 19) {
             return "canac";
         } else if (month == 0) {
             return "ahau";
         } else {
             return "";
         }
     } 
}