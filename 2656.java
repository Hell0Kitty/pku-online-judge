import java.util.*;

 public class Main {

     public static void main(String[] args) {
         Scanner cin = new Scanner(System.in);

         int caseNum = 0;
         int unhappyDay, unhappyValue;
         int studyTime = 0;

         while(true)
         {
             unhappyDay = 0;
             unhappyValue = 0;
             caseNum = cin.nextInt();

             if(caseNum == 0)
                 break;
             else
             {
                 int[][] time = new int[caseNum][2];
                 for(int i = 0; i < caseNum; i++)
                 {
                     for(int j = 0; j < 2; j++)
                         time[i][j] = cin.nextInt();

                     studyTime = time[i][0] + time[i][1];
                     if(studyTime > 8)
                     {
                         if(studyTime > unhappyValue)
                         {
                             unhappyValue = studyTime;
                             unhappyDay = i + 1;
                         }
                     }

                 }
                 System.out.println(unhappyDay);
             }
         }
     }
}

