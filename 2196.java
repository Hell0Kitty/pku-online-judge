//* @author popop0p0popo
public class Main{
    public static void main(String[] args){
        int t,h,w;
        for (int i=2992;i< 10000 ;i++ ){
            t=getI(i);
            h=getD(Integer.toHexString(i));
            w=getD(Integer.toString(i,12));
            if (t==h&&h==w){
                System.out.println(i);
            }
        }
    }

    public static int getD(String n){
        int d=0;
        for (int i=0;i< n.length() ;i++ ){
            if (Character.isLetter(n.charAt(i))){
                d=d+10+(int)(n.charAt(i)-'a');
            }
            else{
                d=d+(int)(n.charAt(i)-'0');
            }
        }
        return d;
    }

    public static int getI(int n){
        int a=n/1000;
        int b=(n-1000*a)/100;
        int c=(n-1000*a-100*b)/10;
        int d=n-1000*a-100*b-10*c;
        return a+b+c+d;
    }
}

