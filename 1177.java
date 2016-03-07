import java.io.*;  
  
public class Main{  
  
    static A4 p[];  
    static A5 ST[];  
      
    public static void main(String[] args) throws Exception{  
          
        BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));  
          
        int n = Integer.parseInt(buf.readLine());  
          
        p = new A4[2*n+1];  
        ST = new A5[40005];  
        int j = 0;  
        int min=10001,max=-10001;  
          
        for(int i=0;i<n;i++){  
            String str[] = buf.readLine().split(" ");  
            int x1 = Integer.parseInt(str[0]);  
            int y1 = Integer.parseInt(str[1]);  
            int x2 = Integer.parseInt(str[2]);  
            int y2 = Integer.parseInt(str[3]);  
            p[j++] = new A4(x1,y1,y2,1);  
            p[j++] = new A4(x2,y1,y2,-1);  
            min = Math.min(y1, min);  
            max = Math.max(y2, max);  
        }  
          
        java.util.Arrays.sort(p,0,j);  
        build(1,min,max);  
        cal(j);  
  
    }  
  
    public static void cal(int n) {  
          
        int sum = 0,t = 0;  
        p[n] = p[n-1];   // 最后一个没有 平行x轴的长度   
          
        for(int i=0;i<n;i++){  
            insert(1,p[i].y1,p[i].y2,p[i].s);  
            sum += ST[1].time*(p[i+1].x-p[i].x)*2;// 加上平行x轴的长度   
            sum += Math.abs(ST[1].len-t);   //减去被覆盖的长度   
            t = ST[1].len;   // t的值为   当前 被覆盖的 平行 y轴的长度   
        }  
          
        System.out.println(sum);  
          
    }  
  
    public static void insert(int k,int l, int r, int s) {  
          
        if(l<=ST[k].l&&r>=ST[k].r){  
            ST[k].count += s;  
            update(k);  
            return ;  
        }  
           
        int mid = (ST[k].l+ST[k].r)>>1;  
        if(l<mid)  
            insert(2*k,l,r,s);  
        if(r>mid)  
            insert(2*k+1,l,r,s);  
        update(k);  
          
    }  
  
    public static void update(int k) {  
          
        if(ST[k].count>0){  
            ST[k].len = ST[k].r-ST[k].l;  // 覆盖的线段长度   
            ST[k].lp=ST[k].rp=ST[k].time=1; // 因为完全覆盖了此区间，所以lp,rp,time = 1;   
        }else if(ST[k].r - ST[k].l == 1){   // 避免 越界     
            ST[k].len = ST[k].lp = ST[k].rp = ST[k].time = 0;  
        }else{  
            int l = 2*k;int r = 2*k+1;  
            ST[k].len = ST[l].len + ST[r].len; //总覆盖长度   
            ST[k].time = ST[l].time + ST[r].time - (ST[l].rp&ST[r].lp); //如果 左子树右端点被覆盖且右子树左端点也被覆盖刚此是连续的，所以减1   
            ST[k].lp = ST[l].lp;  
            ST[k].rp = ST[r].rp;  
        }  
          
    }  
  
    public static void build(int k, int s, int t) {  //建树   
          
        ST[k] = new A5(s,t,0,0,0,0,0);  
          
        if(t - s <= 1)  
            return ;  
          
        int mid = (s+t)>>1;  
        build(2*k,s,mid);  
        build(2*k+1,mid,t);  
          
    }  
  
}  
  
class A4 implements Comparable<A4>{  
    int x;  //扫描线 x 坐标   
    int y1;  
    int y2;  
    int s;  
    public A4(int x, int y1, int y2, int s) {  
        super();  
        this.x = x;  
        this.y1 = y1;  
        this.y2 = y2;  
        this.s = s;  
    }  
      
    public int compareTo(A4 e) {  
          
        if(this.x<e.x)  
            return -1;  
        else if(this.x>e.x)  
            return 1;  
        else{  
            if(this.s>e.s)  
                return -1;  
            else if(this.s<e.s)  
                return 1;  
            else  
                return 0;  
        }  
    }  
}  
class A5{  
    int l,r,count,len,lp,rp,time;  
  
    public A5(int l, int s, int count, int len, int lp, int rp, int time) {  
        super();  
        this.l = l;  
        this.r = s;  
        this.count = count;  
        this.len = len;  
        this.lp = lp;  
        this.rp = rp;  
        this.time = time;  
    }  
      
}  
