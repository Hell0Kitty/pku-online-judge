    import java.util.Scanner;  
      
    public class Main{  
      
          
        public static void main(String[] args) {  
              
            Scanner scan = new Scanner(System.in);  
              
            while(true){  
                int a = scan.nextInt();  
                int b = scan.nextInt();  
                if(a==0&&b==0)  
                    break;  
                A3 p = new A3(0,0);  
                p = cal(a);  
                A3 p1 = new A3(p.x,p.y);  
                p = cal(b);  
                A3 p2 = new A3(p.x,p.y);  
                int x = p1.x-p2.x;  
                int y = p1.y-p2.y;  
                int ans;  
                if(x*y<=0)  
                    ans = Math.max(Math.abs(x), Math.abs(y));  
                else  
                    ans = Math.abs(x+y);  
                System.out.printf("The distance between cells %d and %d is %d.",a,b,ans);  
                System.out.println();  
            }  
      
        }  
      
        public static A3 cal(int a) {  
            if(a == 1){  
                return new A3(0,0);  
            }  
            int x;  
            int y;  
            int n = 0;  
            while(3*(n-1)*n+1<a)     // 3*(n-1)*n+1  为第n圈最后一个数  
                n++;  
            n--;  
            a -= 3*(n-1)*n+1;  
              
            if(a<=n){               // 详细注释见我的   poj 2265  
                x = n;  
                y = -a;  
            }else if(a>n&&a<=2*n){  
                x = 2*n-a;  
                y = -n;  
            }else if(a>2*n&&a<=3*n){  
                x = 2*n-a;  
                y = -n-x;  
            }else if(a>3*n&&a<=4*n){  
                x = -n;  
                y = a-3*n;  
            }else if(a>4*n&&a<=5*n){  
                x = a-5*n;  
                y = n;  
            }else{  
                x = a-5*n;  
                y = n-x;  
            }  
            A3 p = new A3(x,y);  
            return p;  
        }  
      
    }  
      
    class A3{  
        int x;  
        int y;  
        public A3(int x, int y) {  
            super();  
            this.x = x;  
            this.y = y;  
        }  
          
    }  