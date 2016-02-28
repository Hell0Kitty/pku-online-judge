import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

	public static void main(String[] args) throws Exception{

		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int totalnum;
		int count = 0;
		//while((totalnum=Integer.parseInt(in.readLine()))!=-100){
		while(true)	{
			int num;
			ArrayList <Integer> array = new ArrayList<Integer>();
			
			totalnum=Integer.parseInt(in.readLine());
			
			if(totalnum==-1)
				break;
			array.add(totalnum);
			while((num=Integer.parseInt(in.readLine()))!=-1){
				array.add(num);
			}
			
			int length = array.size();
			
			int [] num_array = new int[length];
			int [] max_array = new int[length];
			
			for(int i=0;i<length;i++){
				num_array[i] = array.get(i);
				max_array[i] = 1;
			}
			
			int max_value = 1;
			for(int i=1;i<length;i++){
				for(int j=0;j<i;j++){
					if(num_array[i]<=num_array[j]&&max_array[i]<=max_array[j])
						max_array[i]++;
				}
				max_value = (max_array[i]>max_value)?max_array[i]:max_value;
			}
			
			if(count!=0)
				System.out.println();
			System.out.println("Test #"+(++count)+":");
			System.out.println("  maximum possible interceptions: "+max_value);
		}
		
		
	}

}
