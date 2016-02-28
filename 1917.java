import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=new Integer(scan.nextLine());
        String s, k,c1,c2,c3,c4;
        int l,m;
        for (int i = 0; i < n; i++) {
             s=scan.nextLine();
             k=scan.nextLine();
             l=s.indexOf(" < ");
             m=s.indexOf(">");
             c1=s.substring(l+1, m);
             l=s.indexOf("< ", m+1);
             c2=s.substring(m+1,l);
             m=s.indexOf(">",m+1);
             c3=s.substring(l+1,m);
             c4=s.substring(m+1, s.length());
             s=s.replace("< ", "");
             s=s.replace(">", "");
             System.out.println(s);
             k=k.replace("...", "");
             k+=c3+c2+c1+c4;
             System.out.println(k);
        }
    }
}

