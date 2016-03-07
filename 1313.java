import java.util.*;
public class Main {
  
 public static void main(String[] args){

    Scanner in = new Scanner(System.in);
	
    int n,max;
    int i;
    while(in.hasNext()){
        n=in.nextInt();
        if(n==0) break;
        max=n/4+1;
        System.out.printf("Printing order for %d pages:\n",n);
        if(n%4==1){
            int k=3;
            if(n==1)  System.out.printf("Sheet 1, front: Blank, 1\n");
            else{
                System.out.printf("Sheet 1, front: Blank, 1\n");
                System.out.printf("Sheet 1, back : 2, Blank\n");
            }
            if(max>1){
                System.out.printf("Sheet 2, front: Blank, %d\n",k++);
                System.out.printf("Sheet 2, back : %d, %d\n",k++,n--);
                for(i=3;i<=max;i++){
                    System.out.printf("Sheet %d, front: %d, %d\n",i,n--,k++);
                    System.out.printf("Sheet %d, back : %d, %d\n",i,k++,n--);
                }
            }
        }
        else if(n%4==2){
           int k=3;
            System.out.printf("Sheet 1, front: Blank, 1\n");
            System.out.printf("Sheet 1, back : 2, Blank\n");
            for(i=2;i<=max;i++){
                System.out.printf("Sheet %d, front: %d, %d\n",i,n--,k++);
                System.out.printf("Sheet %d, back : %d, %d\n",i,k++,n--);
            }
        }
        else if(n%4==3){
            int k=3;
            System.out.printf("Sheet 1, front: Blank, 1\n");
            System.out.printf("Sheet 1, back : 2, %d\n",n--);
            for(i=2;i<=max;i++){
                System.out.printf("Sheet %d, front: %d, %d\n",i,n--,k++);
                System.out.printf("Sheet %d, back : %d, %d\n",i,k++,n--);
            }
        }
        else {
            max--;
            int k=1;
            for(i=1;i<=max;i++){
                System.out.printf("Sheet %d, front: %d, %d\n",i,n--,k++);
                System.out.printf("Sheet %d, back : %d, %d\n",i,k++,n--);
            }
        }
    }
   }
}