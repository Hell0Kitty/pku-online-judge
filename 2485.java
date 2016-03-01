import java.util.Scanner;
public class Main{
        public static void main(String argvs[]){
                int matrix[][];
                int Max=65536;
                int m,n,t,i,j,k,max_len,count,num,min,point=0;
                int temp1[],temp2[],flag[];
                Scanner in=new Scanner(System.in);
                t=in.nextInt();
                for(i=0;i< t;i++){
                    n=in.nextInt();
                    matrix=new int[n][n];
                    flag=new int[n];
                    for(j=0;j< n;j++)
                        flag[j]=0;
                    flag[0]=1;
                    count=0;
                    num=0;
                    min=Max;
                    max_len=0;
                    temp1=new int[n*(n-1)/2];
                    temp2=new int[n*(n-1)/2];
                    for(j=0;j< n;j++)
                        for(k=0;k< n;k++)
                            matrix[j][k]=in.nextInt();
                    for(j=1;j< n;j++){
                        temp1[num]=matrix[0][j];
                        temp2[num]=j;
                        num++;
                    }
                    while(count!=n-1){
                       for(j=0;j< num;j++)
                           if(min>temp1[j]&&flag[temp2[j]]==0){
                               min=temp1[j];
                               point=j;
                           }
                       if(min>max_len) max_len=min;
                       flag[temp2[point]]=1;
                       for(j=0;j< n;j++)
                           if(j!=temp2[point]&&flag[j]==0){
                                temp1[num]=matrix[temp2[point]][j];
                                temp2[num]=j;
                                num++;
                           }
                       min=Max;
                       count++;
                    }
                    System.out.println(max_len);
                }
        }
}

