import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String[] kws;
		String[] exs,exsk;
		int[] kn;
		String fl;
		int n,m,max;
		int index=1;
		while (scanner.hasNext()){
			fl=scanner.nextLine();
			String[] t=fl.split(" ");
			n=Integer.parseInt(t[0]);
			m=Integer.parseInt(t[1]);
			kws=new String[n];
			exsk=new String[m];
			exs=new String[m];
			kn=new int[m];
			for (int i=0;i<n ;i++ ){
				kws[i]=scanner.nextLine().toLowerCase();
			}
			for (int i=0;i<m ;i++ ){
				exsk[i]=scanner.nextLine();
				exs[i]=exsk[i].toLowerCase();
				String tmp="";
				for (int j=0;j<exs[i].length() ;j++ ){
					if (Character.isLetter(exs[i].charAt(j))){
						tmp=tmp+exs[i].charAt(j);
					}
					else{
						tmp=tmp+"#";
					}
				}
				exs[i]=tmp;
				for (int j=0;j<n ;j++ ){
					if (exs[i].indexOf("#"+kws[j]+"#")!=-1){
						kn[i]++;
					}
					else if (exs[i].indexOf(kws[j]+"#")==0){
						kn[i]++;
					}
					else if (exs[i].indexOf("#"+kws[j])+kws[j].length()+1==exs[i].length()){
						kn[i]++;
					}
				}
			}
			max=kn[0];
			for (int i=1;i<kn.length ;i++ ){
				if (kn[i]>max){
					max=kn[i];
				}
			}
			System.out.println("Excuse Set #"+index++);
			for (int i=0;i<m ;i++ ){
				if (kn[i]==max){
					System.out.println(exsk[i]);
				}
			}
			System.out.println();
		}
	}
}