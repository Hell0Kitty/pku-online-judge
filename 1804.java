import java.util.*;
public class Main {   
    
   static int count=0;
    /**  
     * @param args  
     */  
    public static void main(String[] args) {  
       Scanner in=new Scanner(System.in);
       String  t=in.nextLine();
       int tcase=Integer.parseInt(t);
  
       for(int j=1;j<=tcase;j++){
         count=0;
         String str = in.nextLine();
         String b[]=str.split("\\s");
        
         int n=Integer.parseInt(b[0]);
         int a[]=new int[n];
         for(int i=0;i<n;i++)
           a[i]=Integer.parseInt(b[i+1]);
      
         sort(a);
         System.out.println("Scenario #"+j+":"); 
         System.out.println(count);
         System.out.println();
        }
    
         
	 
    }   
       
    
       
    public static void sort(int arr[]) {
          
        int temp[] = new int[arr.length];   
        mergeSort(arr,temp,0,arr.length-1);
       
    }   
       
    private static void mergeSort(int arr[],int temp[],int m,int n) {   
        if (m == n) return;   
        int mid = (m+n)/2;   
        mergeSort(arr, temp, m, mid);   
        mergeSort(arr, temp, mid+1, n);   
        for (int i = m; i <= n; i++) {   
            temp[i] = arr[i];   
        }   
        int index1 = m;   
        int index2 = mid + 1;   
        int index = m;   
  
        while (index1 <= mid && index2 <= n) {   
            if (temp[index1] <= temp[index2]) {   
                arr[index++] = temp[index1++];   
            } else {   
                arr[index++] = temp[index2++];   
                count=count+mid-index1+1;
            }   
        }   
        while(index1 <= mid) {   
            arr[index++] = temp[index1++];   
        }   
        while(index2 <= n) {   
            arr[index++] = temp[index2++];   
        }   
           
    }   
  
}  
