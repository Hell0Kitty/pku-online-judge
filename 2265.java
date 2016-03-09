    import java.util.Scanner;
    public class Main{
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            while(scan.hasNext()){
                int n = scan.nextInt();
                cal(n);
            }
        }

        public static void cal(int a) {

            if(a == 1){
                System.out.println(0+" "+0);
                return ;
            }

            int n = 0;
            while(3*(n-1)*n+1< a)      // 3*(n-1)*n+1 表示每层的最后一个数 是谁
                n++;
            n--;
            a -= 3*(n-1)*n+1;    // a现在表示的是a是所在层的第几个数
            int x , y;
            if(a<=n){ // 把每一层分为六边,因为本身就是一个正六边形，当在第n层时，每边是有n个点
                x = n-a;
                y = a;
            }else if(a>n&&a<=2*n){
                x = n-a;
                y = n;
            }else if(a>2*n&&a<=3*n){
                x = -n;
                y = 3*n-a;
            }else if(a>3*n&&a<=4*n){
                x = a-4*n;
                y = 3*n-a;
            }else if(a>4*n&&a<=5*n){
                x = a-4*n;
                y = -n;
            }else{
                x = n;
                y = a-6*n;
            }

            System.out.println(x+" "+y);

        }

    }

