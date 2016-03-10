import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            double temperature = 0, dewpoint = 0, humidex = 0;
            String[] ss = scan.nextLine().split(" ");
            String sa = ss[0];
            if (sa.equals("E")) {
                break;
            }
            double a = Double.parseDouble(ss[1]);
            String sb = ss[2];
            double b = Double.parseDouble(ss[3]);
            if (sa.equals("T") && sb.equals("D")) {
                temperature = a;
                dewpoint = b;
                double e = 6.11 * Math.pow(2.718281828, 5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
                double h = (0.5555) * (e - 10.0);
                humidex = temperature + h;
            }
            if (sa.equals("D") && sb.equals("T")) {
                temperature = b;
                dewpoint = a;
                double e = 6.11 * Math.pow(2.718281828, 5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
                double h = (0.5555) * (e - 10.0);
                humidex = temperature + h;
            }
            if (sa.equals("D") && sb.equals("H")) {
                dewpoint = a;
                humidex = b;
                double e = 6.11 * Math.pow(2.718281828, 5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
                double h = (0.5555) * (e - 10.0);
                temperature = humidex - h;
            }
            if (sa.equals("H") && sb.equals("D")) {
                dewpoint = b;
                humidex = a;
                double e = 6.11 * Math.pow(2.718281828, 5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
                double h = (0.5555) * (e - 10.0);
                temperature = humidex - h;
            }
            if (sa.equals("T") && sb.equals("H")) {
                temperature = a;
                humidex = b;
                double h = humidex - temperature;
                double e = h / 0.5555 + 10.0;
                dewpoint = 1 / ((1 / 273.16) - Math.log(e / 6.11) / 5417.7530) - 273.16;
            }
            if (sa.equals("H") && sb.equals("T")) {
                temperature = b;
                humidex = a;
                double h = humidex - temperature;
                double e = h / 0.5555 + 10.0;
                dewpoint = 1 / ((1 / 273.16) - Math.log(e / 6.11) / 5417.7530) - 273.16;
            }
            System.out.print("T ");
            System.out.printf("%.1f", temperature);
            System.out.print(" D ");
            System.out.printf("%.1f", dewpoint);
            System.out.print(" H ");
            System.out.printf("%.1f", humidex);
            System.out.println();
        }
    }
}
