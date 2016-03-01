iimport java.util.Scanner;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Comparator;

public class Main{
         private int[] array1;
         private int[] array2;
         PriorityQueue< Integer> heap;

       public Main(){
        }

       private void go(){
         Scanner in=new Scanner(System.in);
        int t=in.nextInt();
        while(t-->0){
         int m=in.nextInt();
         int n=in.nextInt();
         array1=new int[n];
         array2=new int[n];
         heap=new PriorityQueue< Integer>(n,new Comparator< Integer>(){
               @Override
               public int compare(Integer o1, Integer o2) {
                  if(o1< o2)
                   return 1 ;
                  else if(o1>o2){
                   return -1;
                 }else{
                   return 0;
                 }
               }
         });
          for(int i=0;i< n;i++)
            array1[i]=in.nextInt();
         Arrays.sort(array1);
         for(int i=1;i< m;i++){

            for(int j=0;j< n;j++){
              array2[j]=in.nextInt();
              heap.offer(array1[0]+array2[j]);

            }
            Arrays.sort(array2);

            for(int k=1;k< n;k++)
             for(int l=0;l< n;l++){
                if(array1[k]+array2[l]>heap.peek())
                    break;
                heap.poll();
                heap.offer(array1[k]+array2[l]);
            }
            for(int k=n-1;k>=0;k--)
            {
                array1[k]=heap.poll();

            }
        }

        System.out.printf("%d",array1[0]);
        for(int i=1;i< n;i++)
         System.out.printf(" %d",array1[i]);
        System.out.println();
      }
  }


   public static void main(String[] args){
     Main ma=new Main();
      ma.go();
   }
}
