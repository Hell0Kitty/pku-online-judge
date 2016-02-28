import java.util.*;
import java.io.*;

public class Main{
	public static void main(String[] args){
		Scanner scanner=new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		String line;
		boolean flag=false;
		while (scanner.hasNext()){
			line=scanner.nextLine();
			for (int i=0;i<line.length()-1 ;i++ ){
				if (line.charAt(i)=='\"'){
					if (flag){
						line=line.replaceFirst("\"","''");
						flag=false;
					}
					else{
						line=line.replaceFirst("\"","``");
						flag=true;
					}
				}
			}
			if (line.charAt(line.length()-1)=='\"'){
				if (flag){
					line=line.replaceFirst("\"","''");
					flag=false;
				}
				else{
					line=line.replaceFirst("\"","``");
					flag=true;
				}
			}
			System.out.println(line);
		}
	}
}