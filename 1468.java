import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        int n=0,k=0;
        boolean band;
        int M[][]=new int[5000][4];
        while(scan.hasNext()){
            n=scan.nextInt();
            for(int i=0;i<n;i++){
                for(int j=0;j<4;j++){
                    M[i][j]=scan.nextInt();
                }
            }
            k=0;
            for(int i=0;i<n;i++){
                band=false;
                for(int j=0;j<n;j++){
                    if(j!=i&&M[j][0]<=M[i][0]&&M[j][1]>=M[i][1]&&M[j][2]<=M[i][2]&&M[j][3]>=M[i][3]){
                        band=true;
                        break;
                    }
                }
                if(band)k++;
            }
            System.out.println(k);
        }
    }
}