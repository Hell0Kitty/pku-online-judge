//* @author  mekarlos@gmail.com
import java.util.Hashtable;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Hashtable< Integer,Integer> table;
        Scanner scan=new Scanner(System.in);
        int M[]=new int[300];
        int n=scan.nextInt(),k=0,m=1;
        boolean band=false;
        for(int i=0;i< n;i++){
            k=scan.nextInt();
            band=true;
            table=new Hashtable< Integer, Integer>();
            for(int j=0;j< k;j++){
                M[j]=scan.nextInt();
            }
            m=k;
            while(true){
                band=true;
                for(int j=0;j< k;j++){
                    if(table.get((M[j]%m))==null){
                        table.put((M[j]%m), 0);
                    }
                    else {
                        band=false;
                        break;
                    }
                }
                if(band==true) break;
                table.clear();
                m++;
            }
            System.out.println(m);
        }
    }
}

