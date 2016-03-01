import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);

        String[] fLine = cin.nextLine().split(" ");
        int kwNum = Integer.valueOf(fLine[0]).intValue();
        int descNum = Integer.valueOf(fLine[1]).intValue();

        HashMap hm = new HashMap();

        for(int i = 0; i < kwNum; i++)
        {
            String[] str = cin.nextLine().split(" ");
            hm.put(str[0], str[1]);
        }

        for(int i = 0; i < descNum; i++)
        {
            StringBuffer sb = new StringBuffer();
            String job = null;
            int salary = 0;

            while(true)
            {
                job = cin.nextLine();
                if(job.equals("."))
                    break;
                else
                    sb.append(job + " ");
            }
            job = sb.toString().trim();

            if(job.length() == 0)
            {
                System.out.println("0");
                continue;
            }
            int eIndex = 0;
            String word = null;
            while(true)
            {
                eIndex = job.indexOf(" ");
                if(eIndex == -1 || eIndex == 0)
                {
                    if(hm.containsKey(job))
                        salary += Integer.valueOf((String)hm.get(job));
                    break;
                }
                word = job.substring(0, eIndex);
                job = job.substring(eIndex + 1).trim();

                if(hm.containsKey(word))
                    salary += Integer.valueOf((String)hm.get(word));
            }
            System.out.println(salary);
        }

    }

}

