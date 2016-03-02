    import java.io.*;
    import java.util.HashMap;

    public class Main{

        public static final int MAX = 310;
        static int equ,var;
        static int a[][];
        static int x[];
        static HashMap< String,Integer> hash = new HashMap< String,Integer>();

        public static void main(String[] args) throws Exception{
            hash.put("MON",0);hash.put("TUE",1);hash.put("WED",2);hash.put("THU",3);
			hash.put("FRI",4);hash.put("SAT",5);hash.put("SUN", 6);
            BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));

            while(true){
                String str[] = buf.readLine().split(" ");
                var = Integer.parseInt(str[0]);
                equ = Integer.parseInt(str[1]);
                if(var==0&&equ==0)
                    break;

                a = new int[MAX][MAX];
                x = new int[MAX];

                for(int i=0;i< equ;i++){
                    str = buf.readLine().split(" ");
                    int k = Integer.parseInt(str[0]);
                    a[i][var] = ((hash.get(str[2])-hash.get(str[1])+1)%7+7)%7;

                    str = buf.readLine().split(" ");
                    for(int j=0;j< k;j++){
                        int t = Integer.parseInt(str[j])-1;
                        a[i][t]++;
                        a[i][t] %= 7;
                    }
                }

                int res = guass();

                if(res == 0){
                    for(int i=0;i< var;i++)
                        if(x[i]< 3)
                            x[i] += 7;
                    for(int i=0;i< var-1;i++)
                        System.out.print(x[i]+" ");
                    System.out.print(x[var-1]);
                    System.out.println();
                }else if(res == -1)
                    System.out.println("Inconsistent data.");
                else
                    System.out.println("Multiple solutions.");

            }

        }

        public static int guass() {

            int row , col;
            row = col = 0;

            while(row< equ&&col< var){
                int mr = row;
           for(int i=row+1;i< equ;i++){//保证从上到下 每个式子都保留着 0...var 的变量
                    if(Math.abs(a[i][col])>Math.abs(a[mr][col]))
                        mr = i;
                }

                if(mr != row)
                    for(int i=col;i<=var;i++){
                        int tmp = a[row][i];
                        a[row][i] = a[mr][i];
                        a[mr][i] = tmp;
                    }

                if(a[row][col]==0){
                    col++;
                    continue;
                }

        for(int i=row+1;i< equ;i++){//以第row个式子为基础化简其余剩下的式子（为了消去第col个变量)
                    if(a[i][col]!=0){
                        int L = lcm(Math.abs(a[i][col]),Math.abs(a[row][col]));
                        int ta = L/Math.abs(a[i][col]); int tb = L/Math.abs(a[row][col]);
                        if(a[i][col]*a[row][col]< 0)   //考虑异号的情况
                            tb = -tb;
                        for(int j=col;j<=var;j++)
                            a[i][j] = ((a[i][j]*ta-a[row][j]*tb)%7+7)%7;
                    }
                }
                row++;
                col++;
            }
      //求解 var个未知数 只需要var个式子 如果有多余的式子(经化简后） 必全部为0否则无解
            for(int i=row;i< equ;i++)
                if(a[i][var]!=0)
                    return -1;
// 判断是否有变量没有在所有式子中出现或着当row指到最后一个式子时  即总式子量< 总未知数量
            if(var>row)
                return var-row;  // row 即为  所有式子中 所有的变量总数

            for(int i=var-1;i>=0;i--){
                int tmp = a[i][var];
                for(int j=i+1;j< var;j++)
                    tmp = ((tmp-a[i][j]*x[j])%7+7)%7;
                while(tmp%a[i][i]!=0)
                    tmp += 7;
                x[i] = (tmp/a[i][i])%7;
            }

            return 0;
        }

        public static int lcm(int a, int b) {

            return a*b/gcd(a,b);
        }

        public static int gcd(int a, int b) {

            return b==0?a:gcd(b,a%b);
        }
    }

