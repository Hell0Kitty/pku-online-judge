//* @author:
import java.util.Scanner;
import java.util.Stack;

public class Main {
 public static void main(String[] args) {
  new Main().init();
 }

 public void init() {
  Scanner sc = new Scanner(System.in);
  char[] s;
  boolean flag;
  while (!sc.hasNextInt()) {
    flag = true;
    s = sc.next().toCharArray();
    for (int i = 0; i < 32; i++) {
        if (!check(i, s)) {
            flag = false;
            break;
        }
    }
    if (flag)
        System.out.println("tautology");
    else
        System.out.println("not");
   }
 }

  public boolean check(int i, char[] s) {
   Stack< Integer> stack = new Stack< Integer>();
   for (char c : s) {
    if (c >= 'p' && c <= 't') {
        int d = c - 'p';
        d = (1 <<  d & i) >> d;
        boolean flag = true;
        while (flag) {
            if (stack.isEmpty()) {
                stack.push(d);
                flag = false;
            } else if (isoperate(stack.peek())) {
                stack.push(d);
                flag = false;
            } else if (stack.peek() == 'N') {
                d = 1 - d;
                stack.pop();
            } else {
                int dd = stack.pop();
                int oper = stack.pop();
                switch (oper) {
                case 'K':
                    d &= dd;
                    break;
                case 'A':
                    d |= dd;
                    break;
                case 'C':
                    d = dd - d > 0 ? 0 : 1;
                    break;
                case 'E':
                    d = 1 - (d ^ dd);
                    break;
                default:
                    break;
                }
            }
        }
    } else {
        stack.push((int) c);
    }
   }

   return stack.pop() == 1;
  }


  private boolean isoperate(Integer peek) {
    switch (peek.intValue()) {
    case 'K':
    case 'A':
    case 'C':
    case 'E':
        return true;
    default:
        return false;
    }
  }

}

