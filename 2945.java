import java.util.HashMap;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			int n = sc.nextInt();
			int m = sc.nextInt();
			if (n == 0 && m == 0)
				break;
			sc.nextLine();
			HashMap< String, Integer> map = new HashMap< String, Integer>();
			int[] dispear = new int[n];
			for (int i = 0; i < n; ++i) {
				String dna = sc.nextLine();
				// /Integer hasCode = dna.hashCode();
				if (map.get(dna) != null) {
					map.put(dna, map.get(dna) + 1);
					dispear[map.get(dna) - 1]--;
					dispear[map.get(dna)]++;
				} else {
					map.put(dna, 0);
					dispear[0]++;
				}
			}
			for (int i = 0; i < n; ++i) {
				System.out.println(dispear[i]);
			}
		}
	}
}

