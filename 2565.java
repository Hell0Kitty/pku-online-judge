import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
public class Main {
 public static void main(String[] args) throws IOException{
  // TODO Auto-generated method stub
  Scanner scan=new Scanner(System.in);
  BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
  StringTokenizer tokens;
  tokens=new StringTokenizer(scan.nextLine());
  int n=new Integer(tokens.nextToken());
  double d=new Double(tokens.nextToken());
  double result;
  int num;
  String a="";
  int h,m,s;
  int i1,i2;
  int aux;
  while(scan.hasNext()){
	h=0;
	m=0;
	s=0;
	tokens=new StringTokenizer(scan.nextLine());
	num=new Integer(tokens.nextToken());
	for(int i=0;i< n;i++){
		a=tokens.nextToken();
		if(a.lastIndexOf('-')>=0) {
			h=-1;
			break;
		}
		i1=a.indexOf(':');
		i2=a.lastIndexOf(':');
		aux=new Integer(a.substring(0, i1));
		h+=aux;
		aux=new Integer(a.substring(i1+1,i2));
		m+=aux;
		s+=new Integer(a.substring(i2+1,a.length()));
	}
	if(h==-1) {
			a=num+"";
			for(int j=0;j< 3-a.length();j++) System.out.print(" ");
			System.out.print(num+": -\n");
	}
	else{
			result=h*3600+m*60+s;
			result=result/(d*60);
			m=(int)Math.floor(result);
			result=result-m;
			result*=60;
			s=(int)Math.round(result);
			if(s==60){
				s=0;
				m++;
			}
			a=num+"";
			for(int j=0;j< 3-a.length();j++) System.out.print(" ");
			a="";
			if(s< 10)a="0";
			System.out.print(num+": "+m+":"+a+s+" min/km\n");
	}
  }
 }
}

