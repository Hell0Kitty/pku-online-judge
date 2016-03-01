import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
 public static void main(String[] args) throws IOException {

  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

   while (true) {
	int n = Integer.parseInt(in.readLine());
	if (n == 0)
		break;
	//StringTokenizer st = new StringTokenizer(in.readLine()," ");
	String s = in.readLine();
	String[] sArray=s.split(" ");
	Map< Integer, Integer> map = new HashMap< Integer, Integer>();
	int[] array = new int[n];
	int i = 0;
//	while(st.hasMoreTokens()) {
//		int key = Integer.parseInt(st.nextToken());
//		array[i] = key;
//		map.put(key, i+1);
//		i++;
//	}
//	int sl = sArray.length;
	//System.out.println(sl);
	for(i = 0; i< n; i++){
		int key = Integer.parseInt(sArray[i]);
		array[i] = key;
		map.put(key, i+1);
	}
	int count = 0;
	for (i = 0; i < n; i++) {
		if (map.get(i+1) == array[i])
			count++;
		else
			break;
		//System.out.println(array[i]+" "+map.get(i+1));

	}
	if (count == n)
		System.out.println("ambiguous");
	else
		System.out.println("not ambiguous");

  }
 }
}

