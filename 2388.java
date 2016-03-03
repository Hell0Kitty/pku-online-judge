import java.io.BufferedInputStream; 
import java.util.Scanner; 
public class Main{ 

    public static void main(String[] args) { 
        Scanner scan = new Scanner(new BufferedInputStream(System.in)); 
        if (scan.hasNext()) { 
            int n = scan.nextInt(); 
            int[] array = new int[n + 1]; 
            for (int i = 0; i < n; i++) { 
                array[i + 1] = scan.nextInt(); 
            } 
            quickSort(array); 
            System.out.println(array[n / 2 + 1]); 

        } 
    } 

    private static int partition(int[] array, int low, int high) { 
        int key = array[low]; 
        while (low < high) {
            while (low < high && array[high] >= key) {
                high--; 
            } 
            array[low] = array[high]; 
            while (low < high && array[low] <= key) {
                low++; 
            } 
            array[high] = array[low];  
        } 
        array[low] = key; 
        return low; 
    } 

    private static void qSort(int[] array, int low, int high) { 
        int pivotloc; 
        if (low < high) {
            pivotloc = partition(array, low, high); 
            qSort(array, low, pivotloc - 1); 
            qSort(array, pivotloc + 1, high); 
        } 
    } 

    public static void quickSort(int[] array) { 
        int n = array.length - 1; 
        qSort(array, 1, n); 
    } 
} 
