import java.util.Scanner;
public class Main{
     public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext()){
           double wellHeight=cin.nextDouble();
           double dayFeet=cin.nextDouble();
           double nightFeet=cin.nextDouble();
           double fatigue=cin.nextDouble();
           if(wellHeight==0)return;
           double height=0;
           int days;
           double temp=0;
           for(days=0;height>=0;days++){
               temp=dayFeet-dayFeet*(fatigue*0.01)*days;
               if(temp<0)temp=0;
               height=height+temp;
               if(wellHeight<height){
                   break;
               }
               height=height-nightFeet;
            }
            System.out.println(height<0 ? "failure on day "+days : "success on day "+(days+1));
        }
    }
}