import java.util.Scanner;

 enum Direction {
     N, S, W, E
 }

 class Robot {
     int id;
     int x;
     int y;
     Direction direction;

     public Robot(int i, int x, int y, String direction) {
         this.id = i;
         this.x = x;
         this.y = y;
         if (direction.equalsIgnoreCase("N"))
             this.direction = Direction.N;
         else if (direction.equalsIgnoreCase("S"))
             this.direction = Direction.S;
         else if (direction.equalsIgnoreCase("W"))
             this.direction = Direction.W;
         else if (direction.equalsIgnoreCase("E"))
             this.direction = Direction.E;
     }

     public void move(String command) {
         if (command.equalsIgnoreCase("F")) {
            switch (this.direction) {
            case N:
                 this.y++;
                 break;
             case S:
                 this.y--;
                 break;
             case W:
                 this.x--;
                 break;
             case E:
                 this.x++;
                 break;
             }
         } else {
             this.rotate(command);
         }
     }

     public void rotate(String s) {
         if (s.equalsIgnoreCase("L")) {
             switch (this.direction) {
             case N:
                 this.direction = Direction.W;
                 break;
             case S:
                 this.direction = Direction.E;
                 break;
             case W:
                 this.direction = Direction.S;
                 break;
             case E:
                 this.direction = Direction.N;
                 break;
             }
         } else {
             switch (this.direction) {
             case N:
                 this.direction = Direction.E;
                 break;
             case S:
                 this.direction = Direction.W;
                 break;
             case W:
                 this.direction = Direction.N;
                 break;
             case E:
                 this.direction = Direction.S;
                 break;
             }
         }
     }
 }

public class Main {

     public static String collision(Robot[] robots, Robot r, int x_dim, int y_dim) {
        int num = robots.length;
         if (r.x <= 0 || r.x > x_dim || r.y <= 0 || r.y > y_dim) {
             return "Robot " + r.id + " crashes into the wall";
         }
         for (int i = 0; i < num; i++) {
             if (r.x == robots[i].x && r.y == robots[i].y
                     && r.id != robots[i].id) {
                 return "Robot " + r.id + " crashes into " + "robot "
                         + robots[i].id;
             }
         }
         return "OK";
     }

     public static void main(String[] args) {

         Scanner in = new Scanner(System.in);
         int rounds = in.nextInt();
         for (int i = 0; i < rounds; i++) {
             int x_dimension = in.nextInt();
             int y_dimension = in.nextInt();
             int num_robots = in.nextInt();
             String response = "OK", temp;
             Robot robots[] = new Robot[num_robots];
             int num_ins = in.nextInt();
             for (int j = 1; j < num_robots + 1; j++) {
                 robots[j - 1] = new Robot(j, in.nextInt(), in.nextInt(), in
                         .next());
             }
             for (int k = 0; k < num_ins; k++) {
                 int r_id = in.nextInt();
                 String command = in.next();
                 int num_iteration = in.nextInt();
                 Robot robot = robots[r_id - 1];
                 for (int m = 0; m < num_iteration; m++) {
                     robot.move(command);
                     temp = collision(robots, robot, x_dimension, y_dimension);
                     if (response.startsWith("O") && !temp.startsWith("O"))
                         response = temp;
                 }
             }
             System.out.println(response);
         }
     }

 }


