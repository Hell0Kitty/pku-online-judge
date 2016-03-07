import java.util.*;   
    
public class Main{   
    public static void main(String[] args){   
        int l[]=new int[10000];   
        int w[]=new int[10000];   
        int tt[]=new int[5000];   
        int k=0;   
        Scanner keyin=new Scanner(System.in);   
        int m=keyin.nextInt();   
        int mm=m;   
        int n=0;   
        for(;m>0;m--){   
            n=keyin.nextInt();   
            for(int j=0;j<n;j++){   
                l[j]=keyin.nextInt();   
                w[j]=keyin.nextInt();   
            }   
  
            int time=0,c=0;   
            for(int t=0;t<=n-2;t++){   
                for(int s=n-2;s>=t;s--){   
                    if(l[s]>l[s+1]){   
                        int temp=l[s];   
                        l[s]=l[s+1];   
                        l[s+1]=temp;   
                        temp=w[s];   
                        w[s]=w[s+1];   
                        w[s+1]=temp;   
                    }   
                }   
            }   
  
            for(int p=0;p<n;p++){   
                if(w[p]!=-1){   
                    time++;   
                    c=w[p];   
                    for(int q=p+1;q<n;q++){   
                        if(w[q]>=c){   
                            c=w[q];   
                            w[q]=-1;   
                        }   
                    }   
                }   
            }   
            tt[k++]=time;   
        }   
        for(int r=0;r<mm;r++)   
            System.out.println(tt[r]);   
    }   
}  