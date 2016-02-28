import java.util.*;
public   class Main{    
   
    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);

       int a1=sc.nextInt();
       int a2=sc.nextInt();
       int a3=sc.nextInt();
       int a4=sc.nextInt();
       int a5=sc.nextInt();
      System.out.println( hashQuestions(a1,a2, a3,a4,a5));
  }
   
 
   /**  
    * @param a1  
    * @param a2  
    * @param a3  
    * @param a4  
    * @param a5  
    */  
   public static  int  hashQuestions(int a1, int a2, int a3, int a4, int a5){   
       
    char hash[] = new char[25000010];   //hash存储   
       
    int bigsqure[] = new int[100];           //存立方数字的   
    int pos = 0;   
    int m = 0;            
    for (int x = -50; x <= 50; x++) {   
        if(x == 0) continue;         //为了删除掉0 不然会多出来200个解   
        bigsqure[m++] = x*x*x;       //把这个立方值存起来，以后好用。   
    }   
       
    //算出左边值   
    for (int i = 0; i < 100; i++) {   
        for (int j = 0; j < 100; j++) {   
            pos = -(bigsqure[i]*a1 + bigsqure[j]*a2);      
                
            hash[pos+12500000]++;          //这个值为1了!   
               
            //这块算结束之后 在hash的这个大数组里边 凡是有左边结果的元素  值都为1了。   
        }   
    }   
       
    int answer = 0;   
    //算右边值   
    for (int i = 0; i < 100; i++) {   
        for (int j = 0; j < 100; j++) {   
            for (int k = 0; k < 100; k++) {   
                pos = bigsqure[i]*a3 + bigsqure[j]*a4 + bigsqure[k]*a5;   
                if(pos > 12500000 || pos < -12500000)    
                    continue;   
                answer += hash[pos+12500000];   
                   
                //这个相加的道理即是，如果右边的值没有和左边重叠 那么这个值是0。   
                //如果重叠了，在左边的时候， 已经把他设为1了，那么 把所有的重叠的“1”累加起来   
                //即是结果。   
            }   
        }   
    }   
        
  return answer;
 }  
}