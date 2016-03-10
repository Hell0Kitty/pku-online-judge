import java.io.BufferedInputStream;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *Poj3750 easy 约瑟夫循环
 * @author NC
 */
public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        //用nextInt的话，与下文的nextLine会有点冲突，会报异常，还是统一用一个方法就好
        int n = Integer.parseInt(scanner.nextLine());
        LinkedList queue = new LinkedList();
        for (int i = 0; i < n; i++) {
            String name = scanner.nextLine();
            queue.add(name.trim());
        }
        String ws = scanner.nextLine();
        String[] wss = ws.split(",");
        int w = Integer.parseInt(wss[0]);
        int s = Integer.parseInt(wss[1]);
        int count = 0;
//找出第w个人，从第w个人开始报数
        while (true) {
            count++;
            if (count == n + 1) {
                count = 1;
            }
            if (count == w) {
                break;
            }
            String person = queue.removeFirst();
            queue.add(person);

        }
//从第w个开始报数，报到s的出队
        count = 0;
        while (true) {
            //从1开始报数
            count++;
            if (count == n + 1) {
                count = 1;
            }
            if (queue.isEmpty()) {
                break;
            }
            //出来一个人报数
            String person = queue.removeFirst();
            if (count == s) {
                System.out.println(person);
                count = 0;//出完队后，重新报数
            } else {
                queue.add(person);
            }

        }
    }
}
