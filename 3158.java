//* @author  mekarlos@gmail.com
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        String s1,s2,s;
        int[] m;
        int k,v1,v2;
        boolean band;
        while(scan.hasNext()){
            s1=scan.next();
            s2=scan.next();
            s=s1;
            for(int i=0;i< s2.length();i++)s+="1";
            k=-1;
            for(int i=0;i<=s.length();i++){
                band=true;
                for(int j=0;j< s2.length();j++){
                 if((Integer.parseInt(s2.charAt(j)+"")+Integer.parseInt(s.charAt(i+j)+""))>3)
                    {
                      band=false;break;
                   }
                }
                if(band){k=i;break;}
            }
            v1=Math.max(s1.length(),k+s2.length());
            s=s2;
            for(int i=0;i< s1.length();i++)s+="1";
            k=-1;
            for(int i=0;i<=s.length();i++){
                band=true;
                for(int j=0;j< s1.length();j++){
                 if((Integer.parseInt(s1.charAt(j)+"")+Integer.parseInt(s.charAt(i+j)+""))>3)
                      {band=false;break;}
                }
                if(band){k=i;break;}
            }
            v2=Math.max(s2.length(),k+s1.length());
            System.out.println(Math.min(v1, v2));
        }
    }
}

