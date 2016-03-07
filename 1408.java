import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
  static double[][][] mesh=new double[32][32][2];
  public static void main(String[] args) throws Exception{
	BufferedReader br = new BufferedReader(new
                InputStreamReader(System.in));
   String s;
   String[] ss;
   int n,i,j;
   double max=0d,t;
   while((s=br.readLine())!=null&&!"0".equals(s)){
      	n=parseInt(s);
      	s=br.readLine();
      	ss=s.split(" ",n);
      	for(i=1;i<=n;i++){
      		mesh[n+1][i][0] = Double.parseDouble(ss[i-1]);
      	}
      	s=br.readLine();
      	ss=s.split(" ",n);
      	for(i=1;i<=n;i++){
      		mesh[0][i][0] = Double.parseDouble(ss[i-1]);
      		mesh[0][i][1] = 1d;
      	}
      	s=br.readLine();
      	ss=s.split(" ",n);
      	for(i=0;i< n;i++){
      		mesh[n-i][0][1] = Double.parseDouble(ss[i]);
      	}
      	s=br.readLine();
      	ss=s.split(" ",n);
      	for(i=0;i< n;i++){
    		mesh[n-i][n+1][0] = 1d;
      		mesh[n-i][n+1][1] = Double.parseDouble(ss[i]);
      	}
      	mesh[0][0][1]=
      	mesh[0][n+1][0]=mesh[0][n+1][1]=
      	mesh[n+1][n+1][0]=1d;
        	
      	for(i=1;i<=n;i++){
         for(j=1;j<=n;j++){
      	    setPoint(mesh[n+1][j][0],mesh[0][j][0],mesh[i][0][1],mesh[i][n+1][1],i,j);
         }
      }
      	for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
          t=getSquare(mesh[i][j],mesh[i][j+1],mesh[i+1][j+1],mesh[i+1][j]);
          if(t>max)
        	max=t;
        }
       }
       System.out.printf("%.6f\n",max);
       max=0d;
       reset(n+2);
    }
   }

   static void print(int n) {
	for(int i=0;i< n;i++){
        for(int j=0;j< n;j++){
	   System.out.print("["+mesh[i][j][0]+","+mesh[i][j][1]+"]");
	  }
	 System.out.println();
	}
    }

   static void setPoint(double a,double b,double c,double d,int x,int y){
	double t=1-(a-b)*(c-d);
	mesh[x][y][0]=(a-(a-b)*c)/t;
	mesh[x][y][1]=(c-a*(c-d))/t;
   }

   static double getSquare(double[] a,double[] b,double[] c,double[] d){
	double t=Math.abs((a[0]-b[0])*(c[1]-b[1])-(a[1]-b[1])*(c[0]-b[0]));
	t+=Math.abs((a[0]-d[0])*(c[1]-d[1])-(a[1]-d[1])*(c[0]-d[0]));
	return t/2;
   }

   static void reset(int limit){
	for(int i=0;i< limit;i++){
         for(int j=0;j< limit;j++){
	   mesh[i][j][0]=mesh[i][j][1]=0d;
	  }
	}
    }

  static int parseInt(String s){
    int t = 0;
   for(char ch: s.toCharArray()){
      t *= 10;
     t += ch-'0';
  }
  return t;
 }
}
