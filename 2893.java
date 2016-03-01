import java.io.*;
import java.util.*;

public class Main {
 static final int M = 1000+2;
 static final int N = 1000000+10;
 static int sort[] = new int[N],map[][] = new int[M][M];
 public static void main(String []args) throws Exception{

  int i,j,n,m,top,a,b;
  int num[] = new int[N];

  StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
  while(true){
	n = Get_Num(cin);
	m = Get_Num(cin);
	if(n==0 && m==0) break;
	for(i=top=0;i< n;++i)
	  for(j=0;j< m;++j){
		map[i][j] = Get_Num(cin);
	  }
	if(m%2==1){
		for(i=0;i< n;++i)
		 for(j=0;j< m;++j) if(map[i][j]>0)
			num[top++] = map[i][j];
	}else{
		for(i=0;i< m;++i)
		  for(j=0;j< n;++j) if(map[j][i]>0)
			num[top++] = map[j][i];
	}
	a = merge(num,0,top-1);
	if(m%2==1){
		if(a%2==0) System.out.println("YES");
		else System.out.println("NO");
	}
	else{
		for(i=top=0;i< n;++i)
		  for(j=0;j< m;++j)
			map[i][j] = ++top;
		map[n-1][m-1] = 0;
		for(i=top=0;i< m;++i)
		 for(j=0;j< n;++j) if(map[j][i]>0)
			num[top++] = map[j][i];
		b = merge(num,0,top-1);
		if(a%2==b%2) System.out.println("YES");
		else System.out.println("NO");
	}
    }

  }

  public static int Get_Num(StreamTokenizer cin)throws Exception{
   cin.nextToken();
   return (int)cin.nval;
  }


  public static int merge(int num[],int left,int right){

	if(left==right){
		sort[left] = num[left];
		return 0;
	}
	int mid,i,j,ans=0,top=0;
	mid = (left+right)/2;
	ans = merge(num,left,mid)%2;
	ans += merge(num,mid+1,right)%2;

	i = left ; j = mid+1;
	while(i<=mid && j<=right){
		if(num[i]>num[j]){
			ans += (mid-i+1)%2;
			sort[top++] = num[j++];
		}
		else{
			sort[top++] = num[i++];
		}
	}
	while(i<=mid)
		sort[top++] = num[i++];
	while(j<=right)
		sort[top++] = num[j++];
	for(i=left;i<=right;++i)
		num[i] = sort[i-left];

	return ans;
  }
}

