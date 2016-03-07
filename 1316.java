public class Main{
	public static void main(String[] args){
		int[] n=new int[9999];
		for (int i=0;i<n.length ;i++ ){
			n[i]=getN(i+1);
		}
		intSort(n,0,n.length-1);
		System.out.println(1);
		for (int i=0;i<n.length-1 ;i++ ){
			if (n[i]+1>9993){
				break;
			}
			for (int j=n[i]+1;j<n[i+1] ;j++ ){
				System.out.println(j);
			}
		}
	}

	public static int getN(int n){
		int a=n/1000;
		int b=(n-1000*a)/100;
		int c=(n-1000*a-100*b)/10;
		int d=n-1000*a-100*b-10*c;
		return n+a+b+c+d;
	}

	public static void intSort(int[] number,int left,int right){
        if (left<right){
            int s=number[(left+right)/2];
            int i=left-1;
            int j=right+1;
            while (true){
                while (number[++i]<s);
                while (number[--j]>s);
                if (i>=j) break;
                swap(number,i,j);
            }
            intSort(number,left,i-1);
            intSort(number,j+1,right);
        }
    }

	public static void swap(int[] number,int i,int j) {
        int t;
        t=number[i];
        number[i]=number[j];
        number[j]=t;
    }
}