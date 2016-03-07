import java.util.*;   
  
public class Main {   
  
    public static void main(String[] args) {   
        Scanner cin = new Scanner(System.in);   
        String[] str;   
           
        int[][] target = new int[16][3];   
        int[] temp = new int[3];   
        int minIndex = 0;   
        double minValue = -1;   
        double tempValue = 0;   
           
        for(int i = 0; i < 16; i++)   
        {   
            str = cin.nextLine().split(" ");   
            target[i][0] = Integer.valueOf(str[0]).intValue();   
            target[i][1] = Integer.valueOf(str[1]).intValue();   
            target[i][2] = Integer.valueOf(str[2]).intValue();   
        }   
           
        while(cin.hasNext())   
        {   
            minIndex = 0;   
            minValue = -1;   
            tempValue = 0;   
            str = cin.nextLine().split(" ");   
            temp[0] = Integer.valueOf(str[0]).intValue();   
            temp[1] = Integer.valueOf(str[1]).intValue();   
            temp[2] = Integer.valueOf(str[2]).intValue();   
               
            if(temp[0]==-1 && temp[1]==-1 && temp[2]==-1)   
                break;   
               
            for(int i = 0; i < 16; i++)   
            {   
                tempValue = getEuclideanD(temp, target[i]);   
                if(tempValue == 0)   
                {   
                    minValue = tempValue;   
                    minIndex = i;   
                    break;   
                }   
                if(minValue == -1)   
                {   
                    minValue = tempValue;   
                    minIndex = 0;   
                    continue;   
                }   
                if(minValue > tempValue)   
                {   
                    minValue = tempValue;   
                    minIndex = i;   
                }   
            }   
               
            System.out.println(   
                    "("+temp[0]+","+temp[1]+","+temp[2]+   
                    ") maps to "+   
                    "("+target[minIndex][0]+","+   
                    target[minIndex][1]+","+   
                    target[minIndex][2]+")");   
        }   
    }   
       
    private static double getEuclideanD(int[] p1, int[] p2)   
    {   
        double value = 0;   
           
        value = Math.sqrt(Math.pow((p2[0]-p1[0]), 2) +   
                    Math.pow((p2[1]-p1[1]), 2) +    
                    Math.pow((p2[2]-p1[2]), 2));   
           
        return value;   
           
    }   
  
}