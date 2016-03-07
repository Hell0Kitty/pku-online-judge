import java.util.Scanner;
import java.util.Vector;
public class Main {
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        Vector<Long> v=new Vector<Long>();
        v.add(new Long(1));
        int i=0,j=0,k=0;
        while(v.size()<1500){
            v.add(Math.min(Math.min(v.get(i)*2, v.get(j)*3), v.get(k)*5));
           if(v.get(v.size()-1).equals(v.get(v.size()-2))){v.remove(v.size()-1);}
            if(v.get(i)*2==v.get(v.size()-1))i++;
            else if(v.get(j)*3==v.get(v.size()-1))j++;
            else k++;
        }
       int n=1;      
       while((n=scan.nextInt())!=0){
            System.out.println(v.get(n-1));
        }        
    }
}