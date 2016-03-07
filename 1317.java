import java.util.*;
/**
 *
 * @author Leo
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int key=1;
        String ciphertext;
        while(true){
            key=sc.nextInt();
            if(key==0) break;
            ciphertext=sc.next();
            int [] plaincode=new int [ciphertext.length()];
            int [] ciphercode=new int [ciphertext.length()];
            for(int i=0;i<ciphertext.length();i++){
                if(ciphertext.charAt(i)=='.') ciphercode[i]=27;
                else if (ciphertext.charAt(i)=='_') ciphercode[i]=0;
                else ciphercode[i]=ciphertext.charAt(i)-'a'+1;
            }
            for(int i=0;i<ciphertext.length();i++){
                plaincode[(key*i)%ciphertext.length()]=(ciphercode[i]+i)%28;
            }
            for(int i=0;i<ciphertext.length();i++){
                if(plaincode[i]==0) System.out.print('_');
                else if(plaincode[i]==27) System.out.print('.');
                else System.out.print((char)(plaincode[i]-1+'a'));
            }
            System.out.println();
        }
        // TODO code application logic here
    }

}