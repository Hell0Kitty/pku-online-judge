import java.util.Scanner;

    public class Main{

        static int mod[][];
        static int k;
        static int flag[][];
        static int m[],n[];
        static int n_mod;
        static int len;

        public static void main(String[] args) {

            Scanner scan = new Scanner(System.in);

            while(scan.hasNext()){
                char s[] = scan.next().toCharArray();
                k = scan.nextInt();

                len = s.length;
                mod = new int[len][10];
                flag = new int[len][k];
                m = new int[len];
                n = new int[len];
                n_mod = 0;

                playTable(len);

                for(int i=0;i< len;i++){
                    m[i] = n[i] = s[len-i-1]-'0';
                    n_mod = (n_mod+mod[i][n[i]])%k;
                }

                int i;
                for(i=1;i<=len;i++)          // 修改的长度
                    if(dfs(len-1,i,n_mod))
                        break;

                for(i=len-1;i>=0;i--)
                    System.out.print(""+m[i]);
                System.out.println();

            }
        }

        public static boolean dfs(int pos, int clen, int m_mod) {

            if(m_mod == 0)
                return true;
            if(pos< 0||clen==0)
                return false;

            if(clen<=flag[pos][m_mod])          //剪枝
                return false;

            for(int i=pos;i>=0;i--){
                for(int j=0;j< n[i];j++){
                    if(i==len-1&&j==0)
                        continue;
                    int res = (m_mod-mod[i][m[i]]+mod[i][j]+k)%k;  // 同余模
                    int temp = m[i];
                    m[i] = j;

                    if(dfs(i-1,clen-1,res)){
                        return true;
                    }
                    m[i] = temp;
                }
            }
            for(int i=0;i<=pos;i++){
                for(int j=n[i]+1;j<=9;j++){
                    int res = (m_mod-mod[i][m[i]]+mod[i][j]+k)%k;
                    int temp = m[i];
                    m[i] = j;
                    if(dfs(i-1,clen-1,res))
                        return true;
                    m[i] = temp;
                }
            }
            flag[pos][m_mod] = clen;              // 剪枝

            return false;
        }

        public static void playTable(int len) {

            for(int i=0;i< 10;i++)
                mod[0][i] = i%k;
            for(int i=1;i< len;i++){
                for(int j=0;j< 10;j++)
                    mod[i][j] = (mod[i-1][j]*10)%k;
            }

        }

    }
