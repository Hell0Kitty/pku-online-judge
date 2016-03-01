import java.util.Scanner;
public class Main{
    Scanner scan=new Scanner(System.in);
    int n,k;
    int[] queue=new int[1000005];
    int[] Index=new int[1000005];
    int[] arr=new int[1000005];
    int[] MIN=new int[1000005];
    int[] MAX=new int[1000005];
    public static void main(String[] args){
        new Main().run();
    }
    void run(){
        n=scan.nextInt();
        k=scan.nextInt();
        if(k>n)
            k=n;
        for(int i=1;i<=n;i++)
        {
            arr[i]=scan.nextInt();
        }
        GetMin();
        GetMax();
        for(int i=0;i<=(n-k);i++)
        {
            System.out.print(MIN[i]+" ");
        }
        System.out.println();
        for(int i=0;i<=(n-k);i++)
        {
            System.out.print(MAX[i]+" ");
        }
    }

    void GetMin(){
        int head=1;
        int tail=0;
        for(int i=1;i< k;i++)
        {
            while(head<=tail&&queue[tail]>arr[i])
                tail--;
            tail++;
            queue[tail]=arr[i];
            Index[tail]=i;
        }
        for(int i=k;i<=n;i++)
        {
            while(head<=tail&&queue[tail]>arr[i])
                tail--;
            tail++;
            queue[tail]=arr[i];
            Index[tail]=i;
            while(Index[head]<=i-k)
                head++;
            MIN[i-k]=queue[head];
        }
    }

    void GetMax(){
        int head=1;
        int tail=0;
        for(int i=1;i< k;i++)
        {
            while(head<=tail&&queue[tail]< arr[i])
                tail--;
            tail++;
            queue[tail]=arr[i];
            Index[tail]=i;
        }
        for(int i=k;i<=n;i++)
        {
            while(head<=tail&&queue[tail]< arr[i])
                tail--;
            tail++;
            queue[tail]=arr[i];
            Index[tail]=i;
            while(Index[head]<=i-k)
                head++;
            MAX[i-k]=queue[head];
        }
    }
}



