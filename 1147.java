import java.io.*;
import java.util.*;
public class Main {
	static public void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		n = cin.nextInt();
		int i, j;
		int[] next = new int[3003];
		int[] a = new int[3003];
		int[] b = new int[3003];
		boolean[] used = new boolean[3003];
		int ones = 0;
		for (i=0; i<n; i++) used[i] = false;
		for (i=0; i<n; i++) {
			a[i] = cin.nextInt();
			ones += a[i];
		}
		for (i=0; i<n-ones; i++) b[i] = 0;
		for (i=n-ones; i<n; i++) b[i] = 1;
		j = 0;
		for (i=0; i<n; i++) {
				while (b[i] != a[j] || used[j]) j++;
				used[j] = true;
				next[i] = j;
				j = 0;
		}
		j = 0;
		j = next[j];
		System.out.print(a[j]);
		for (i=1; i<n; i++) {
			j = next[j];
			System.out.print(" " + a[j]);
		}
	}
}
