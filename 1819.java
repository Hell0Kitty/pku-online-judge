import java.io.BufferedReader;  
import java.io.InputStreamReader;  
  
public class Main{  
  
    static double r[],x[];  
    static int touch[];  
    static boolean flag[];  
      
    public static void main(String[] args) throws Exception{  
          
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));  
          
        int n = Integer.parseInt(buf.readLine());  
          
        r = new double[n];  
        x = new double[n];  
        touch = new int[n];  
        flag = new boolean[n];  
        double max = 0;  
        int tmax = 0;  
        java.util.Arrays.fill(touch, -1);  
          
        for(int i=0;i<n;i++){  
            r[i] = Double.parseDouble(buf.readLine());  
            x[i] = r[i];  
        }  
          
        for(int i=1;i<n;i++){  
            for(int j=0;j<i;j++){  
                if(x[j]+2*Math.sqrt(r[i]*r[j])-x[i]>1e-10){// 2*Math.sqrt(r[i]*r[j])是i,j圆心的水平距离 即x坐标差值   
                    x[i] = x[j]+2*Math.sqrt(r[i]*r[j]);  
                    touch[i] = j;  
                }  
            }  
              
            if(x[i]+r[i]-max>1e-10){  
                max = x[i]+r[i];  
                tmax = i;  
            }  
        }  
        int sum = 0;  
        for(int i=1;i<n;i++){  
            for(int j=touch[i]+1;j<i;j++)  
                if(!flag[j]){  
                    flag[j] = true;  
                    sum ++;  
                }  
        }  
          
        for(int i=tmax+1;i<n;i++)  
            if(!flag[i]){  
                flag[i] = true;  
                sum ++;  
            }  
          
        System.out.println(sum);  
        for(int i=0;i<n;i++)  
            if(flag[i])  
                System.out.println(i+1);  
  
    }  
  
}  
