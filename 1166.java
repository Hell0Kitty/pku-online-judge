import java.util.Scanner;
public class Main{
 public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
	int arr[]=new int[9];
        int ans[]=new int[9];
        int i=0;
	for(i=0;i<9;i++)
		arr[i]=sc.nextInt();
	int a1,a2,a3,a4,a5,a6,a7,a8,a9,cnt;
	int u[]=new int[9];
	int min=100;
	for(a1=0;a1<4;a1++)
		for(a2=0;a2<4;a2++)
			for(a3=0;a3<4;a3++)
				for(a4=0;a4<4;a4++)
					for(a5=0;a5<4;a5++)
						for(a6=0;a6<4;a6++)
							for(a7=0;a7<4;a7++)
								for(a8=0;a8<4;a8++)
									for(a9=0;a9<4;a9++)
									{
										cnt=a1+a2+a3+a4+a5+a6+a7+a8+a9;

										u[0]=arr[0]+a1+a2+a4;
										u[1]=arr[1]+a1+a2+a3+a5;
										u[2]=arr[2]+a2+a3+a6;
										u[3]=arr[3]+a1+a4+a5+a7;
										u[4]=arr[4]+a1+a3+a5+a7+a9;
										u[5]=arr[5]+a3+a5+a6+a9;
										u[6]=arr[6]+a4+a7+a8;
										u[7]=arr[7]+a5+a7+a8+a9;
										u[8]=arr[8]+a6+a8+a9;
										for(i=0;i<9;i++)
											if(u[i]%4!=0)break;
										if(i==9&&cnt<min)
										{
											ans[0]=a1;
											ans[1]=a2;
											ans[2]=a3;
											ans[3]=a4;
											ans[4]=a5;
											ans[5]=a6;
											ans[6]=a7;
											ans[7]=a8;
											ans[8]=a9;
											min=cnt;
										}
									}
	boolean bb=false;
	for(i=0;i<9;i++)
	{
		if(ans[i]==0)continue;
		for(int j=0;j<ans[i];j++)
		{
		if(bb) System.out.printf(" ");
		bb=true;
			System.out.printf("%d",i+1);
		}
	}
    }
}