import java.io.*;

public class Main{

    static int A[],B[],H[];
    static int S[];
    static A8 ST[];
    static int x;

    public static void main(String[] args) throws Exception{

        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(buf.readLine());

        A = new int[n];
        B = new int[n];
        H = new int[n];
        ST = new A8[8*n+1];

        int j = 0;
        int t[] = new int[2*n];
        S = new int[2*n];

        for(int i=0;i< n;i++){
            String str[] = buf.readLine().split(" ");
            A[i] = Integer.parseInt(str[0]);
            B[i] = Integer.parseInt(str[1]);
            H[i] = Integer.parseInt(str[2]);
            t[j++] = A[i];
            t[j++] = B[i];
        }

        java.util.Arrays.sort(t);
        S[0] = t[0];
        int num = 1;
        for(int i=1;i< j;i++){
            if(t[i-1]!=t[i])
                S[num++] = t[i];
        }
        t = null;
        build(1,0,num-1);

        for(x=0;x< n;x++)
            insert(1,A[x],B[x]);

        System.out.println(Count(1,0));

    }

    public static long Count(int p,int h){
         if(h>ST[p].h)
             ST[p].h=h;
         if(ST[p].r-ST[p].l==1)
             return (long)(S[ST[p].r]-S[ST[p].l])*ST[p].h;
         return Count(2*p,ST[p].h)+Count(2*p+1,ST[p].h);
    }

    public static void insert(int k, int l, int r) {

        if(l<=S[ST[k].l]&&r>=S[ST[k].r]){
            if(ST[k].h< H[x])
                ST[k].h = H[x];
            return ;
        }
        int mid = S[(ST[k].l+ST[k].r)>>1];
        if(l< mid)
            insert(2*k,l,r);
        if(r>mid)
            insert(2*k+1,l,r);

    }

    public static void build(int k, int l, int r) {

        ST[k] = new A8(l,r,0);

        if(r-l==1)
            return ;
        int mid = (l+r)>>1;
        build(2*k,l,mid);
        build(2*k+1,mid,r);

    }

}
class A8{
    int l;
    int r;
    int h;
    public A8(int l, int r, int h) {
        super();
        this.l = l;
        this.r = r;
        this.h = h;
    }

}

