import java.io.*;
import java.util.*;

public class Main{
	public static void main(String args[]){
		int[] array = new int[10];
		array[0]=6;
		array[1]=35;
		
		for(int i=2;i<10;i++)
			array[i] = 6*array[i-1]-array[i-2];
			
		for(int i=0;i<10;i++){
			//System.out.println("  "+array[i]+"   "+(Math.sqrt(8*array[i]*array[i]+1)-1)/2);
		}
		
		System.out.println("         "+6+"         "+8);
		System.out.println("        "+35+"        "+49);
		System.out.println("       "+204+"       "+288);
		System.out.println("      "+1189+"      "+1681);
		System.out.println("      "+6930+"      "+9800);
		System.out.println("     "+40391+"     "+57121);
		System.out.println("    "+235416+"    "+332928);
		System.out.println("   "+1372105+"   "+1940449);
		System.out.println("   "+7997214+"  "+11309768);
		System.out.println("  "+46611179+"  "+65918161);
	}
}